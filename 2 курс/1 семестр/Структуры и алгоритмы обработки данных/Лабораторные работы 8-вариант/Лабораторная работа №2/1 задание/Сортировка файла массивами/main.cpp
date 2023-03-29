#include <iostream>
#include <fstream>
#include <chrono>

bool isSorted(int *input, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (input[i] < input[i + 1])
			continue;
		else
			return false;
	}
	return true;
}

void bubbleSort(int* input, int length)
{
	int end = 1;
	while (!isSorted(input, length))
	{
		for (int j = 0; j < length - end; j++)
		{
			if (input[j] > input[j + 1])
			{
				int variable = input[j];
				input[j] = input[j + 1];
				input[j + 1] = variable;
			}
		}
		end++;
	}
}

void insertionSort(int* input, int length)
{
	for (int i = 1; i < length; i++)
	{
		int temp = input[i];
		int index = i - 1;
		while (index >= 0 && input[index] > temp)
		{
			input[index + 1] = input[index];
			input[index] = temp;
			index--;
		}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	const int length = 10000;
	int outputArray[length]; // Массив для заполнения файла
	int inputArray[length]; // Массив для данных из файла
	//==================================================
	for (int i = 0; i < length; i++)
	{
		outputArray[i] = length - i; // Заполняем массив
	}
	//====================
	std::ofstream outputFile("file.dat", std::ios::binary);
	if (!outputFile.is_open())
		std::cout << "Ошибка открытия файла" << '\n';
	else
	{
		outputFile.write((char*)&outputArray, sizeof(outputArray)); // Записываем данные из массива в файл
		outputFile.close();
	}
	//==================================================
	std::cout << "Обменная сортировка:\n";
	//==================================================
	// Обменная сортировка (Сортировка пузырьком) 
	std::ifstream inputFile("file.dat", std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "\tОшибка открытия файла" << '\n';
	else
	{
		inputFile.read((char*)&inputArray, sizeof(inputArray)); // Записываем данные из файла в массив
		inputFile.close();
		if (isSorted(inputArray, length))
			std::cout << "\tSorted\n";
		else
			std::cout << "\tNot sorted\n";
		auto start = std::chrono::high_resolution_clock::now();
		bubbleSort(inputArray, length);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << "\ttime: " << duration.count() << '\n';
		if (isSorted(inputArray, length))
			std::cout << "\tSorted\n";
	}
	//==================================================
	std::cout << "Сортировка вставками:\n";
	//==================================================
	// Сортировка вставками
	inputFile.open("file.dat", std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "\tОшибка открытия файла" << '\n';
	else
	{
		inputFile.read((char*)&inputArray, sizeof(inputArray)); // Записываем данные из файла в массив
		inputFile.close();
		if (isSorted(inputArray, length))
			std::cout << "\tSorted\n";
		else
			std::cout << "\tNot sorted\n";
		auto start = std::chrono::high_resolution_clock::now();
		insertionSort(inputArray, length);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << "\ttime: " << duration.count() << '\n';
		if (isSorted(inputArray, length))
			std::cout << "\tSorted\n";
	}
	//==================================================
	return 0;
}