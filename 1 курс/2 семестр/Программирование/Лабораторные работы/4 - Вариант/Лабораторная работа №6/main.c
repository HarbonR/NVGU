#include <stdio.h> /// ���������� ����� ������
#include <stdlib.h> /// ����������� ����������
#include <locale.h> /// ���������� ��� �����������
#include <time.h> /// ���������� ��� ������ �� ��������
#define lengthArrayChar 5

/// ������� ��������� ������. ��������� ������ ���������� ������� �� 0 �� 9. ������ �� ����������.
void fillStringDigits (char inputArrayChar[lengthArrayChar])
{
    srand(time(NULL)); /// ��������� ��������� �����
    int i;
    char arrayIntChar[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char variableChar;
    for(i = 0; i < lengthArrayChar; i++)
    {
        variableChar = arrayIntChar[rand() % 10];
        inputArrayChar[i] = variableChar;
    }
}

/// ������� ��������� ������. ������� ������ � �������. ������ �� ����������.
void printString (char inputArrayChar[lengthArrayChar])
{
    int i;
    for (i = 0; i < lengthArrayChar; i++)
        printf("%c ", inputArrayChar[i]);
}

/// ������� ��������� ������ � ������. �������������� ������������ ������ �� �������������� ���������� �� ������� ��������. ������� ������ � �������. ������ �� ����������.
void set (char inputArrayChar[lengthArrayChar], char *inputDynamicArrayChar)
{
    int i,j,k; /// ���������� ��� ������
    int variableBool; /// ���������� Bool
    int counter = 0; /// ������� ��� �������� ���������� �� ������������� �������� � ������� ��������
    char variableChar; /// ���������� ��� �������� ��������� �������� ������� ��������
    //====================================================================================
    ///������� ���������� �� ������������� �������� � ������� ��������
    for (i = 0; i < lengthArrayChar; i++)
    {
        variableBool = 0; /// false
        variableChar = inputArrayChar[i];
        for(j = i+1; j < lengthArrayChar; j++)
        {
            if(inputArrayChar[i] == inputArrayChar[j])
            {
                variableBool = 1; /// true
                break; /// ����� �� �����
            }
        }
        if(variableBool == 0)
            counter++;
    }
    //====================================================================================
    inputDynamicArrayChar = malloc(counter * sizeof(char)); /// �������� ������ ��� ������������� �������
    k = 0; /// �������� ����������
    //====================================================================================
    /// �������������� ������������ ������ �� �������������� ���������� �� ������� ��������
    for (i = 0; i < lengthArrayChar; i++)
    {
        variableBool = 0; /// false
        variableChar = inputArrayChar[i];
        for(j = i+1; j < lengthArrayChar; j++)
        {
            if(inputArrayChar[i] == inputArrayChar[j])
            {
                variableBool = 1; /// true
                break; /// ����� �� �����
            }
        }
        if(variableBool == 0)
        {
            inputDynamicArrayChar[k] = inputArrayChar[i];
            k++;
        }
    }
    //====================================================================================
    /// ������� ������������ ������ � �������
    for (i = 0; i < counter; i++)
        printf("%c ", *(inputDynamicArrayChar + i));
    free(inputDynamicArrayChar); /// ����������� ������ ���������� ��� ������������ ������
}

/// ������� ��������� ������. ��������� ������ ���������� ���������. ������ �� ����������.
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

/// ������� ��������� ������. ���������� ����� � ������� ��������. ���������� �����.
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

/// ������� ��������� ������ � ������. ������� ������� ����� �������� ����� �������. ���������� ����������.
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
        printf("\n���������� �������� � ������ �� ������� '%c' = %d\n", inputChar, number);
    }
    else
        printf("\n� ������ ��� ������� '%c'\n", inputChar);

}

