#include <iostream>
#include <fstream>
#include <chrono>

void printFile(std::string pathToFile)
{
	std::ifstream inputFile(pathToFile, std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "Error";
	else
	{
		int value = 0;
		int size = 0;
		inputFile.seekg(0, std::ios::end);
		size = inputFile.tellg() / sizeof(int);
		for (int i = 0; i < size; i++)
		{
			inputFile.seekg(sizeof(int) * i);
			inputFile.read((char*)&value, sizeof(int));
			std::cout << value << ' ';
		}
		inputFile.close();
		std::cout << '\n';
	}
}

void fillFile(std::string pathToFile, int length)
{
	std::ofstream outputFile("file.dat", std::ios::binary);
	if (!outputFile.is_open())
		std::cout << "Error open file\n";
	else
	{
		int value = length;
		for (int i = 0; i < length; i++)
		{
			outputFile.seekp(sizeof(int) * i);
			outputFile.write((char*)&value, sizeof(int));
			value--;
		}
		outputFile.close();
	}
}

bool isSortedFile(std::string pathToFile)
{
	std::ifstream inputFile(pathToFile, std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "\tError open file\n";
	else
	{
		int first = 0;
		int second = 0;
		int size = 0;
		inputFile.seekg(0, std::ios::end);
		size = inputFile.tellg() / sizeof(int);
		for (int i = 0; i < size - 1; i++)
		{
			inputFile.seekg(sizeof(int) * i);
			inputFile.read((char*)&first, sizeof(int));
			inputFile.seekg(sizeof(int) * i + sizeof(int));
			inputFile.read((char*)&second, sizeof(int));
			if (first < second)
				continue;
			else
			{
				inputFile.close();
				return false;
			}
		}
		inputFile.close();
		return true;
	}
}

void bubbleSortFile(std::string pathToFile)
{
	std::fstream file(pathToFile, std::ios::in | std::ios::out | std::ios::binary);
	if (!file.is_open())
		std::cout << "\tError open file\n";
	else
	{
		int first = 0; // Первый элемент
		int second = 0; // Второй элемент
		int size = 0; // Размер файла
		int end = 1;
		file.seekg(0, std::ios::end);
		size = file.tellg() / sizeof(int);
		//==================================================
		while (!isSortedFile(pathToFile))
		{
			for (int i = 0; i < size - end; i++)
			{
				file.seekg(sizeof(int) * i);
				file.read((char*)&first, sizeof(int));
				file.seekg(sizeof(int) * i + sizeof(int));
				file.read((char*)&second, sizeof(int));
				if (first > second)
				{
					file.seekp(sizeof(int) * i);
					file.write((char*)&second, sizeof(int));
					file.seekp(sizeof(int) * i + sizeof(int));
					file.write((char*)&first, sizeof(int));
				}
			}
		}
		//==================================================
		file.close();
	}
}

void insertionSort(std::string pathToFile)
{
	std::fstream file(pathToFile, std::ios::in | std::ios::out | std::ios::binary);
	if (!file.is_open())
		std::cout << "\tError open file\n";
	else
	{
		int temp = 0;
		int tempIndex = 0;
		int index = 0;
		int size = 0; // Размер файла
		file.seekg(0, std::ios::end);
		size = file.tellg() / sizeof(int);
		//==================================================
		for (int i = 1; i < size; i++)
		{
			file.seekg(sizeof(int) * i);
			file.read((char*)&temp, sizeof(int));
			index = i - 1;
			file.seekg(sizeof(int) * index);
			file.read((char*)&tempIndex, sizeof(int));
			while (index >= 0 && tempIndex > temp)
			{
				file.seekp(sizeof(int) * (index + 1));
				file.write((char*)&tempIndex, sizeof(int));
				file.seekp(sizeof(int) * index);
				file.write((char*)&temp, sizeof(int));
				index--;
				if (index >= 0)
				{
					file.seekg(sizeof(int) * index);
					file.read((char*)&tempIndex, sizeof(int));
				}
			}
		}
		//==================================================
		file.close();
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	std::string pathToFile = "file.dat";
	int length = 1000;
	//==================================================
	//Обменная сортировка (пузырькова сортировка)
	std::cout << "Обменная сортировка:\n";
	fillFile(pathToFile, length);
	if (isSortedFile(pathToFile))
		std::cout << "\tSorted\n";
	else
		std::cout << "\tNot sorted\n";
	auto start = std::chrono::high_resolution_clock::now();
	bubbleSortFile(pathToFile);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "\ttime: " << duration.count() << '\n';
	if (isSortedFile(pathToFile))
		std::cout << "\tSorted\n";
	else
		std::cout << "\tNot sorted\n";
	//==================================================
	//Сортировка вставками
	std::cout << "Сортировка вставками:\n";
	fillFile(pathToFile, length);
	if (isSortedFile(pathToFile))
		std::cout << "\tSorted\n";
	else
		std::cout << "\tNot sorted\n";
	start = std::chrono::high_resolution_clock::now();
	insertionSort(pathToFile);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "\ttime: " << duration.count() << '\n';
	if (isSortedFile(pathToFile))
		std::cout << "\tSorted\n";
	else
		std::cout << "\tNot sorted\n";
	//==================================================
	system("pause");
	return 0;
}