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
		std::cout << "Фамилия: " << list->data.Surname << '\n';
		std::cout << "Факультет: " << list->data.faculty << '\n';
		std::cout << "Курс: " << list->data.course << '\n';
		std::cout << "Группа: " << list->data.group << '\n';
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
			std::cout << "Удалить: ";
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
				std::cout << "Элемент не найден\n";
			else
				std::cout << "Удалено" << '\n';
		}
		else
			std::cout << "Список пуст" << '\n';
	}
	void searchElement()
	{
		if (pHead != nullptr)
		{
			list_t* pVariable = pHead;
			bool notSearch = true;
			std::string search;
			std::cout << "Найти: ";
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
				std::cout << "Элемент не найден\n";
		}
		else
			std::cout << "Список пуст" << '\n';
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
			std::cout << "Список пуст" << '\n';
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
			std::cout << "Список удалён" << '\n';
		}
		else
			std::cout << "Список пуст" << '\n';
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
		std::cout << "1. Добавить узел\n";
		std::cout << "2. Удалить узел\n";
		std::cout << "3. Просмотр списка\n";
		std::cout << "4. Поиск\n";
		std::cout << "5. Выход\n";
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			std::cout << "Фамилия: ";
			std::getline(std::cin, data.Surname);
			std::cout << "Факультет: ";
			std::getline(std::cin, data.faculty);
			std::cout << "Курс: ";
			std::getline(std::cin, data.course);
			std::cout << "Группа: ";
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