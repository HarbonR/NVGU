#include <stdio.h> /// ����������� ���������� �����-������.
#include <locale.h> /// ���������� ��� ����������� ������.
#include <conio.h> /// ���������� ��� ������� �����-������.
#include <stdlib.h> /// ����������� ����������.
#include <time.h> /// ���������� ��� ������ �� ��������.
#include "myMod.h"

//====================================================================================================
/// ������� ��� exercise 4.

/// ������� ��������� 3-� ������� �����. ���������� 1, ���� � ����� ���� ������ �����. ����� ���������� 0.
int evenDigitsInNumber (int number)
{
    int variableBool = 0;
    int variableX;
    while (number != 0)
    {
        variableX = number % 10; /// ���������� variableX ������������� ��������� ����� �����
        if (variableX % 2 == 0)
            variableBool = 1;
        number /= 10; /// �� ���������� number ��������� ��������� �����
    }
    if (variableBool == 1)
        return 1;
    else
        return 0;
}

/// ������� ��������� �������� 3-� ������� �����. ���������� ����� ����� � ������� ��� ������ ����.
int summNumbers (int from, int to)
{
    int summ = 0;
    for (int i = from; i <= to; i++)
    {
        if (evenDigitsInNumber(i) == 0)
            summ += i;
    }
    return summ;
}

//====================================================================================================
/// ������� ��� exercise 9.

/// ������� ��������� ���������� number(���-��) � character(������). ������� � ������� �������. ������ �� ����������.
void printChar (int number, char character)
{
    int i;
    for (i = 0; i < number; i++)
        printf("%c", character);
    printf("\n");
}

//====================================================================================================
/// ������� ��� exercise 14.

/// ������� ��������� ���������� ��������� � �������. ���������� ��������� �� ���������� ������.
int* mallocForArrayTypeInt (int numberElements)
{
    return (int*)malloc(numberElements * sizeof(int));
}

/// ������� ��������� ������ � ���������� ��� ���������. ��������� ������. ������ �� ����������.
void fillArrayTypeIntRandomNumbers (int *inputArrayTypeInt, int numberElements)
{
    int i;
    for (i = 0; i < numberElements; i++)
    {
        inputArrayTypeInt[i] = rand() % 9 + 1;
    }
}

/// ������� ��������� ������ � ���������� ��� ���������. ������� ������ � �������. ������ �� ����������.
void printArrayTypeInt (int *inputArrayTypeInt, int numberElements)
{
    int i;
    for (i = 0; i < numberElements; i++)
    {
        printf("%d ", inputArrayTypeInt[i]);
    }
    printf("\n");
}

/// ������� ��������� ��� ������� � ���������� ��������� � ������ � ������ �������. ���������� ������ � ������ ������, ���������� ��������� � ������. ������ �� ����������.
void summTwoArraysTypeInt (int *inputFirstArray, int numberElementsFirstArray, int *inputSecondArray, int numberElementsSecondArray , int *summTwoArrays)
{
    int i;
    if (numberElementsFirstArray > numberElementsSecondArray)
    {
        for (i = 0; i < numberElementsSecondArray; i++)
        {
            summTwoArrays[i] = inputFirstArray[i] + inputSecondArray[i];
        }
        for (; i < numberElementsFirstArray; i++)
        {
            summTwoArrays[i] = inputFirstArray[i];
        }
    }
    else if (numberElementsSecondArray > numberElementsFirstArray)
    {
        for (i = 0; i < numberElementsFirstArray; i++)
        {
            summTwoArrays[i] = inputFirstArray[i] + inputSecondArray[i];
        }
        for (; i < numberElementsSecondArray; i++)
        {
            summTwoArrays[i] = inputSecondArray[i];
        }
    }
    else if (numberElementsFirstArray == numberElementsSecondArray)
    {
        for (i = 0; i < numberElementsFirstArray; i++)
        {
            summTwoArrays[i] = inputFirstArray[i] + inputSecondArray[i];
        }
    }
}

//====================================================================================================
