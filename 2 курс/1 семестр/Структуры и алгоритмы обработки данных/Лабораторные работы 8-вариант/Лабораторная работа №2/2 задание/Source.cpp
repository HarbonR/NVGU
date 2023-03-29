#include <iostream>
#include <string>
#include <conio.h>

template<typename T>
bool isSorted(T* inputArray, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (inputArray[i] < inputArray[i + 1])
			continue;
		else
			return false;
	}
	return true;
}

template<typename T>
void quickSort(T* inputArray, int length)
{
    int i = 0;
    int j = length - 1;
    T mid = inputArray[length / 2];
    do
    {
        while (inputArray[i] < mid)
        {
            i++;
        }
        while (inputArray[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            T tmp = inputArray[i];
            inputArray[i] = inputArray[j];
            inputArray[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
    {
        quickSort(inputArray, j + 1);
    }
    if (i < length)
    {
        quickSort(&inputArray[i], length - i);
    }
}

template<typename T>
void sequentialSearch(T* inputArray, int length, T& search)
{
    int counter = 0;
    bool isSearch = false;
    for (int i = 0; i < length; i++)
    {
        if (inputArray[i] == search)
        {
            std::cout << inputArray[i] << '\n';
            std::cout << "Количество шагов: " << counter << '\n';
            isSearch = true;
            break;
        }
        counter++;
    }
    if (!isSearch)
        std::cout << "Строка не найдена\n";
}

template<typename T>
void binarySearch(T* inputArray, int length, T search)
{
    int min = 0;
    int max = length - 1;
    int mid;
    int counter = 0;
    bool isSearch = false;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (inputArray[mid] < search)
        {
            min = mid + 1;
        }
        else if (inputArray[mid] > search)
        {
            max = mid - 1;
        }
        else if (inputArray[mid] == search)
        {
            std::cout << inputArray[mid] << '\n';
            std::cout << "Количество шагов: " << counter << '\n';
            isSearch = true;
            break;
        }
        counter++;
    }
    if (!isSearch)
        std::cout << "Строка не найдена\n";
}

int main()
{
    system("chcp 1251");
    system("cls");
    std::string inputArray[100];
    std::string tmp;
    int index = 0;
    char menu = '0';
    while (menu != '6')
    {
        std::cout << "1. Добавить строку\n";
        std::cout << "2. Сортировать\n";
        std::cout << "3. Последовательный поиск\n";
        std::cout << "4. Бинарный поиск\n";
        std::cout << "5. Показать массив строк\n";
        std::cout << "6. Выход\n";
        menu = _getch();
        system("cls");
        switch (menu)
        {
        case '1' :
            std::cout << "Введите строку\n";
            std::getline(std::cin, inputArray[index]);
            index++;
            system("cls");
            break;
        case '2':
            quickSort(inputArray, index);
            std::cout << "Отсортированно\n";
            system("pause");
            system("cls");
            break;
        case '3':
            std::cin >> tmp;
            sequentialSearch(inputArray, index, tmp);
            system("pause");
            system("cls");
            break;
        case '4':
            if (isSorted(inputArray,index))
            {
                std::cin >> tmp;
                binarySearch(inputArray, index, tmp);
                system("pause");
                system("cls");
            }
            else
            {
                std::cout << "Массив не отсортирован, отсортируйте массив\n";
                system("pause");
                system("cls");
            }
            break;
        case '5':
            for (int i = 0; i < index; i++)
            {
                std::cout << inputArray[i] << '\n';
            }
            system("pause");
            system("cls");
            break;
        }
    }
	return 0;
}