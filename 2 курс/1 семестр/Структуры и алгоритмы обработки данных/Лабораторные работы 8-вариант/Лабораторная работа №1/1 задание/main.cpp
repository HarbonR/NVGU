#include <iostream>
#include <conio.h>
#include <fstream>

typedef struct
{
	char school[30]; // Школа
	char yearOfEnding[30]; // Год окончания
	char university[30]; // Вуз
	int gradePointAverage; // Cредний балл аттестата
}enrollee; // Абитуриент

bool stringEqual(char* one, char* two)
{
	int lengthOne = 0;
	int lengthTwo = 0;
	for (int i = 0; one[i] != '\0'; i++)
		lengthOne++;
	for (int i = 0; two[i] != '\0'; i++)
		lengthTwo++;
	if (lengthOne != lengthTwo)
		return false;
	else
	{
		for (int i = 0; one[i] != '\0'; i++)
		{
			if (one[i] != two[i])
				return false;
		}
		return true;
	}
}

void addElement(char* pathToFile)
{
	enrollee element;
	std::cout << "school: ";
	std::cin >> element.school;
	std::cout << "yearOfEnding: ";
	std::cin >> element.yearOfEnding;
	std::cout << "university: ";
	std::cin >> element.university;
	std::cout << "gradePointAverage: ";
	std::cin >> element.gradePointAverage;
	std::ofstream output(pathToFile, std::ios::app);
	if (!output.is_open())
	{
		std::cout << "Ошибка открытия файла" << '\n';
	}
	else
	{
		output.write((char*)&element, sizeof(enrollee));
		output.close();
	}
}

void deleteElement(char* pathToFile, char* findAField)
{
	enrollee element;
	char gradePointAverage[30];
	bool isElement = false;
	std::ifstream input(pathToFile);
	std::ofstream varInput("variableFile.txt");
	if (!input.is_open() || !varInput.is_open())
		std::cout << "Ошибка открытия файла" << '\n';
	else
	{
		while (input.read((char*)&element, sizeof(enrollee)))
		{
			_itoa_s(element.gradePointAverage, gradePointAverage, 10);
			if (stringEqual(element.school, findAField))
			{
				isElement = true;
			}
			else if (stringEqual(element.yearOfEnding, findAField))
			{
				isElement = true;
			}
			else if (stringEqual(element.university, findAField))
			{
				isElement = true;
			}
			else if (stringEqual(gradePointAverage, findAField))
			{
				isElement = true;
			}
			else
				varInput.write((char*)&element, sizeof(enrollee));
		}
		input.close();
		varInput.close();
		remove(pathToFile);
		rename("variableFile.txt", pathToFile);
		if (!isElement)
		{
			std::cout << "Строка не найдена\n";
			system("pause");
		}
	}
}

void findElement(char* pathToFile, char* findAField)
{
	enrollee element;
	char gradePointAverage[30];
	char border[] = "==================================================";
	std::ifstream input(pathToFile);
	if (!input.is_open())
		std::cout << "Ошибка открытия файла" << '\n';
	else
	{
		std::cout << border;
		while (input.read((char*)&element, sizeof(enrollee)))
		{
			_itoa_s(element.gradePointAverage, gradePointAverage, 10);
			if (stringEqual(element.school, findAField))
			{
				std::cout << '\n' << element.school << '\n' << element.yearOfEnding << '\n' << element.university << '\n' << element.gradePointAverage << '\n';
				std::cout << border;
			}
			else if (stringEqual(element.yearOfEnding, findAField))
			{
				std::cout << '\n' << element.school << '\n' << element.yearOfEnding << '\n' << element.university << '\n' << element.gradePointAverage << '\n';
				std::cout << border;
			}
			else if (stringEqual(element.university, findAField))
			{
				std::cout << '\n' << element.school << '\n' << element.yearOfEnding << '\n' << element.university << '\n' << element.gradePointAverage << '\n';
				std::cout << border;
			}
			else if (stringEqual(gradePointAverage, findAField))
			{
				std::cout << '\n' << element.school << '\n' << element.yearOfEnding << '\n' << element.university << '\n' << element.gradePointAverage << '\n';
				std::cout << border;
			}
		}
	}
}

void printRecords(char* pathToFile)
{
	enrollee element;
	char border[] = "==================================================";
	std::ifstream input(pathToFile);
	if (!input.is_open())
		std::cout << "Ошибка открытия файла" << '\n';
	else
	{
		std::cout << border << '\n';
		while (input.read((char*)&element, sizeof(enrollee)))
		{
			std::cout << element.school << '\n' << element.yearOfEnding << '\n' << element.university << '\n' << element.gradePointAverage << '\n' << border << '\n';
		}
		input.close();
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	char menu = '0';
	char path[] = "data.txt";
	char findAField[30];
	while (menu != '5')
	{
		std::cout << "1. Добавить элемент в файл" << '\n';
		std::cout << "2. Удалить элемент из файла" << '\n';
		std::cout << "3. Принадлежность элемента файлу" << '\n';
		std::cout << "4. Вывод всех записей на экран" << '\n';
		std::cout << "5. Выход" << '\n';
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			addElement(path);
			system("cls");
			break;
		case '2':
			std::cin >> findAField;
			deleteElement(path, findAField);
			system("cls");
			break;
		case '3':
			std::cin >> findAField;
			findElement(path, findAField);
			std::cout << '\n';
			system("pause");
			system("cls");
			break;
		case '4':
			printRecords(path);
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}