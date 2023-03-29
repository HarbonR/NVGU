#include <iostream>
#include <fstream>
#include <string>

struct student
{
	char fam[20] = "\0";
	char dr[20] = "\0";
	char hob1[12] = "\0";
	char hob2[12] = "\0";
	char hob3[12] = "\0";
	char hob4[12] = "\0";
};

int heshFunction(char *inputString)
{
	return unsigned char(inputString[0]) * 6;
}

void addToFile(std::string pathToFile, student &input)
{
	std::fstream file;
	file.open(pathToFile, std::ios::in | std::ios::binary);
	if (!file.is_open())
		std::cout << "Error open file\n";
	else
	{
		student tmp;
		int hesh = heshFunction(input.fam);
		file.seekg(hesh * sizeof(student));
		file.read((char*)&tmp, sizeof(student));
		if (tmp.fam[0] == input.fam[0])
		{
			std::string pathToFile = std::string() + input.fam[0] + ".dat";
			std::ofstream outputFile(pathToFile, std::ios::app | std::ios::binary);
			if(!outputFile.is_open())
				std::cout << "Error open file\n";
			else
			{
				outputFile.write((char*)&input, sizeof(student));
				outputFile.close();
			}
			file.close();
		}
		else
		{
			file.close();
			file.open(pathToFile, std::ios::in | std::ios::out | std::ios::binary);
			if (!file.is_open())
				std::cout << "Error open file\n";
			else
			{
				file.seekg(hesh * sizeof(student));
				file.write((char*)&input, sizeof(student));
				file.close();
			}
		}
	}
}

bool printFile(std::string pathToFile, int counter = 0)
{
	std::ifstream inputFile(pathToFile);
	if (!inputFile.is_open())
		return false;
	else
	{
		student tmp;
		inputFile.seekg(0, std::ios::end);
		int size = inputFile.tellg() / sizeof(student);
		inputFile.seekg(0);
		for(int i = 0; i < size; i++)
		{
			inputFile.read((char*)&tmp, sizeof(student));
			if (tmp.fam[0] != '\0')
			{
				std::cout << tmp.fam << '\n';
				std::cout << tmp.dr << '\n';
				std::cout << tmp.hob1 << '\n';
				std::cout << tmp.hob2 << '\n';
				std::cout << tmp.hob3 << '\n';
				std::cout << tmp.hob4 << '\n';
				std::cout << "==================================================\n";
				if (counter == 0)
				{
					std::string pathToFile = std::string() + tmp.fam[0] + ".dat";
					printFile(pathToFile, 1);
				}
			}
		}
		inputFile.close();
		return true;
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	std::string pathToFile = "students.dat";
	//==================================================
	// Открываем файл на запись, если нет создаём
	std::ofstream outputFile(pathToFile);
	if (!outputFile.is_open())
		std::cout << "Error open file\n";
	else
		outputFile.close();
	//==================================================
	// Заносим данные из файла в файл
	std::ifstream inputFile("inputFile.txt");
	if (!inputFile.is_open())
		std::cout << "Error open file\n";
	else
	{
		student tmp;
		while (true)
		{
			inputFile >> tmp.fam;
			inputFile >> tmp.dr;
			inputFile >> tmp.hob1;
			inputFile >> tmp.hob2;
			inputFile >> tmp.hob3;
			inputFile >> tmp.hob4;
			if (inputFile.eof())
				break;
			addToFile(pathToFile, tmp);
		}
		inputFile.close();
	}
	//==================================================
	printFile(pathToFile);
	//==================================================
	return 0;
}