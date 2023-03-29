#include <stdio.h> /// Библиотека ввода вывода
#include <stdlib.h> /// Стандартная библиотека
#include <locale.h> /// Библиотека для локализации
#include <time.h> /// Библиотека для работы со временем
#define lengthArrayChar 5

/// Функция принимает массив. Заполняет массив рандомными числами от 0 до 9. Ничего не возвращает.
void fillStringDigits (char inputArrayChar[lengthArrayChar])
{
    srand(time(NULL)); /// Генератор случайных чисел
    int i;
    char arrayIntChar[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char variableChar;
    for(i = 0; i < lengthArrayChar; i++)
    {
        variableChar = arrayIntChar[rand() % 10];
        inputArrayChar[i] = variableChar;
    }
}

/// Функция принимает массив. Выводит массив в консоль. Ничего не возвращает.
void printString (char inputArrayChar[lengthArrayChar])
{
    int i;
    for (i = 0; i < lengthArrayChar; i++)
        printf("%c ", inputArrayChar[i]);
}

/// Функция принимает массив и ссылку. Инициализирует динамический массив не повторяющимися значениями из массива символов. Выводит массив в консоль. Ничего не возвращает.
void set (char inputArrayChar[lengthArrayChar], char *inputDynamicArrayChar)
{
    int i,j,k; /// Переменные для циклов
    int variableBool; /// Переменная Bool
    int counter = 0; /// Счётчик для подсчета количества не повтяряющихся символов в массиве символов
    char variableChar; /// Переменная для хранения временных символов массива символов
    //====================================================================================
    ///Считает количество не повтяряющихся символов в массиве символов
    for (i = 0; i < lengthArrayChar; i++)
    {
        variableBool = 0; /// false
        variableChar = inputArrayChar[i];
        for(j = i+1; j < lengthArrayChar; j++)
        {
            if(inputArrayChar[i] == inputArrayChar[j])
            {
                variableBool = 1; /// true
                break; /// Выход из цикла
            }
        }
        if(variableBool == 0)
            counter++;
    }
    //====================================================================================
    inputDynamicArrayChar = malloc(counter * sizeof(char)); /// Выделяет память для динамического массива
    k = 0; /// Обнуляем переменную
    //====================================================================================
    /// Инициализирует динамический массив не повторяющимися значениями из массива символов
    for (i = 0; i < lengthArrayChar; i++)
    {
        variableBool = 0; /// false
        variableChar = inputArrayChar[i];
        for(j = i+1; j < lengthArrayChar; j++)
        {
            if(inputArrayChar[i] == inputArrayChar[j])
            {
                variableBool = 1; /// true
                break; /// Выход из цикла
            }
        }
        if(variableBool == 0)
        {
            inputDynamicArrayChar[k] = inputArrayChar[i];
            k++;
        }
    }
    //====================================================================================
    /// Выводим динамический массив в консоль
    for (i = 0; i < counter; i++)
        printf("%c ", *(inputDynamicArrayChar + i));
    free(inputDynamicArrayChar); /// Освобождаем память выделенную под динамический массив
}

/// Функция принимает массив. Заполняет массив рандомными символами. Ничего не возвращает.
void fillStringCharacters (char inputStringCharacters[lengthArrayChar])
{
    srand(time(NULL));
    int i;
    char arrayCharacters[] = {'0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','^','&','*','(',')','_','+','=','-'};
    char varibalChar;
    int lengthArrayCharacters = (sizeof(arrayCharacters) / sizeof(char))-1;
    for (i = 0; i < lengthArrayChar; i++)
    {
        varibalChar = arrayCharacters[rand() % lengthArrayCharacters];
        inputStringCharacters[i] = varibalChar;
    }
}

/// Функция принимает массив. Складывает цифры в массиве символов. Возвращает сумму.
int sumDigitsInString (char inputStringCharacters[lengthArrayChar])
{
    int i;
    int summDigits = 0;
    for (i = 0; i < lengthArrayChar; i++)
    {
        switch (inputStringCharacters[i])
        {
            case '0' : summDigits += 0; break;
            case '1' : summDigits += 1; break;
            case '2' : summDigits += 2; break;
            case '3' : summDigits += 3; break;
            case '4' : summDigits += 4; break;
            case '5' : summDigits += 5; break;
            case '6' : summDigits += 6; break;
            case '7' : summDigits += 7; break;
            case '8' : summDigits += 8; break;
            case '9' : summDigits += 9; break;
        }
    }
    return summDigits;
}

/// Функция принимает массив и символ. Считает сколько стоит символов после символа. Возвращает количество.
void numberOfCharactersToCharacter (char inputArrayCharacter[], char inputChar)
{
    int i;
    int number = 0;
    short variableBool = 0; /// false
    for (i = 0; inputArrayCharacter[i] != '\0'; i++)
    {
        if (inputArrayCharacter[i] == inputChar)
        {
            variableBool = 1; /// true
            break;
        }
    }
    if (variableBool == 1)
    {
        for (i = 0; inputArrayCharacter[i] != '\0'; i++)
        {
            if (inputArrayCharacter[i] == inputChar)
                break;
            else
                number++;
        }
        printf("\nКоличество символов в строке до символа '%c' = %d\n", inputChar, number);
    }
    else
        printf("\nВ строке нет символа '%c'\n", inputChar);

}

/// Функция принимает массив. Выводит в консоль каких аглийских букв в строке больше строчных или заглавных. Ничего не возвращает.
void numberSmallBigLetters (char inputArrayCharacter[])
{
    int i, j, k;
    int numberSmallLetters = 0;
    char arraySmallLetters[26]; /// Массив будет хранить строчные английские буквы
    short variableForArraySmallLetters = 97; /// Номер символа 'a' в таблице
    int numberBigLetters = 0;
    char arrayBigLetters[26]; /// Массив будет хранить заглавные английские буквы
    short variableForArrayBigLetters = 65; /// Номер символа 'A' в таблице
    /// Заполняет массив строчными английскими буквами
    for (j = 0; j < 26; j++)
    {
        arraySmallLetters[j] = (char)variableForArraySmallLetters;
        variableForArraySmallLetters++;

    }
    /// Заполняет массив заглавными английскими буквами
    for (k = 0; k < 26; k++)
    {
        arrayBigLetters[k] = (char)variableForArrayBigLetters;
        variableForArrayBigLetters++;
    }
    /// Подсчитывает число строчных и заглавных букв в строке
    for (i = 0; inputArrayCharacter[i] != '\0'; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (inputArrayCharacter[i] == arraySmallLetters[j])
            {
                numberSmallLetters++;
                break;;
            }
        }
        for (k = 0; k < 26; k++)
        {
            if (inputArrayCharacter[i] == arrayBigLetters[k])
            {
                numberBigLetters++;
                break;
            }
        }
    }
    if (numberSmallLetters < numberBigLetters)
        printf("Строчных букв %d < %d заглавных", numberSmallLetters, numberBigLetters);
    else if (numberSmallLetters > numberBigLetters)
        printf("Строчных букв %d > %d заглавных", numberSmallLetters, numberBigLetters);
    else if (numberSmallLetters == numberBigLetters)
        printf("Строчных букв %d = %d заглавных", numberSmallLetters, numberBigLetters);
}

