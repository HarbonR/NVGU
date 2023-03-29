#include <iostream> /// Библиотека ввода-вывода с++
#include <windows.h> /// Библиотека для windown команд
#include <locale.h> /// Библиотека для локализации языка
#include <conio.h> /// Библиотека с функциями для ввода-вывода
#include <time.h> /// Библиотека для работы со временем
#define height 20 /// Высота
#define width 40 /// Ширина
#define timeSleep 400 /// Задержка движения

using namespace std; /// Используем пространство имен

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /// Переменная для установки цвета
///SetConsoleTextAttribute(hConsole, номерЦвета); /// Функция для установки цвета

/// Структура точек
typedef struct
{
    int x;
    int y;
}typePointer;

/// Структура переменных bool чтоб змейка не могла разворачиваться
typedef struct
{
    bool booleanW;
    bool booleanS;
    bool booleanA;
    bool booleanD;
}typeBooleanMove;

char gameField[height][width]; /// Массив игровое поле
char charBordersGameField; /// Символ границ игрового поля
typePointer snake; /// Змея
char charHeadSnake; /// Символ головы змеи
char charTailSnake; /// Символ хвоста змеи
typePointer tailSnake[100]; /// Массив структур точек хвоста змеи
int indexTailSnake = 0; /// Индекс для массива хвоста
typeBooleanMove booleanMove; /// Переменная типа typeBooleanMove чтоб змейка не могла разворачиваться
typePointer variableApple; /// Хранит текущее положение яблочка
char charApple; /// Символ яблочка
bool pause = true; /// Переменная для паузы
int counter = 0; /// Количество очков

/// Заполняет игровое поле
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

/// Выводит игровое поле в консоль
void printGameField ()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == variableApple.x && i == variableApple.y)
            {
                SetConsoleTextAttribute(hConsole, 4); /// Установить цвет яблочка (красный)
                cout << gameField[i][j];
            }
            else if (i == 0 || i == height - 1)
            {
                SetConsoleTextAttribute(hConsole, 3); /// Установить цвет верхнего и нижнего поля (голубой)
                cout << gameField[i][j];
            }
            else if (j == 0 || j == width - 1)
            {
                SetConsoleTextAttribute(hConsole, 3); /// Установить цвет левого и правого поля (голубой)
                cout << gameField[i][j];
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 14); /// Установить остальной цвет [змея] (бежевый)
                cout << gameField[i][j];
            }
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 15); /// Установитрь белый цвет
    cout << "Счёт: " << counter;

}

/// Рандомно присваивает положение яблочка на игровом поле
void apple ()
{
    variableApple.x = rand() % (width - 2) + 1;
    variableApple.y = rand() % (height -2) + 1;
}

