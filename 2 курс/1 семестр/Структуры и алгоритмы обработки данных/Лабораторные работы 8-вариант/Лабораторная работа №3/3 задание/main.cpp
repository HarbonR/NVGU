#include <iostream>
#include<string>
#include<conio.h>

class Stack
{
private:
	typedef struct list_t
	{
		std::string data;
		list_t* nextElement;
	}list_t;
	list_t *pHead = nullptr;
	list_t *pVariable = nullptr;
public:
	void addElement(std::string &data)
	{
		if (pHead == nullptr)
		{
			pHead = new list_t;
			pHead->data = data;
			pHead->nextElement = nullptr;
		}
		else
		{
			pVariable = new list_t;
			pVariable->data = data;
			pVariable->nextElement = pHead;
			pHead = pVariable;
			pVariable = nullptr;
		}
	}
	void printElement()
	{
		if (pHead != nullptr)
		{
			std::cout << pHead->data << '\n';
		}
		else
			std::cout << "���� ����" << '\n';
	}
	void printStack()
	{
		if (pHead != nullptr)
		{
			pVariable = pHead;
			while (pVariable != nullptr)
			{
				std::cout << pVariable->data << '\n';
				pVariable = pVariable->nextElement;
			}
		}
		else
			std::cout << "���� ����" << '\n';
	}
	void deleteElement()
	{
		if (pHead != nullptr)
		{
			pVariable = pHead;
			pHead = pHead->nextElement;
			delete pVariable;
			pVariable = nullptr;
			std::cout << "������� �����" << '\n';
		}
		else
			std::cout << "���� ����" << '\n';
	}
	void deleteStack()
	{
		if (pHead != nullptr)
		{
			while (pHead != nullptr)
			{
				pVariable = pHead;
				pHead = pHead->nextElement;
				delete pVariable;
			}
			pVariable = nullptr;
			std::cout << "���� �����" << '\n';
		}
		else
			std::cout << "���� ����" << '\n';
	}
	~Stack()
	{
		if (pHead != nullptr)
			deleteStack();
	}
};

int main()
{
	system("chcp 1251");
	system("cls");
	Stack stackOne;
	char menu = '0';
	std::string data;
	char ddd[30];
	while (menu != '6')
	{
		std::cout << "1. �������� �������" << '\n';
		std::cout << "2. ������� �������" << '\n';
		std::cout << "3. ������� ����" << '\n';
		std::cout << "4. �������� �������" << '\n';
		std::cout << "5. �������� ����" << '\n';
		std::cout << "6. �����" << '\n';
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			std::getline(std::cin, data);
			stackOne.addElement(data);
			system("cls");
			break;
		case '2':
			stackOne.deleteElement();
			system("pause");
			system("cls");
			break;
		case '3':
			stackOne.deleteStack();
			system("pause");
			system("cls");
			break;
		case '4':
			stackOne.printElement();
			system("pause");
			system("cls");
			break;
		case '5':
			stackOne.printStack();
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}