/// Функция принимает массив и ссылку. Инициализирует динамический массив не повторяющимися значениями из массива символов. Сортирует строку. Выводит строку в консоль. Ничего не возвращает.
void removeIdentionalCharacters (char inputArrayChar[], char *inputDynamicArrayChar)
{
    int i,j,k; /// Переменные для циклов
    int variableBool; /// Переменная Bool
    int counter = 0; /// Счётчик для подсчета количества не повтяряющихся символов в массиве символов
    char variableChar; /// Переменная для хранения временных символов массива символов
    //====================================================================================
    ///Считает количество не повтяряющихся символов в массиве символов
    for (i = 0; inputArrayChar[i] != '\0'; i++)
    {
        if (inputArrayChar[i] != ' ')
        {
            variableBool = 0; /// false
            variableChar = inputArrayChar[i];
            for(j = i+1; inputArrayChar[j] != '\0'; j++)
            {
                if(inputArrayChar[i] == inputArrayChar[j])
                {
                variableBool = 1; /// true
                break; /// Выход из цикла
                }
            }
            if(variableBool == 0)
                counter++;
        }
    }
    //====================================================================================
    inputDynamicArrayChar = malloc(counter * sizeof(char)); /// Выделяет память для динамического массива
    k = 0; /// Обнуляем переменную
    //====================================================================================
    /// Инициализирует динамический массив не повторяющимися значениями из массива символов
    for (i = 0; inputArrayChar[i] != '\0'; i++)
    {
        if (inputArrayChar[i] != ' ')
        {
            variableBool = 0; /// false
            variableChar = inputArrayChar[i];
            for(j = i+1; inputArrayChar[j] != '\0'; j++)
            {
                if(inputArrayChar[i] == inputArrayChar[j])
                {
                    variableBool = 1; /// true
                    break; /// Выход из цикла
                }
            }
            if(variableBool == 0)
            {
                inputDynamicArrayChar[k] = inputArrayChar[i];
                k++;
            }
        }
    }
    //====================================================================================
    /// Сортирует динамический массив по возрастанию
    for (i = 0; i < counter - 1; i++)
    {
        for (j = i + 1; j < counter; j++)
        {
            if (*(inputDynamicArrayChar + i) > *(inputDynamicArrayChar + j))
            {
                variableChar = *(inputDynamicArrayChar + i);
                *(inputDynamicArrayChar + i) = *(inputDynamicArrayChar + j);
                *(inputDynamicArrayChar + j) = variableChar;
            }
        }
    }
    //====================================================================================
    /// Выводим динамический массив в консоль
    for (i = 0; i < counter; i++)
        printf("%c ", *(inputDynamicArrayChar + i));
    free(inputDynamicArrayChar); /// Освобождаем память выделенную под динамический массив
}

