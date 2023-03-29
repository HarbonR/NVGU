#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

int heshFunction(char* inputString)
{
	return (unsigned char(inputString[0]) * 50) + (unsigned char(inputString[0])) - 51;
}

bool stringEqual(char* one, char* two)
{
	for (int i = 0; one[i] != '\0'; i++)
	{
		if (one[i] != two[i])
			return false;
	}
	return true;
}

void addElementToFile(char* pathToFile)
{
	FILE* file = fopen(pathToFile, "r+t");
	if (file == NULL)
		std::cout << "Error open file\n";
	else
	{
		char string[50];
		gets_s(string, 50);
		int hesh = heshFunction(string);
		while (true)
		{
			char tmp[50] = { '\0' };
			char tmp1[50] = { '\0' };
			fseek(file, hesh * (sizeof(char) * 50), SEEK_SET);
			fgets(tmp, sizeof(char) * 50, file);
			if (stringEqual(tmp, tmp1))
				break;
			if (tmp[0] != '\0')
				hesh++;
			else
				break;
		}
		fseek(file, hesh * (sizeof(char) * 50), SEEK_SET);
		fputs(string, file);
		fclose(file);
	}
}

void printFile(char* pathToFile)
{
	std::ifstream inputFile(pathToFile, std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "Error open file\n";
	else
	{
		char variableString[50];
		while (!inputFile.eof())
		{
			inputFile.read((char*)&variableString, (sizeof(char) * 50));
			if (variableString[0] != '\0')
				std::cout << variableString << '\n';
		}
		inputFile.close();
	}
}

void search(char* pathToFile, char *searchString)
{
	std::ifstream inputFile(pathToFile);
	if (!inputFile.is_open())
		std::cout << "Error open file\n";
	else
	{
		char variableString[50] = {'\0'};
		int hesh = heshFunction(searchString);
		do
		{
			inputFile.seekg(hesh * (sizeof(char) * 50));
			inputFile.read((char*)&variableString, sizeof(char) * 50);
			hesh++;
		} while (!stringEqual(variableString, searchString));
		std::cout << variableString << '\n';
		inputFile.close();
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	char outputFile[] = "Person.txt";
	char string[50];
	FILE* f = fopen(outputFile, "wt");
	if (f == NULL)
		std::cout << "Error open file\n";
	else
		fclose(f);
	char menu = '0';
	while (menu != '4')
	{
		std::cout << "1. Добавить элемент\n";
		std::cout << "2. Поиск элемента\n";
		std::cout << "3. Просмотр элементов\n";
		std::cout << "4. Выход\n";
		menu = _getch();
		system("cls");
		switch (menu)
		{
		case '1':
			addElementToFile(outputFile);
			system("cls");
			break;
		case '2':
			gets_s(string, 50);
			search(outputFile, string);
			system("pause");
			system("cls");
			break;
		case '3':
			printFile(outputFile);
			system("pause");
			system("cls");
		}
	}
	return 0;
}