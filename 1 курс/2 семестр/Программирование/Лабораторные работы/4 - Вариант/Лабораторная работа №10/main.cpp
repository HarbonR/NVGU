#include <stdio.h> /// ����������� ���������� �����-������.
#include <locale.h> /// ���������� ��� ����������� ������.
#include <conio.h> /// ���������� ��� ������� �����-������.
#include <stdlib.h> /// ����������� ����������.
#include <time.h> /// ���������� ��� ������ �� ��������.
#include "myMod.h"

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
