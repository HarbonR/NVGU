#include <iostream>
#include <conio.h>

class Queue
{
private:
	typedef struct list_t
	{
		int data;
		list_t* nextElement;
	};
	list_t* pHead;
	list_t* pTail;
public:
	void addElement(int &data)
	{
		if (pHead == nullptr)
		{
			pHead = new list_t;
			pHead->data = data;
			pHead->nextElement = nullptr;
		}
		else if (pHead->nextElement == nullptr)
		{
			pTail = new list_t;
			pTail->data = data;
			pTail->nextElement = nullptr;
			pHead->nextElement = pTail;
		}
		else
		{
			pTail->nextElement = new list_t;
			pTail->nextElement->data = data;
			pTail->nextElement->nextElement = nullptr;
			pTail = pTail->nextElement;
		}
	}
	void printElement()
	{
		if (pHead != nullptr)
		{
			std::cout << pHead->data << '\n';
		}
		else
			std::cout << "������� �����" << '\n';
	}
	void printQueue()
	{
		if (pHead != nullptr)
		{
			list_t* pVariable = pHead;
			while (pVariable != nullptr)
			{
				std::cout << pVariable->data << '\n';
				pVariable = pVariable->nextElement;
			}
		}
		else
			std::cout << "������� �����" << '\n';
	}
	void deleteElement()
	{
		if (pHead != nullptr)
		{
			list_t* pVariable;
			pVariable = pHead;
			pHead = pHead->nextElement;
			delete pVariable;
			std::cout << "������� �����" << '\n';
		}
		else
			std::cout << "������� �����" << '\n';
	}
	void deleteQueue()
	{
		if (pHead != nullptr)
		{
			list_t* pVariable;
			while (pHead != nullptr)
			{
				pVariable = pHead;
				pHead = pHead->nextElement;
				delete pVariable;
			}
			std::cout << "������� �������" << '\n';
		}
		else
			std::cout << "������� �����" << '\n';
	}
	~Queue()
	{
		if (pHead != nullptr)
			deleteQueue();
	}
};

int main()
{
	system("chcp 1251");
	system("cls");
	Queue queueOne;
	char menu = '0';
	int data;
	while (menu != '6')
	{
		std::cout << "1. �������� �������" << '\n';
		std::cout << "2. ������� �������" << '\n';
		std::cout << "3. ������� �������" << '\n';
		std::cout << "4. �������� �������" << '\n';
		std::cout << "5. �������� �������" << '\n';
		std::cout << "6. �����" << '\n';
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			std::cin >> data;
			queueOne.addElement(data);
			system("cls");
			break;
		case '2':
			queueOne.deleteElement();
			system("pause");
			system("cls");
			break;
		case '3':
			queueOne.deleteQueue();
			system("pause");
			system("cls");
			break;
		case '4':
			queueOne.printElement();
			system("pause");
			system("cls");
			break;
		case '5':
			queueOne.printQueue();
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}