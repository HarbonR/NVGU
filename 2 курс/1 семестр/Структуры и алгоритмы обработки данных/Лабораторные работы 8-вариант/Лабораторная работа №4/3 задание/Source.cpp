#include <iostream>
#include <string>
#include <conio.h>

class Queue
{
private:
	struct list_t
	{
		std::string data;
		list_t* previousElement = nullptr;
		list_t* nextElement = nullptr;
	};
	int counter = 0;
	list_t* pHead = nullptr;
	list_t* pTail = nullptr;
public:
	void addElement(std::string& data)
	{
		if (pHead == nullptr)
		{
			pHead = new list_t;
			pHead->data = data;
			pHead->previousElement = nullptr;
			pHead->nextElement = nullptr;
		}
		else if (pTail == nullptr)
		{
			pTail = new list_t;
			pTail->data = data;
			pTail->previousElement = pHead;
			pTail->nextElement = nullptr;
			pHead->nextElement = pTail;
		}
		else
		{
			pTail->nextElement = new list_t;
			pTail->nextElement->data = data;
			pTail->nextElement->previousElement = pTail;
			pTail->nextElement->nextElement = nullptr;
			pTail = pTail->nextElement;
		}
		counter++;
	}
	void print()
	{
		if (pHead != nullptr)
		{
			list_t* tmp = pHead;
			while (tmp != nullptr)
			{
				std::cout << tmp->data << '\n';
				tmp = tmp->nextElement;
			}
		}
		else
			std::cout << "Очередь пустая\n";
	}
	void search(std::string& data)
	{
		if (pHead != nullptr)
		{
			bool notSeatch = true;
			list_t* tmp = pHead;
			while (tmp != nullptr)
			{
				if (tmp->data == data)
				{
					std::cout << tmp->data << '\n';
					notSeatch = false;
				}
				tmp = tmp->nextElement;
			}
			if(notSeatch)
				std::cout << "Элемент не найден\n";
		}
		else
			std::cout << "Очередь пустая\n";
	}
	int getCounter()
	{
		return counter;
	}
	void deleteElement()
	{
		if (pHead != nullptr)
		{
			list_t* tmp = pHead;
			pHead = pHead->nextElement;
			delete tmp;
			std::cout << "Удалено\n";
			counter--;
		}
		else
			std::cout << "Очередь пустая\n";
	}
	void deleleteQueue()
	{
		if (pHead != nullptr)
		{
			while (pHead != nullptr)
			{
				list_t* tmp = pHead;
				pHead = pHead->nextElement;
				delete tmp;
				counter--;
			}
			std::cout << "Удалено\n";
		}
		else
			std::cout << "Очередь пустая\n";
	}
	~Queue()
	{
		if (pHead != nullptr)
			deleleteQueue();
	}
};

int main()
{
	system("chcp 1251");
	system("cls");
	Queue surnamesOfStudents;
	std::string data;
	char menu = '0';
	while (menu != '6')
	{
		std::cout << "1. Добавить элемент\n";
		std::cout << "2. Удалить элемент\n";
		std::cout << "3. Мощность множества\n";
		std::cout << "4. Просмотр всех элементов\n";
		std::cout << "5. Принадлежность элемента множеству\n";
		std::cout << "6. Выход\n";
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			std::getline(std::cin, data);
			surnamesOfStudents.addElement(data);
			system("cls");
			break;
		case '2':
			surnamesOfStudents.deleteElement();
			system("pause");
			system("cls");
			break;
		case '3':
			std::cout << "Количество элементов: " << surnamesOfStudents.getCounter() << '\n';
			system("pause");
			system("cls");
			break;
		case'4':
			surnamesOfStudents.print();
			system("pause");
			system("cls");
			break;
		case '5':
			std::getline(std::cin, data);
			surnamesOfStudents.search(data);
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}