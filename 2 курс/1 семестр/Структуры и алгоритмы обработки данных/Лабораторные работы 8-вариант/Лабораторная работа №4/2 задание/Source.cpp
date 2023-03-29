#include <iostream>
#include <fstream>
#include <string>

struct Men
{
	unsigned char surname[256];
	unsigned char name[256];
};

void fillFile(std::string pathToInputFile, std::string pathToOutputFile)
{
	std::ifstream inputFile(pathToInputFile);
	std::ofstream outputFile(pathToOutputFile, std::ios::binary);
	if (!inputFile.is_open() || !outputFile.is_open())
		std::cout << "Ошибка открытия файла\n";
	else
	{
		Men tmp;
		int position;
		while (!inputFile.eof())
		{
			inputFile >> tmp.surname;
			inputFile >> tmp.name;
			position = 0;
			position = tmp.surname[0] + tmp.surname[1];
			position %= 100;
			position *= sizeof(Men);
			outputFile.seekp(position);
			outputFile.write((char*)&tmp, sizeof(tmp));
		}
		inputFile.close();
		outputFile.close();
	}
}

void printFile(std::string pathToFile)
{
	std::ifstream file(pathToFile, std::ios::binary);
	if(!file.is_open())
		std::cout << "Ошибка открытия файла\n";
	else
	{
		file.seekg(0, std::ios::end);
		int size = file.tellg() / sizeof(Men);
		file.seekg(0);
		std::cout << "Фамилия:\t" << "Имя:\n";
		for (int i = 0; i < size; i++)
		{
			Men tmp;
			file.read((char*)&tmp, sizeof(tmp));
			if (tmp.surname[0] != '\0' || tmp.name[0] != '\0')
			{
				std::cout << tmp.surname << "\r\t\t";
				std::cout << tmp.name << '\n';
			}
		}
		file.close();
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	fillFile("inputFile.txt", "outputFile.dat");
	printFile("outputFile.dat");
	return 0;
}