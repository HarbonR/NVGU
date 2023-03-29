#include <iostream> /// ���������� �����-������ �++
#include <windows.h> /// ���������� ��� windown ������
#include <locale.h> /// ���������� ��� ����������� �����
#include <conio.h> /// ���������� � ��������� ��� �����-������
#include <time.h> /// ���������� ��� ������ �� ��������
#define height 20 /// ������
#define width 40 /// ������
#define timeSleep 400 /// �������� ��������

using namespace std; /// ���������� ������������ ����

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /// ���������� ��� ��������� �����
///SetConsoleTextAttribute(hConsole, ����������); /// ������� ��� ��������� �����

/// ��������� �����
typedef struct
{
    int x;
    int y;
}typePointer;

/// ��������� ���������� bool ���� ������ �� ����� ���������������
typedef struct
{
    bool booleanW;
    bool booleanS;
    bool booleanA;
    bool booleanD;
}typeBooleanMove;

char gameField[height][width]; /// ������ ������� ����
char charBordersGameField; /// ������ ������ �������� ����
typePointer snake; /// ����
char charHeadSnake; /// ������ ������ ����
char charTailSnake; /// ������ ������ ����
typePointer tailSnake[100]; /// ������ �������� ����� ������ ����
int indexTailSnake = 0; /// ������ ��� ������� ������
typeBooleanMove booleanMove; /// ���������� ���� typeBooleanMove ���� ������ �� ����� ���������������
typePointer variableApple; /// ������ ������� ��������� �������
char charApple; /// ������ �������
bool pause = true; /// ���������� ��� �����
int counter = 0; /// ���������� �����

/// ��������� ������� ����
void fillGameField (char inputCharBordersGameField)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1)
                gameField[i][j] = inputCharBordersGameField;
            else if (j == 0 || j == width - 1)
                gameField[i][j] = inputCharBordersGameField;
            else
                gameField[i][j] = ' ';
        }
    }
}

/// ������� ������� ���� � �������
void printGameField ()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == variableApple.x && i == variableApple.y)
            {
                SetConsoleTextAttribute(hConsole, 4); /// ���������� ���� ������� (�������)
                cout << gameField[i][j];
            }
            else if (i == 0 || i == height - 1)
            {
                SetConsoleTextAttribute(hConsole, 3); /// ���������� ���� �������� � ������� ���� (�������)
                cout << gameField[i][j];
            }
            else if (j == 0 || j == width - 1)
            {
                SetConsoleTextAttribute(hConsole, 3); /// ���������� ���� ������ � ������� ���� (�������)
                cout << gameField[i][j];
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 14); /// ���������� ��������� ���� [����] (�������)
                cout << gameField[i][j];
            }
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 15); /// ����������� ����� ����
    cout << "����: " << counter;

}

/// �������� ����������� ��������� ������� �� ������� ����
void apple ()
{
    variableApple.x = rand() % (width - 2) + 1;
    variableApple.y = rand() % (height -2) + 1;
}