/// ������� ��������� ������. ������� � ������� ����� ��������� ���� � ������ ������ �������� ��� ���������. ������ �� ����������.
void numberSmallBigLetters (char inputArrayCharacter[])
{
    int i, j, k;
    int numberSmallLetters = 0;
    char arraySmallLetters[26]; /// ������ ����� ������� �������� ���������� �����
    short variableForArraySmallLetters = 97; /// ����� ������� 'a' � �������
    int numberBigLetters = 0;
    char arrayBigLetters[26]; /// ������ ����� ������� ��������� ���������� �����
    short variableForArrayBigLetters = 65; /// ����� ������� 'A' � �������
    /// ��������� ������ ��������� ����������� �������
    for (j = 0; j < 26; j++)
    {
        arraySmallLetters[j] = (char)variableForArraySmallLetters;
        variableForArraySmallLetters++;

    }
    /// ��������� ������ ���������� ����������� �������
    for (k = 0; k < 26; k++)
    {
        arrayBigLetters[k] = (char)variableForArrayBigLetters;
        variableForArrayBigLetters++;
    }
    /// ������������ ����� �������� � ��������� ���� � ������
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
        printf("�������� ���� %d < %d ���������", numberSmallLetters, numberBigLetters);
    else if (numberSmallLetters > numberBigLetters)
        printf("�������� ���� %d > %d ���������", numberSmallLetters, numberBigLetters);
    else if (numberSmallLetters == numberBigLetters)
        printf("�������� ���� %d = %d ���������", numberSmallLetters, numberBigLetters);
}

/// ������� ��������� ������ � ������. �������������� ������������ ������ �� �������������� ���������� �� ������� ��������. ��������� ������. ������� ������ � �������. ������ �� ����������.
void removeIdentionalCharacters (char inputArrayChar[], char *inputDynamicArrayChar)
{
    int i,j,k; /// ���������� ��� ������
    int variableBool; /// ���������� Bool
    int counter = 0; /// ������� ��� �������� ���������� �� ������������� �������� � ������� ��������
    char variableChar; /// ���������� ��� �������� ��������� �������� ������� ��������
    //====================================================================================
    ///������� ���������� �� ������������� �������� � ������� ��������
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
                break; /// ����� �� �����
                }
            }
            if(variableBool == 0)
                counter++;
        }
    }
    //====================================================================================
    inputDynamicArrayChar = malloc(counter * sizeof(char)); /// �������� ������ ��� ������������� �������
    k = 0; /// �������� ����������
    //====================================================================================
    /// �������������� ������������ ������ �� �������������� ���������� �� ������� ��������
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
                    break; /// ����� �� �����
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
    /// ��������� ������������ ������ �� �����������
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
    /// ������� ������������ ������ � �������
    for (i = 0; i < counter; i++)
        printf("%c ", *(inputDynamicArrayChar + i));
    free(inputDynamicArrayChar); /// ����������� ������ ���������� ��� ������������ ������
}

/// ������� ��������� ������ � ������.
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
    inputDynamicArrayChar = malloc(counter * sizeof(char)); /// �������� ������ ��� ������������� �������
    j = 0; /// �������� ����������
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
    /// ������� ������������ ������ � �������
    for (i = 0; i < counter; i++)
        printf("%c", *(inputDynamicArrayChar + i));
    free(inputDynamicArrayChar); /// ����������� ������ ���������� ��� ������������ ������
}

main()
{
    setlocale(LC_ALL, "Rus"); /// ���������� ���.
    char stringDigits[lengthArrayChar]; /// ��������� ������ ��������.
    char *dynamicArray; /// ��������� ������ �� ������������ ������.
    char stringCharacters[lengthArrayChar]; /// ������ ��������.
    int summDigits; /// ��������� ���������� "����� ���� � ������� ��������".
    char stringCharacter[] = "cba ed c ba";
    char ch = ':';
    fillStringDigits(stringDigits); /// ��������� ������ ���������� �������
    printf("�������� ������ ����: ");
    printString(stringDigits);
    printf("\n���������� ������: ");
    set(stringDigits, dynamicArray);
    fillStringCharacters(stringCharacters); /// ��������� ������ �������� ���������� ���������.
    printf("\n�������� ������ ��������: ");
    printString(stringCharacters);
    summDigits = sumDigitsInString(stringCharacters);
    printf("\n����� ���� � ������� ��������: %d", summDigits);
    numberOfCharactersToCharacter(stringCharacter, ch);
    numberSmallBigLetters(stringCharacter);
    printf("\n��������� ������: ");
    removeIdentionalCharacters(stringCharacter, stringCharacter); /// ������� ���������� ������� � ������. ��������� ������. ������� ������ � �������.
    printf("\n��������� ������: ");
    doubleSpacesInString(stringCharacter, dynamicArray);
    return 0;
}
