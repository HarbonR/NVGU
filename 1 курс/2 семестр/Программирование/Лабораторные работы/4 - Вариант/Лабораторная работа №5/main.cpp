#include <stdio.h> /// Стандартная библиотека ввода-вывода.
#include <locale.h> /// Библиотека для локализации языков.
#include <conio.h> /// Библиотека для функций ввода-вывода.
#include <stdlib.h> /// Стандартная библиотека.
#include <time.h> /// Библиотека для работы со временем.

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

int main ()
{
    setlocale(LC_ALL, "Rus"); /// Локализуем русский язык.
    srand(time(NULL)); /// Ключ для рандомайзера.
    //====================================================================================================
    /// Глобальные переменные.
    char variableForMenu = '0';
    int summ;
    int from, to;
    int numberCharacters;
    char character;
    int numberElementsFirstArray;
    int numberElementsSecondArray;
    int *pFirstDynamicArrayTypeInt = NULL;
    int *pSecondDynamicArrayTypeInt = NULL;
    int *pSummFirstAndSecondDynamicArrayTypeInt = NULL;
    int numberElementsSummFirstAndSecondArrays;
    //====================================================================================================
    while (variableForMenu != '4')
    {
        printf("==============================Laboratory Work 5==============================\n");
        printf("1. (exercise 4) Создайте программу вычисления суммы трехзначных чисел,\n");
        printf("в десятичной записи которых нет четных цифр, оформив функцию, определяющую\n");
        printf("наличие четных цифр в числе.\n");
        printf("2. (exercise 9) Написать функцию, которая выводит на экран строку, состоящую из\n");
        printf("звездочек. Длина строки (количество звездочек) является параметром функции.\n");
        printf("3. (exercise 14) Написать функцию, которая складывает поэлементно 2 массива.\n");
        printf("Параметрами функции должны быть оба массива и массив, в который\n");
        printf("записывается результат.\n");
        printf("4. Exit\n");
        printf("=============================================================================\n");
        variableForMenu = getch();
        system("cls");
        if (variableForMenu == '1')
        {
            printf("Введите диапозон 3-х значных чисел: \n");
            printf("От: ");
            scanf("%d", &from);
            printf("До: ");
            scanf("%d", &to);
            summ = summNumbers(from, to);
            printf("Сумма чисел в которых нет четных цифр в диапозоне от %d до %d = %d \n", from, to, summ);
            system("pause");
            system("cls");
        }
        if (variableForMenu == '2')
        {
            printf("Введите символ: ");
            scanf(" %c", &character); /// Если не ввести пробел перед спецификатором, не считывает символ.
            printf("Введите кол-во: ");
            scanf("%d", &numberCharacters);
            printf("Строка символов: ");
            printChar(numberCharacters, character);
            system("pause");
            system("cls");
        }
        if (variableForMenu == '3')
        {
            printf("Введтите количество элементов первого массива: ");
            scanf("%d", &numberElementsFirstArray);
            pFirstDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsFirstArray);
            fillArrayTypeIntRandomNumbers(pFirstDynamicArrayTypeInt, numberElementsFirstArray);
            printf("Первый массив: ");
            printArrayTypeInt(pFirstDynamicArrayTypeInt, numberElementsFirstArray);
            printf("Введтите количество элементов второго массива: ");
            scanf("%d", &numberElementsSecondArray);
            pSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsSecondArray);
            fillArrayTypeIntRandomNumbers(pSecondDynamicArrayTypeInt, numberElementsSecondArray);
            printf("Второй массив: ");
            printArrayTypeInt(pSecondDynamicArrayTypeInt, numberElementsSecondArray);
            if(numberElementsFirstArray > numberElementsSecondArray) /// Если количество элементов первого массива больше чем второго выполнять
            {
                pSummFirstAndSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsFirstArray); /// Выделить память под сумму массивов
                numberElementsSummFirstAndSecondArrays = numberElementsFirstArray; /// Присвоить переменной кол-во элементов суммы массивов
            }
            else if (numberElementsSecondArray > numberElementsFirstArray) /// Если количество элементов второго массива больше чем первого выполнять
            {
                pSummFirstAndSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsSecondArray); /// Выделить память под сумму массивов
                numberElementsSummFirstAndSecondArrays = numberElementsSecondArray; /// Присвоить переменной кол-во элементов суммы массивов
            }
            else if (numberElementsFirstArray == numberElementsSecondArray) /// Если количество элементов первого и второго массива равны выполнять
            {
                pSummFirstAndSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsFirstArray); /// Выделить память под сумму массивов
                numberElementsSummFirstAndSecondArrays = numberElementsFirstArray; /// Присвоить переменной кол-во элементов суммы массивов
            }
            summTwoArraysTypeInt(pFirstDynamicArrayTypeInt, numberElementsFirstArray, pSecondDynamicArrayTypeInt, numberElementsSecondArray, pSummFirstAndSecondDynamicArrayTypeInt);
            printf("Сумма двух массивов: ");
            printArrayTypeInt(pSummFirstAndSecondDynamicArrayTypeInt, numberElementsSummFirstAndSecondArrays);
            free(pFirstDynamicArrayTypeInt); /// Отчищаем память первого массива
            pFirstDynamicArrayTypeInt = NULL; /// Отчищаем ссылку
            free(pSecondDynamicArrayTypeInt); /// Отчищаем память второго массива
            pSecondDynamicArrayTypeInt = NULL; /// Отчищаем ссылку
            free(pSummFirstAndSecondDynamicArrayTypeInt); /// Отчищаем память суммы массивов
            pSummFirstAndSecondDynamicArrayTypeInt = NULL; /// Отчищаем ссылку
            system("pause");
            system("cls");
        }
    }
    return 0;
}