/// Логика движения змейки
void moveSnake (typePointer inputSnake, char symbolSnake)
{
    char variableMove = '0'; /// Переменная для хранения символа движения и выхода из игры
    gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// Помещаем змейку в центр игрового поля
    apple(); /// Присваиваем яблочку рандомное положение на игровом поле
    gameField[variableApple.y][variableApple.x] = charApple; /// Помещаем яблочко на игровое поле
    printGameField(); /// Выводим игровое поле в консоль
    while (variableMove != 'e')
    {
        pause = true; /// Присваиваем значение true чтобы работала пауза
        variableMove = _getch(); /// Нажатая кнопка присваивается переменной variableMove
        /// Проверка на попытку развернуться
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
            while( !_kbhit() ) /// Пока кнопка не нажата выполнять
            {
                /// Присвоение переменным значений структуры переменных bool чтоб змейка не могла разворачиваться
                booleanMove.booleanA = false;
                booleanMove.booleanD = false;
                booleanMove.booleanS = false;
                booleanMove.booleanW = true;
                /// Если (indexTailSnake > 1) значит хвост состоит из более чем 1 значения хвоста. Значения массива хвоста сдвинутся на 1 единицу к нуливому индексу.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// Если (indexTailSnake > 0) значит хвост состоит хотябы из 1 элемента. Присвоить последнее значение змеи последнему элементу хвоста.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                }
                inputSnake.y--; /// Змейка вверх
                /// Проверка на столкновение с хвостом
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// Выходит если столкулись с хвостом
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    break;
                }
                /// Проверка на столкновение со стеной
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// Заполняем игровое поле. Параметр функции граница игрового поля
                gameField[variableApple.y][variableApple.x] = charApple; /// Помещаем яблочко на игровое поле
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// Помещаем змейку в ковые координаты
                /// Выводим хвост
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// Задержка вывода
                system("cls"); /// Отчищаем консоль
                /// Если собирается яблочко
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                    apple(); /// Присваиваем яблочку рандомное положение на игровом поле
                }
                printGameField(); /// Выводит игровое поле в консоль
            }; break;
        //====================================================================================================
        case 's' :
            while( !_kbhit() ) /// Пока кнопка не нажата выполнять
            {
                /// Присвоение переменным значений структуры переменных bool чтоб змейка не могла разворачиваться
                booleanMove.booleanA = false;
                booleanMove.booleanD = false;
                booleanMove.booleanS = true;
                booleanMove.booleanW = false;
                /// Если (indexTailSnake > 1) значит хвост состоит из более чем 1 значения хвоста. Значения массива хвоста сдвинутся на 1 единицу к нуливому индексу.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// Если (indexTailSnake > 0) значит хвост состоит хотябы из 1 элемента. Присвоить последнее значение змеи последнему элементу хвоста.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                }
                inputSnake.y++; /// Змейка вниз
                /// Проверка на столкновение с хвостом
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// Выходит если столкулись с хвостом
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    break;
                }
                /// Проверка на столкновение со стеной
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// Заполняем игровое поле. Параметр функции граница игрового поля
                gameField[variableApple.y][variableApple.x] = charApple; /// Помещаем яблочко на игровое поле
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// Помещаем змейку в ковые координаты
                /// Выводим хвост
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// Задержка вывода
                system("cls"); /// Отчищаем консоль
                /// Если собирается яблочко
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                    apple(); /// Присваиваем яблочку рандомное положение на игровом поле
                }
                printGameField(); /// Выводит игровое поле в консоль
            }; break;
        //====================================================================================================
        case 'a' :
            while( !_kbhit() ) /// Пока кнопка не нажата выполнять
            {
                /// Присвоение переменным значений структуры переменных bool чтоб змейка не могла разворачиваться
                booleanMove.booleanA = true;
                booleanMove.booleanD = false;
                booleanMove.booleanS = false;
                booleanMove.booleanW = false;
                /// Если (indexTailSnake > 1) значит хвост состоит из более чем 1 значения хвоста. Значения массива хвоста сдвинутся на 1 единицу к нуливому индексу.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// Если (indexTailSnake > 0) значит хвост состоит хотябы из 1 элемента. Присвоить последнее значение змеи последнему элементу хвоста.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                }
                inputSnake.x--; /// Змейка влево
                /// Проверка на столкновение с хвостом
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// Выходит если столкулись с хвостом
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    break;
                }
                /// Проверка на столкновение со стеной
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// Заполняем игровое поле. Параметр функции граница игрового поля
                gameField[variableApple.y][variableApple.x] = charApple; /// Помещаем яблочко на игровое поле
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// Помещаем змейку в ковые координаты
                /// Выводим хвост
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// Задержка вывода
                system("cls"); /// Отчищаем консоль
                /// Если собирается яблочко
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                    apple(); /// Присваиваем яблочку рандомное положение на игровом поле

                }
                printGameField(); /// Выводит игровое поле в консоль
            }; break;
        //====================================================================================================
        case 'd' :
            while( !_kbhit() ) /// Пока кнопка не нажата выполнять
            {
                /// Присвоение переменным значений структуры переменных bool чтоб змейка не могла разворачиваться
                booleanMove.booleanA = false;
                booleanMove.booleanD = true;
                booleanMove.booleanS = false;
                booleanMove.booleanW = false;
                /// Если (indexTailSnake > 1) значит хвост состоит из более чем 1 значения хвоста. Значения массива хвоста сдвинутся на 1 единицу к нуливому индексу.
                if(indexTailSnake > 1)
                {
                    for (int i = 1; i < indexTailSnake; i++)
                    {
                        tailSnake[i - 1].x = tailSnake[i].x;
                        tailSnake[i - 1].y = tailSnake[i].y;
                    }
                }
                /// Если (indexTailSnake > 0) значит хвост состоит хотябы из 1 элемента. Присвоить последнее значение змеи последнему элементу хвоста.
                if (indexTailSnake > 0)
                {
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                }
                inputSnake.x++; /// Змейка вправо
                /// Проверка на столкновение с хвостом
                for (int i = 0; i < indexTailSnake; i++)
                {
                    if(inputSnake.x == tailSnake[i].x && inputSnake.y == tailSnake[i].y)
                    {
                        variableMove = 'e';
                        break;
                    }
                }
                /// Выходит если столкулись с хвостом
                if(variableMove == 'e')
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    break;
                }
                /// Проверка на столкновение со стеной
                if(inputSnake.x == 0 || inputSnake.x == width -1 || inputSnake.y == 0 || inputSnake.y == height -1)
                {
                    cout << endl;
                    cout << "Конец игры" << endl;
                    variableMove = 'e';
                    break;
                }
                fillGameField(charBordersGameField); /// Заполняем игровое поле. Параметр функции граница игрового поля
                gameField[variableApple.y][variableApple.x] = charApple; /// Помещаем яблочко на игровое поле
                gameField[inputSnake.y][inputSnake.x] = symbolSnake; /// Помещаем змейку в ковые координаты
                /// Выводим хвост
                for(int i = 0; i < indexTailSnake; i++)
                    gameField[tailSnake[i].y][tailSnake[i].x] = 'x';
                Sleep(timeSleep); /// Задержка вывода
                system("cls"); /// Отчищаем консоль
                /// Если собирается яблочко
                if (variableApple.x == inputSnake.x && variableApple.y == inputSnake.y)
                {
                    counter += 10;
                    indexTailSnake++;
                    tailSnake[indexTailSnake - 1].x = inputSnake.x; /// Присваиваем поле x хвоста под индексом indexTailSnake поле x inputSnake
                    tailSnake[indexTailSnake - 1].y = inputSnake.y; /// Присваиваем поле y хвоста под индексом indexTailSnake поле y inputSnake
                    apple(); /// Присваиваем яблочку рандомное положение на игровом поле
                }
                printGameField(); /// Выводит игровое поле в консоль
            }; break;
        //====================================================================================================
        case ' ' :
            while( !_kbhit() ) /// Пока кнопка не нажата выполнять
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
    srand(time(NULL)); /// Ключ для рандомной генерации
    setlocale(LC_ALL, "Rus"); /// Локализуем русский язык
    snake.x = width / 2; /// Устанавливаем начальное положение змейки по x
    snake.y = 8; ///height / 2; /// Устанавливаем начальное положение змейки по y
    charHeadSnake = '@'; /// Устанавливаем символ головы змеи
    charBordersGameField = '#'; /// Устанавливаем символ границ игрового поля
    charApple = '$'; /// Устанавливаем символ яблочка
    fillGameField(charBordersGameField); /// Заполняем игровое поле. Параметр функции граница игрового поля
    moveSnake(snake, charHeadSnake); /// Функция для движения змеи. Параметры функции typePointer Змея, символ головы змеи
    _getch(); /// Ожидает ввод. Исправляет баг с закрытием консоли без показа счёта
    return 0;
}