/// ������ �������� ������
void moveSnake (typePointer inputSnake, char symbolSnake)
{
    char variableMove = '0'; /// ���������� ��� �������� ������� �������� � ������ �� ����
    gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// �������� ������ � ����� �������� ����
    apple(); /// ����������� ������� ��������� ��������� �� ������� ����
    gameField[variableApple.y][variableApple.x] = charApple; /// �������� ������� �� ������� ����
    printGameField(); /// ������� ������� ���� � �������
    while (variableMove != 'e')
    {
        pause = true; /// ����������� �������� true ����� �������� �����
        variableMove = _getch(); /// ������� ������ ������������� ���������� variableMove
        /// �������� �� ������� ������������
        if (booleanMove.booleanA == true && variableMove == 'd')
            variableMove = 'a';
        else if (booleanMove.booleanD == true && variableMove == 'a')
            variableMove = 'd';
        else if (booleanMove.booleanS == true && variableMove == 'w')
            variableMove = 's';
        else if (booleanMove.booleanW == true && variableMove == 's')
            variableMove = 'w';
        switch (variableMove)
        {
        //====================================================================================================
        case 'w' :
            while( !_kbhit() ) /// ���� ������ �� ������ ���������
            {
                /// ���������� ���������� �������� ��������� ���������� bool ���� ������ �� ����� ���������������
                booleanMove.booleanA = false;
                booleanMove.booleanD = false;
                booleanMove.booleanS = false;
                booleanMove.booleanW = true;
                /// ���� (indexTailSnake > 1) ������ ����� ������� �� ����� ��� 1 �������� ������. �������� ������� ������ ��������� �� 1 ������� � �������� �������.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// ���� (indexTailSnake > 0) ������ ����� ������� ������ �� 1 ��������. ��������� ��������� �������� ���� ���������� �������� ������.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                }
                inputSnake.y--; /// ������ �����
                /// �������� �� ������������ � �������
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// ������� ���� ���������� � �������
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    break;
                }
                /// �������� �� ������������ �� ������
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// ��������� ������� ����. �������� ������� ������� �������� ����
                gameField[variableApple.y][variableApple.x] = charApple; /// �������� ������� �� ������� ����
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// �������� ������ � ����� ����������
                /// ������� �����
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// �������� ������
                system("cls"); /// �������� �������
                /// ���� ���������� �������
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                    apple(); /// ����������� ������� ��������� ��������� �� ������� ����
                }
                printGameField(); /// ������� ������� ���� � �������
            }; break;
        //====================================================================================================
        case 's' :
            while( !_kbhit() ) /// ���� ������ �� ������ ���������
            {
                /// ���������� ���������� �������� ��������� ���������� bool ���� ������ �� ����� ���������������
                booleanMove.booleanA = false;
                booleanMove.booleanD = false;
                booleanMove.booleanS = true;
                booleanMove.booleanW = false;
                /// ���� (indexTailSnake > 1) ������ ����� ������� �� ����� ��� 1 �������� ������. �������� ������� ������ ��������� �� 1 ������� � �������� �������.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// ���� (indexTailSnake > 0) ������ ����� ������� ������ �� 1 ��������. ��������� ��������� �������� ���� ���������� �������� ������.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                }
                inputSnake.y++; /// ������ ����
                /// �������� �� ������������ � �������
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// ������� ���� ���������� � �������
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    break;
                }
                /// �������� �� ������������ �� ������
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// ��������� ������� ����. �������� ������� ������� �������� ����
                gameField[variableApple.y][variableApple.x] = charApple; /// �������� ������� �� ������� ����
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// �������� ������ � ����� ����������
                /// ������� �����
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// �������� ������
                system("cls"); /// �������� �������
                /// ���� ���������� �������
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                    apple(); /// ����������� ������� ��������� ��������� �� ������� ����
                }
                printGameField(); /// ������� ������� ���� � �������
            }; break;
        //====================================================================================================
        case 'a' :
            while( !_kbhit() ) /// ���� ������ �� ������ ���������
            {
                /// ���������� ���������� �������� ��������� ���������� bool ���� ������ �� ����� ���������������
                booleanMove.booleanA = true;
                booleanMove.booleanD = false;
                booleanMove.booleanS = false;
                booleanMove.booleanW = false;
                /// ���� (indexTailSnake > 1) ������ ����� ������� �� ����� ��� 1 �������� ������. �������� ������� ������ ��������� �� 1 ������� � �������� �������.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// ���� (indexTailSnake > 0) ������ ����� ������� ������ �� 1 ��������. ��������� ��������� �������� ���� ���������� �������� ������.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                }
                inputSnake.x--; /// ������ �����
                /// �������� �� ������������ � �������
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// ������� ���� ���������� � �������
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    break;
                }
                /// �������� �� ������������ �� ������
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// ��������� ������� ����. �������� ������� ������� �������� ����
                gameField[variableApple.y][variableApple.x] = charApple; /// �������� ������� �� ������� ����
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// �������� ������ � ����� ����������
                /// ������� �����
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// �������� ������
                system("cls"); /// �������� �������
                /// ���� ���������� �������
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                    apple(); /// ����������� ������� ��������� ��������� �� ������� ����

                }
                printGameField(); /// ������� ������� ���� � �������
            }; break;
        //====================================================================================================
        case 'd' :
            while( !_kbhit() ) /// ���� ������ �� ������ ���������
            {
                /// ���������� ���������� �������� ��������� ���������� bool ���� ������ �� ����� ���������������
                booleanMove.booleanA = false;
                booleanMove.booleanD = true;
                booleanMove.booleanS = false;
                booleanMove.booleanW = false;
                /// ���� (indexTailSnake > 1) ������ ����� ������� �� ����� ��� 1 �������� ������. �������� ������� ������ ��������� �� 1 ������� � �������� �������.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// ���� (indexTailSnake > 0) ������ ����� ������� ������ �� 1 ��������. ��������� ��������� �������� ���� ���������� �������� ������.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                }
                inputSnake.x++; /// ������ ������
                /// �������� �� ������������ � �������
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// ������� ���� ���������� � �������
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    break;
                }
                /// �������� �� ������������ �� ������
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "����� ����" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// ��������� ������� ����. �������� ������� ������� �������� ����
                gameField[variableApple.y][variableApple.x] = charApple; /// �������� ������� �� ������� ����
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// �������� ������ � ����� ����������
                /// ������� �����
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// �������� ������
                system("cls"); /// �������� �������
                /// ���� ���������� �������
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// ����������� ���� x ������ ��� �������� indexTailSnake ���� x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// ����������� ���� y ������ ��� �������� indexTailSnake ���� y inputSnake
                    apple(); /// ����������� ������� ��������� ��������� �� ������� ����
                }
                printGameField(); /// ������� ������� ���� � �������
            }; break;
        //====================================================================================================
        case ' ' :
            while( !_kbhit() ) /// ���� ������ �� ������ ���������
            {
                if (pause)
                {
                    cout << endl;
                    cout << "Pause";
                }
                pause = false;
            };break;
        }
    }
}

int main()
{
    srand(time(NULL)); /// ���� ��� ��������� ���������
    setlocale(LC_ALL, "Rus"); /// ���������� ������� ����
    snake.x = width / 2; /// ������������� ��������� ��������� ������ �� x
    snake.y = 8; ///height / 2; /// ������������� ��������� ��������� ������ �� y
    charHeadSnake = '@'; /// ������������� ������ ������ ����
    charBordersGameField = '#'; /// ������������� ������ ������ �������� ����
    charApple = '$'; /// ������������� ������ �������
    fillGameField(charBordersGameField); /// ��������� ������� ����. �������� ������� ������� �������� ����
    moveSnake(snake, charHeadSnake); /// ������� ��� �������� ����. ��������� ������� typePointer ����, ������ ������ ����
    _getch(); /// ������� ����. ���������� ��� � ��������� ������� ��� ������ �����
    return 0;
}
