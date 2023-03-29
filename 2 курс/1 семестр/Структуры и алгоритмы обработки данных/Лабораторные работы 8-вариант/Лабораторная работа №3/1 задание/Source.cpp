#include <iostream>
#include <string>
#include <conio.h>

class List
{
public:
	struct data
	{
		std::string Surname;
		std::string faculty;
		std::string course;
		std::string group;
	};
private:
	struct list_t
	{
		data data;
		list_t* nextElement = nullptr;
	};
	list_t* pHead;
	list_t* pTail;
	void printElement(list_t* list)
	{
		std::cout << "�������: " << list->data.Surname << '\n';
		std::cout << "���������: " << list->data.faculty << '\n';
		std::cout << "����: " << list->data.course << '\n';
		std::cout << "������: " << list->data.group << '\n';
		std::cout << "==============================\n";
	}
public:
	void addElement(data& data)
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
	void deleteElement()
	{
		if (pHead != nullptr)
		{
			list_t* pTmpHead = pHead;
			list_t* pTmpTail = pTail;
			list_t* pVariable = pHead;
			bool notSearch = true;
			std::string search;
			std::cout << "�������: ";
			std::getline(std::cin, search);
			while (pVariable != nullptr)
			{
				if (pVariable->data.Surname == search)
				{
					if (pVariable == pHead)
					{
						pHead = pHead->nextElement;
						delete pVariable;
						pVariable = pHead;
					}
					else if (pVariable == pTail)
					{
						pTmpHead->nextElement = nullptr;
						delete pVariable;
						pVariable = nullptr;
					}
					else
					{
						pTmpHead->nextElement = pTmpTail;
						delete pVariable;
						pVariable = pTmpHead;
					}
					notSearch = false;
				}
				else if (pVariable->data.faculty == search)
				{
					if (pVariable == pHead)
					{
						pHead = pHead->nextElement;
						delete pVariable;
						pVariable = pHead;
					}
					else if (pVariable == pTail)
					{
						pTmpHead->nextElement = nullptr;
						delete pVariable;
						pVariable = nullptr;
					}
					else
					{
						pTmpHead->nextElement = pTmpTail;
						delete pVariable;
						pVariable = pTmpHead;
					}
					notSearch = false;
				}
				else if (pVariable->data.course == search)
				{
					if (pVariable == pHead)
					{
						pHead = pHead->nextElement;
						delete pVariable;
						pVariable = pHead;
					}
					else if (pVariable == pTail)
					{
						pTmpHead->nextElement = nullptr;
						delete pVariable;
						pVariable = nullptr;
					}
					else
					{
						pTmpHead->nextElement = pTmpTail;
						delete pVariable;
						pVariable = pTmpHead;
					}
					notSearch = false;
				}
				else if (pVariable->data.group == search)
				{
					if (pVariable == pHead)
					{
						pHead = pHead->nextElement;
						delete pVariable;
						pVariable = pHead;
					}
					else if (pVariable == pTail)
					{
						pTmpHead->nextElement = nullptr;
						delete pVariable;
						pVariable = nullptr;
					}
					else
					{
						pTmpHead->nextElement = pTmpTail;
						delete pVariable;
						pVariable = pTmpHead;
					}
					notSearch = false;
				}
				else
				{
					pTmpHead = pVariable;
					pVariable = pVariable->nextElement;
					if (pVariable != nullptr)
						pTmpTail = pVariable->nextElement;
				}
			}
			if (notSearch)
				std::cout << "������� �� ������\n";
			else
				std::cout << "�������" << '\n';
		}
		else
			std::cout << "������ ����" << '\n';
	}
	void searchElement()
	{
		if (pHead != nullptr)
		{
			list_t* pVariable = pHead;
			bool notSearch = true;
			std::string search;
			std::cout << "�����: ";
			std::getline(std::cin, search);
			while (pVariable != nullptr)
			{
				if (pVariable->data.Surname == search)
				{
					printElement(pVariable);
					notSearch = false;
				}
				else if (pVariable->data.faculty == search)
				{
					printElement(pVariable);
					notSearch = false;
				}
				else if (pVariable->data.course == search)
				{
					printElement(pVariable);
					notSearch = false;
				}
				else if (pVariable->data.group == search)
				{
					printElement(pVariable);
					notSearch = false;
				}
				pVariable = pVariable->nextElement;
			}
			if (notSearch)
				std::cout << "������� �� ������\n";
		}
		else
			std::cout << "������ ����" << '\n';
	}
	void printList()
	{
		if (pHead != nullptr)
		{
			list_t* pVariable = pHead;
			while (pVariable != nullptr)
			{
				printElement(pVariable);
				pVariable = pVariable->nextElement;
			}
		}
		else
			std::cout << "������ ����" << '\n';
	}
	void deleteList()
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
			std::cout << "������ �����" << '\n';
		}
		else
			std::cout << "������ ����" << '\n';
	}
	~List()
	{
		if (pHead != nullptr)
			deleteList();
	}
};

int main()
{
	system("chcp 1251");
	system("cls");
	List listOne;
	List::data data;
	char menu = '0';
	while (menu != '5')
	{
		std::cout << "1. �������� ����\n";
		std::cout << "2. ������� ����\n";
		std::cout << "3. �������� ������\n";
		std::cout << "4. �����\n";
		std::cout << "5. �����\n";
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			std::cout << "�������: ";
			std::getline(std::cin, data.Surname);
			std::cout << "���������: ";
			std::getline(std::cin, data.faculty);
			std::cout << "����: ";
			std::getline(std::cin, data.course);
			std::cout << "������: ";
			std::getline(std::cin, data.group);
			listOne.addElement(data);
			system("cls");
			break;
		case '2':
			listOne.deleteElement();
			system("pause");
			system("cls");
			break;
		case '3':
			listOne.printList();
			system("pause");
			system("cls");
			break;
		case '4':
			listOne.searchElement();
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}