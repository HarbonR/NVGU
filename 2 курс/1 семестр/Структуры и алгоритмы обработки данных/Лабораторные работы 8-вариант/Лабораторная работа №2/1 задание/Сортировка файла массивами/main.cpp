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
	int outputArray[length]; // ������ ��� ���������� �����
	int inputArray[length]; // ������ ��� ������ �� �����
	//==================================================
	for (int i = 0; i < length; i++)
	{
		outputArray[i] = length - i; // ��������� ������
	}
	//====================
	std::ofstream outputFile("file.dat", std::ios::binary);
	if (!outputFile.is_open())
		std::cout << "������ �������� �����" << '\n';
	else
	{
		outputFile.write((char*)&outputArray, sizeof(outputArray)); // ���������� ������ �� ������� � ����
		outputFile.close();
	}
	//==================================================
	std::cout << "�������� ����������:\n";
	//==================================================
	// �������� ���������� (���������� ���������) 
	std::ifstream inputFile("file.dat", std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "\t������ �������� �����" << '\n';
	else
	{
		inputFile.read((char*)&inputArray, sizeof(inputArray)); // ���������� ������ �� ����� � ������
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
	std::cout << "���������� ���������:\n";
	//==================================================
	// ���������� ���������
	inputFile.open("file.dat", std::ios::binary);
	if (!inputFile.is_open())
		std::cout << "\t������ �������� �����" << '\n';
	else
	{
		inputFile.read((char*)&inputArray, sizeof(inputArray)); // ���������� ������ �� ����� � ������
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