/// Функция принимает массив и ссылку.
void doubleSpacesInString (char inputArrayChar[], char *inputDynamicArrayChar)
{
    int i,j;
    int counter = 0;
    //====================================================================================
    for (i = 0; inputArrayChar[i] != '\0'; i++)
    {
        if (inputArrayChar[i] == ' ')
            counter += 2;
        else
            counter++;
    }
    //====================================================================================
    inputDynamicArrayChar = malloc(counter * sizeof(char)); /// Выделяет память для динамического массива
    j = 0; /// Обнуляем переменную
    //====================================================================================
    for (i = 0; inputArrayChar[i] != '\0'; i++)
    {
        if (inputArrayChar[i] == ' ')
        {
            *(inputDynamicArrayChar + j) = inputArrayChar[i];
            j++;
            *(inputDynamicArrayChar + j) = ' ';
            j++;
        }
        else
        {
           *(inputDynamicArrayChar + j) = inputArrayChar[i];
            j++;
        }
    }
    //====================================================================================
    /// Выводим динамический массив в консоль
    for (i = 0; i < counter; i++)
        printf("%c", *(inputDynamicArrayChar + i));
    free(inputDynamicArrayChar); /// Освобождаем память выделенную под динамический массив
}

main()
{
    setlocale(LC_ALL, "Rus"); /// Локализуем код.
    char stringDigits[lengthArrayChar]; /// Объявляем массив символов.
    char *dynamicArray; /// Объявляем ссылку на динамический массив.
    char stringCharacters[lengthArrayChar]; /// Строка символов.
    int summDigits; /// Объявляем переменную "Сумма цифр в массиве символов".
    char stringCharacter[] = "cba ed c ba";
    char ch = ':';
    fillStringDigits(stringDigits); /// Заполняет строку рандомными числами
    printf("Исходный массив цифр: ");
    printString(stringDigits);
    printf("\nИзмененный массив: ");
    set(stringDigits, dynamicArray);
    fillStringCharacters(stringCharacters); /// Заполняет массив символов рандомными символами.
    printf("\nИсходный массив символов: ");
    printString(stringCharacters);
    summDigits = sumDigitsInString(stringCharacters);
    printf("\nСумма цифр в массиве символов: %d", summDigits);
    numberOfCharactersToCharacter(stringCharacter, ch);
    numberSmallBigLetters(stringCharacter);
    printf("\nИзменённая строка: ");
    removeIdentionalCharacters(stringCharacter, stringCharacter); /// Удаляет одинаковые символы в строке. Сортирует строку. Выводит строку в консоль.
    printf("\nИзменённая строка: ");
    doubleSpacesInString(stringCharacter, dynamicArray);
    return 0;
}
