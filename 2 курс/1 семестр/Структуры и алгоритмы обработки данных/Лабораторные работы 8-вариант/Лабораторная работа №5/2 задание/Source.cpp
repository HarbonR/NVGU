#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>

int heshFunction(char* inputString)
{
	return (unsigned char(inputString[0]) * 50) + (unsigned char(inputString[0])) - 51;
}

void copyString(char* inputString, char* outputString, int length)
{
	for (int i = 0; i < length; i++)
	{
		outputString[i] = inputString[i];
	}
}

bool stringEqual(char* one, char* two, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (one[i] != two[i])
			return false;
	}
	return true;
}

void fillFile(char* pathToInputFile, char* pathToOutputFile)
{
	FILE* inputFile = fopen(pathToInputFile, "rb");
	FILE* outputFile = fopen(pathToOutputFile, "w+b");
	if (inputFile == NULL || outputFile == NULL)
	{
		if (inputFile != NULL)
			fclose(inputFile);
		else if (outputFile != NULL)
			fclose(outputFile);
		std::cout << "Error open file\n";
	}
	else
	{
		while (!feof(inputFile))
		{
			char string[50];
			fgets(string, sizeof(char) * 50, inputFile);
			int hesh = heshFunction(string);
			fseek(outputFile, hesh * (sizeof(char) * 50), SEEK_SET);
			while (true)
			{
				char tmp[50];
				char tmp1[50];
				copyString(tmp, tmp1, 50);
				fgets(tmp, sizeof(char) * 50, outputFile);
				if (stringEqual(tmp, tmp1, 50))
					break;
				if (tmp[0] != '\0')
					hesh++;
				else
					break;
			}
			fseek(outputFile, hesh * (sizeof(char) * 50), SEEK_SET);
			fputs(string, outputFile);
		}
		fclose(inputFile);
		fclose(outputFile);
	}
}

void printFile(char* pathToInputFile)
{
	std::ifstream inputFile(pathToInputFile, std::ios::binary);
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

int main()
{
	system("chcp 1251");
	system("cls");
	char inputFile[] = "Surname.txt";
	char outputFile[] = "Person.txt";
	fillFile(inputFile, outputFile);
	printFile(outputFile);
	return 0;
}