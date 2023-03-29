#include <stdio.h> /// ���������� ����� ������
#include <stdlib.h> /// ����������� ����������
#include <time.h> /// ���������� ��� ������ �� ��������
#define width 20 /// ������ ����
#define height 7 /// ������ ����

/// ������� ��������� ���������� ������ � ������. ��������� ���������� ������. ������ �� ����������.
void fillPlayingField (char inputPlayingField[width][height], char *inputPlayingFieldBoundarySymbol)
{
    int i,j;
    for (i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1)
                inputPlayingField[j][i] = *inputPlayingFieldBoundarySymbol;
            else if (j == 0 || j == width - 1)
                inputPlayingField[j][i] = *inputPlayingFieldBoundarySymbol;
            else
                inputPlayingField[j][i] = ' ';

        }
    }
}

/// ������� ��������� ���������� ������. ������� ���������� ������ � �������. ������ �� ����������.
void printPlayingField (char inputPlayingField[width][height], int *inputCounter)
{
    int i,j;
    for (i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
            printf("%c", inputPlayingField[j][i]);
        printf("\n");
    }
    printf("Count: %d\n", *inputCounter);
    printf("Press e to exit");
}

/// ������� ��������� ���������� ������ � ������. ���������� ������ �� ����������� �������. ������ �� ����������.
char playerCharacterMovement (char inputPlayingField[width][height], char *inputGameCharacter, int *inputGameCharacterX, int *inputGameCharacterY)
{
    char variableForFunctionGetch; /// ���������� ������ ������ ��������� � ����������.
    variableForFunctionGetch = getch(); /// ���������� ������������� ������ �������� � ����������.
    if (variableForFunctionGetch == 'w') /// ���������� ������ ����� �� 1
    {
        inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = ' ';
        *inputGameCharacterY -= 1;
        if (*inputGameCharacterY == 0)
        {
            *inputGameCharacterY += 1;
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
        }
        else
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
    }
    else if (variableForFunctionGetch == 's') /// ���������� ������ ���� �� 1
    {
        inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = ' ';
        *inputGameCharacterY += 1;
        if (*inputGameCharacterY == height - 1)
        {
            *inputGameCharacterY -= 1;
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
        }
        else
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
    }
    else if (variableForFunctionGetch == 'a') /// ���������� ������ ����� �� 1
    {
        inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = ' ';
        *inputGameCharacterX -= 1;
        if (*inputGameCharacterX == 0)
        {
            *inputGameCharacterX += 1;
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
        }
        else
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
    }
    else if (variableForFunctionGetch == 'd') /// ���������� ������ ������ �� 1
    {
        inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = ' ';
        *inputGameCharacterX += 1;
        if (*inputGameCharacterX == width - 1)
        {
            *inputGameCharacterX -= 1;
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
        }
        else
            inputPlayingField[*inputGameCharacterX][*inputGameCharacterY] = *inputGameCharacter;
    }
    return variableForFunctionGetch;
}

/// ������� ��������� ����������� ������ � ������. �������� ������ � ���������� ����� � �������. ������ �� ����������.
void randomFillPlayingFieldSymbol (char inputPlayingField[width][height], char *inputPlayingSymbol, int *inputPlayingSymbolX, int *inputPlayingSymbolY)
{
    srand(time(NULL)); /// ��������� ��������� �����.
    *inputPlayingSymbolX = rand() % (width - 2) + 1;
    *inputPlayingSymbolY = rand() % (height - 2) + 1;
    inputPlayingField[*inputPlayingSymbolX][*inputPlayingSymbolY] = *inputPlayingSymbol;
}

main()
{
    char menu; /// ��������� ���������� ��� ����
    char playingFieldBoundarySymbol = '@'; /// ������ ������ �������� ����.
    char gameCharacter = '@'; /// ������� ��������.
    char playingSymbol = '*'; /// ������� ������ (������� �������).
    while (menu != '5')
    {
        system("cls");
        printf("==================Menu==================\n1. Play\n2. Select playing field boundary symbol\n3. Select game character\n4. Select playing symbol\n5. Exit\n=========================================");
        menu = getch();
        system("cls");
        if (menu == '1')
        {
            //===============================VARIABLE===============================
            char playingField[width][height]; /// ��������� ���������� ������.
            char *pPlayingFieldBoundarySymbol = playingFieldBoundarySymbol; /// ������ �� ���������� "������ ������ �������� ����".
            char *pGameCharacter = &gameCharacter; /// ������ �� ���������� "������� ��������".
            int gameCharacterX = (int)width/2; /// ��������� ���������� "������� ��������" �� ���������� X
            int *pGameCharacterX = &gameCharacterX; /// ������ �� ���������� "������� ��������" �� ���������� X.
            int gameCharacterY = (int)height/2; /// ��������� ���������� "������� ��������" �� ���������� Y
            int *pGameCharacterY = &gameCharacterY; /// ������ �� ���������� "������� ��������" �� ���������� Y.
            char *pPlayingSymbol = &playingSymbol; /// ������ �� ���������� "������� ������".
            int playingSymbolX; /// ��������� ���������� "������� ������" �� ���������� X.
            int *pPlayingSymbolX = &playingSymbolX; /// ������ �� ���������� "������� ������" �� ���������� X.
            int playingSymbolY; /// ��������� ���������� "������� ������" �� ���������� Y.
            int *pPlayingSymbolY = &playingSymbolY; /// ������ �� ���������� "������� ������" �� ���������� Y.
            int counter = 0; /// ������� ���������� "������� ������".
            int *pCounter = &counter; /// ������ �� ���������� "������� ����������: ������� ������".
            char exit = '?';
            //======================================================================
            fillPlayingField(playingField, &pPlayingFieldBoundarySymbol); /// ��������� ���������� ������.
            playingField[(int)width/2][(int)height/2] = gameCharacter; /// �������� �������� ��������� � ����� �������� ����.
            randomFillPlayingFieldSymbol(playingField, pPlayingSymbol, pPlayingSymbolX, pPlayingSymbolY); /// �������� ������ � ���������� ����� � �������.
            printPlayingField(playingField, pCounter); /// ������� ���������� ������ � �������.
            while (exit != 'e')
            {
                exit = playerCharacterMovement(playingField, pGameCharacter, pGameCharacterX, pGameCharacterY); /// ���������� �������� ��������� �� �������� ����.
                if (gameCharacterX == playingSymbolX && gameCharacterY == playingSymbolY)
                {
                    counter++;
                    randomFillPlayingFieldSymbol(playingField, pPlayingSymbol, pPlayingSymbolX, pPlayingSymbolY);
                }
                system("cls");
                printPlayingField(playingField, pCounter); /// ������� ���������� ������ � �������.
            }
        }
        else if (menu == '2')
        {
           printf("Select playing field boundary symbol: ");
           scanf(" %c", &playingFieldBoundarySymbol);
        }
        else if (menu == '3')
        {
            printf("Select game character: ");
            scanf(" %c", &gameCharacter);
        }
        else if (menu == '4')
        {
            printf("Select playing symbol: ");
            scanf(" %c", &playingSymbol);
        }
    }
    return 0;
}
