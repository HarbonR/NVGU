#include <iostream>
#include <fstream>

int heshFunction(std::string inputString)
{
	return (unsigned char(inputString[0]) * 50) + (unsigned char(inputString[1])) - 51;
}

void fillFile(std::string pathToInputFile, std::string pathToOutputFile)
{
	std::ifstream inputFile(pathToInputFile);
	std::ofstream outputFile(pathToOutputFile);
	if (!inputFile.is_open() || !outputFile.is_open())
	{
		if (inputFile.is_open())
			inputFile.close();
		else if (outputFile.is_open())
			outputFile.close();
		std::cout << "Error open file\n";
	}
	else
	{
		char variableString[50];
		while (!inputFile.eof())
		{
			inputFile >> variableString;
			int hash = heshFunction(variableString);
			outputFile.seekp(hash * (sizeof(char) * 50));
			outputFile << variableString;
		}
		outputFile.close();
		inputFile.close();
	}
}

void printFile(std::string pathToInputFile)
{
	std::ifstream inputFile(pathToInputFile, std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "Error open file\n";
	else
	{
		char variableString[50];
		inputFile.seekg(0, std::ios::end);
		int size = inputFile.tellg() / (sizeof(char) * 50);
		for (int i = 0; i < size; i++)
		{
			inputFile.seekg(i * (sizeof(char) * 50));
			inputFile.read((char*)&variableString, (sizeof(char) * 50));
			if (variableString[0] != '\0')
				std::cout << variableString << '\n';
		}
		inputFile.close();
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	std::string pathToInputFile = "Surname.txt";
	std::string pathToOutputFile = "Person.txt";
	fillFile(pathToInputFile, pathToOutputFile);
	printFile(pathToOutputFile);
	return 0;
}