#include <stdio.h> /// Стандартная библиотека ввода-вывода.
#include <locale.h> /// Библиотека для локализации языков.
#include <conio.h> /// Библиотека для функций ввода-вывода.
#include <stdlib.h> /// Стандартная библиотека.
#include <time.h> /// Библиотека для работы со временем.
#include "myMod.h"

//====================================================================================================
/// Функции для exercise 4.

/// Функция принимает 3-х значное число. Возвращает 1, если в числе есть четные цифры. Иначе возвращает 0.
int evenDigitsInNumber (int number)
{
    int variableBool = 0;
    int variableX;
    while (number != 0)
    {
        variableX = number % 10; /// Переменной variableX присваивается последняя цифра числа
        if (variableX % 2 == 0)
            variableBool = 1;
        number /= 10; /// Из переменной number убирается последняя цифра
    }
    if (variableBool == 1)
        return 1;
    else
        return 0;
}

/// Функция принимает диапозон 3-х значных чисел. Возвращает сумму чисел в которых нет четных цифр.
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
/// Функции для exercise 9.

/// Функция принимает переменные number(кол-во) и character(символ). Выводит в консоль символы. Ничего не возвращает.
void printChar (int number, char character)
{
    int i;
    for (i = 0; i < number; i++)
        printf("%c", character);
    printf("\n");
}

//====================================================================================================
/// Функции для exercise 14.

/// Функция принимает количество элементов в массиве. Возвращает указатель на выделенную память.
int* mallocForArrayTypeInt (int numberElements)
{
    return (int*)malloc(numberElements * sizeof(int));
}

/// Функция принимает массив и количество его элементов. Заполняет массив. Ничего не возвращает.
void fillArrayTypeIntRandomNumbers (int *inputArrayTypeInt, int numberElements)
{
    int i;
    for (i = 0; i < numberElements; i++)
    {
        inputArrayTypeInt[i] = rand() % 9 + 1;
    }
}

/// Функция принимает массив и количество его элементов. Выводит массив в консоль. Ничего не возвращает.
void printArrayTypeInt (int *inputArrayTypeInt, int numberElements)
{
    int i;
    for (i = 0; i < numberElements; i++)
    {
        printf("%d ", inputArrayTypeInt[i]);
    }
    printf("\n");
}

/// Функция принимает три массива и количество элементов в первом и втором массиве. Складывает первый и второй массив, записывает результат в третий. Ничего не возвращает.
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
