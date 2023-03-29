#include <stdio.h> /// Библиотека ввода вывода
#include <stdlib.h> /// Стандартная библиотека
#include <time.h> /// Библиотека для работы со временем
#define width 20 /// Ширина поля
#define height 7 /// Высота поля

/// Функция принимает двухмерный массив и ссылку. Заполняет двухмерный массив. Ничего не возвращает.
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

/// Функция принимает двухмерный массив. Выводит двухмерный массив в консоль. Ничего не возвращает.
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

/// Функция принимает двухмерный массив и ссылки. Перемещает символ по двухмерному массиву. Ничего не возвращает.
char playerCharacterMovement (char inputPlayingField[width][height], char *inputGameCharacter, int *inputGameCharacterX, int *inputGameCharacterY)
{
    char variableForFunctionGetch; /// Переменная хранит символ введенный с клавиатуры.
    variableForFunctionGetch = getch(); /// Переменной присваивается символ введённый с клавиатуры.
    if (variableForFunctionGetch == 'w') /// Перемещает символ вверх на 1
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
    else if (variableForFunctionGetch == 's') /// Перемещает символ вниз на 1
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
    else if (variableForFunctionGetch == 'a') /// Перемещает символ влево на 1
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
    else if (variableForFunctionGetch == 'd') /// Перемещает символ вправо на 1
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

/// Функция принимает двуухмерный массив и ссылки. Помещает символ в рандомныом месте в массиве. Ничего не возвращает.
void randomFillPlayingFieldSymbol (char inputPlayingField[width][height], char *inputPlayingSymbol, int *inputPlayingSymbolX, int *inputPlayingSymbolY)
{
    srand(time(NULL)); /// Генератор случайных чисел.
    *inputPlayingSymbolX = rand() % (width - 2) + 1;
    *inputPlayingSymbolY = rand() % (height - 2) + 1;
    inputPlayingField[*inputPlayingSymbolX][*inputPlayingSymbolY] = *inputPlayingSymbol;
}

main()
{
    char menu; /// Объявляем переменную для меню
    char playingFieldBoundarySymbol = '@'; /// Символ границ игрового поля.
    char gameCharacter = '@'; /// Игровой персонаж.
    char playingSymbol = '*'; /// Игровой символ (Игровая монетка).
    while (menu != '5')
    {
        system("cls");
        printf("==================Menu==================\n1. Play\n2. Select playing field boundary symbol\n3. Select game character\n4. Select playing symbol\n5. Exit\n=========================================");
        menu = getch();
        system("cls");
        if (menu == '1')
        {
            //===============================VARIABLE===============================
            char playingField[width][height]; /// Объявляем двухмерный массив.
            char *pPlayingFieldBoundarySymbol = playingFieldBoundarySymbol; /// Ссылка на переменную "Символ границ игрового поля".
            char *pGameCharacter = &gameCharacter; /// Ссылка на переменную "Игровой персонаж".
            int gameCharacterX = (int)width/2; /// Объявляем переменную "Игровой персонаж" по координате X
            int *pGameCharacterX = &gameCharacterX; /// Ссылка на переменную "Игровой персонаж" по координате X.
            int gameCharacterY = (int)height/2; /// Объявляем переменную "Игровой персонаж" по координате Y
            int *pGameCharacterY = &gameCharacterY; /// Ссылка на переменную "Игровой персонаж" по координате Y.
            char *pPlayingSymbol = &playingSymbol; /// Ссылка на переменную "Игровой символ".
            int playingSymbolX; /// Объявляем переменную "Игровой символ" по координате X.
            int *pPlayingSymbolX = &playingSymbolX; /// Ссылка на переменную "Игровой символ" по координате X.
            int playingSymbolY; /// Объявляем переменную "Игровой символ" по координате Y.
            int *pPlayingSymbolY = &playingSymbolY; /// Ссылка на переменную "Игровой символ" по координате Y.
            int counter = 0; /// Счетчик переменной "Игровой символ".
            int *pCounter = &counter; /// Ссылка на переменную "Счетчик переменной: игровой символ".
            char exit = '?';
            //======================================================================
            fillPlayingField(playingField, &pPlayingFieldBoundarySymbol); /// Заполняет двухмерный массив.
            playingField[(int)width/2][(int)height/2] = gameCharacter; /// Помещаем игрового персонажа в центр игрового поля.
            randomFillPlayingFieldSymbol(playingField, pPlayingSymbol, pPlayingSymbolX, pPlayingSymbolY); /// Помещает символ в рандомныом месте в массиве.
            printPlayingField(playingField, pCounter); /// Выводит двухмерный массив в консоль.
            while (exit != 'e')
            {
                exit = playerCharacterMovement(playingField, pGameCharacter, pGameCharacterX, pGameCharacterY); /// Перемещает игрового персонажа по игровому полю.
                if (gameCharacterX == playingSymbolX && gameCharacterY == playingSymbolY)
                {
                    counter++;
                    randomFillPlayingFieldSymbol(playingField, pPlayingSymbol, pPlayingSymbolX, pPlayingSymbolY);
                }
                system("cls");
                printPlayingField(playingField, pCounter); /// Выводит двухмерный массив в консоль.
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
