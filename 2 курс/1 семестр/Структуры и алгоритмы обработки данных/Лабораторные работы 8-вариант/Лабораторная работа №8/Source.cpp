#include <iostream>
#include <conio.h>

struct elementArray
{
	int element;
	int index;
};

elementArray minNumber(elementArray a, elementArray b)
{
	if (a.element < b.element)
		return a;
	else
		return b;
}

void printArray(elementArray* inputArray, int lengthArray)
{
	for (int i = 0; i < lengthArray; i++)
	{
		if (inputArray[i].element == 1000)
		{
			for (int i = 0; i < 50 / lengthArray; i++)
			{
				std::cout << ' ';
			}
			std::cout << "___";
		}
		else if (lengthArray == 1)
		{
			for (int i = 0; i < 50 / 1.3; i++)
			{
				std::cout << ' ';
			}
			std::cout << inputArray[i].element;
		}
		else
		{
			for (int i = 0; i < 50 / lengthArray; i++)
			{
				std::cout << ' ';
			}
			std::cout << inputArray[i].element;
		}
	}
	std::cout << '\n';
}

elementArray minNumberToArray(elementArray *inputArray, int lengthArray)
{
	elementArray returned;
	printArray(inputArray, lengthArray);
	if (lengthArray == 1)
		return inputArray[0];
	int lengthTmpArray = lengthArray / 2;
	if (lengthArray == 3)
		lengthTmpArray = 2;
	if (lengthTmpArray != 0)
	{
		elementArray* tmpArray = new elementArray[lengthTmpArray];
		for (int i = 0, j = 0; j < lengthTmpArray; i+=2, j++)
		{
			if (i < lengthArray - 1)
				tmpArray[j] = minNumber(inputArray[i], inputArray[i + 1]);
			else
			{
				tmpArray[j] = inputArray[i];
			}
			if (lengthTmpArray == 1)
				returned = tmpArray[0];
		}
		returned = minNumberToArray(tmpArray, lengthTmpArray);
		delete[] tmpArray;
	}
	return returned;
}

void eliminationTournament(int *inputArray, int lengthArray)
{
	char nextElement;
	elementArray* array = new elementArray[lengthArray];
	elementArray* sortArray = new elementArray[lengthArray];
	for (int i = 0; i < lengthArray; i++)
	{
		array[i].element = inputArray[i];
		array[i].index = i;
	}
	for (int i = 0; i < lengthArray; i++)
	{
		sortArray[i] = minNumberToArray(array, lengthArray);
		std::cout << "==================================================\n";
		for(int j = 0; j <= i; j++)
			std::cout << sortArray[j].element << ' ';
		std::cout << '\n';
		nextElement = _getch();
		system("cls");
		array[sortArray[i].index].element = 1000;
	}

	delete[] array;
}
 
int main()
{
	int numbersArray[12] = { 54, 101, 27, 14, 17, 18, 54, 91, 72, 76, 75, 102 };
	eliminationTournament(numbersArray, 12);
	return 0;
}