#include <stdio.h> /// ����������� ���������� �����-������.
#include <locale.h> /// ���������� ��� ����������� ������.
#include <conio.h> /// ���������� ��� ������� �����-������.
#include <stdlib.h> /// ����������� ����������.
#include <time.h> /// ���������� ��� ������ �� ��������.

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

int main ()
{
    setlocale(LC_ALL, "Rus"); /// ���������� ������� ����.
    srand(time(NULL)); /// ���� ��� ������������.
    //====================================================================================================
    /// ���������� ����������.
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
        printf("1. (exercise 4) �������� ��������� ���������� ����� ����������� �����,\n");
        printf("� ���������� ������ ������� ��� ������ ����, ������� �������, ������������\n");
        printf("������� ������ ���� � �����.\n");
        printf("2. (exercise 9) �������� �������, ������� ������� �� ����� ������, ��������� ��\n");
        printf("���������. ����� ������ (���������� ���������) �������� ���������� �������.\n");
        printf("3. (exercise 14) �������� �������, ������� ���������� ����������� 2 �������.\n");
        printf("����������� ������� ������ ���� ��� ������� � ������, � �������\n");
        printf("������������ ���������.\n");
        printf("4. Exit\n");
        printf("=============================================================================\n");
        variableForMenu = getch();
        system("cls");
        if (variableForMenu == '1')
        {
            printf("������� �������� 3-� ������� �����: \n");
            printf("��: ");
            scanf("%d", &from);
            printf("��: ");
            scanf("%d", &to);
            summ = summNumbers(from, to);
            printf("����� ����� � ������� ��� ������ ���� � ��������� �� %d �� %d = %d \n", from, to, summ);
            system("pause");
            system("cls");
        }
        if (variableForMenu == '2')
        {
            printf("������� ������: ");
            scanf(" %c", &character); /// ���� �� ������ ������ ����� ��������������, �� ��������� ������.
            printf("������� ���-��: ");
            scanf("%d", &numberCharacters);
            printf("������ ��������: ");
            printChar(numberCharacters, character);
            system("pause");
            system("cls");
        }
        if (variableForMenu == '3')
        {
            printf("�������� ���������� ��������� ������� �������: ");
            scanf("%d", &numberElementsFirstArray);
            pFirstDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsFirstArray);
            fillArrayTypeIntRandomNumbers(pFirstDynamicArrayTypeInt, numberElementsFirstArray);
            printf("������ ������: ");
            printArrayTypeInt(pFirstDynamicArrayTypeInt, numberElementsFirstArray);
            printf("�������� ���������� ��������� ������� �������: ");
            scanf("%d", &numberElementsSecondArray);
            pSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsSecondArray);
            fillArrayTypeIntRandomNumbers(pSecondDynamicArrayTypeInt, numberElementsSecondArray);
            printf("������ ������: ");
            printArrayTypeInt(pSecondDynamicArrayTypeInt, numberElementsSecondArray);
            if(numberElementsFirstArray > numberElementsSecondArray) /// ���� ���������� ��������� ������� ������� ������ ��� ������� ���������
            {
                pSummFirstAndSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsFirstArray); /// �������� ������ ��� ����� ��������
                numberElementsSummFirstAndSecondArrays = numberElementsFirstArray; /// ��������� ���������� ���-�� ��������� ����� ��������
            }
            else if (numberElementsSecondArray > numberElementsFirstArray) /// ���� ���������� ��������� ������� ������� ������ ��� ������� ���������
            {
                pSummFirstAndSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsSecondArray); /// �������� ������ ��� ����� ��������
                numberElementsSummFirstAndSecondArrays = numberElementsSecondArray; /// ��������� ���������� ���-�� ��������� ����� ��������
            }
            else if (numberElementsFirstArray == numberElementsSecondArray) /// ���� ���������� ��������� ������� � ������� ������� ����� ���������
            {
                pSummFirstAndSecondDynamicArrayTypeInt = mallocForArrayTypeInt(numberElementsFirstArray); /// �������� ������ ��� ����� ��������
                numberElementsSummFirstAndSecondArrays = numberElementsFirstArray; /// ��������� ���������� ���-�� ��������� ����� ��������
            }
            summTwoArraysTypeInt(pFirstDynamicArrayTypeInt, numberElementsFirstArray, pSecondDynamicArrayTypeInt, numberElementsSecondArray, pSummFirstAndSecondDynamicArrayTypeInt);
            printf("����� ���� ��������: ");
            printArrayTypeInt(pSummFirstAndSecondDynamicArrayTypeInt, numberElementsSummFirstAndSecondArrays);
            free(pFirstDynamicArrayTypeInt); /// �������� ������ ������� �������
            pFirstDynamicArrayTypeInt = NULL; /// �������� ������
            free(pSecondDynamicArrayTypeInt); /// �������� ������ ������� �������
            pSecondDynamicArrayTypeInt = NULL; /// �������� ������
            free(pSummFirstAndSecondDynamicArrayTypeInt); /// �������� ������ ����� ��������
            pSummFirstAndSecondDynamicArrayTypeInt = NULL; /// �������� ������
            system("pause");
            system("cls");
        }
    }
    return 0;
}
