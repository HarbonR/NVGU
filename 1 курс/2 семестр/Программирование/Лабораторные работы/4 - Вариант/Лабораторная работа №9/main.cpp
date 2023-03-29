#include <graphics.h> /// ���������� ��� ������ � ��������.
#include <stdlib.h> /// ���������� ����������.
#include <stdio.h> /// ���������� ����� ������.
#include <math.h> /// ���������� ��� ������� �� ����������.

//====================================================================================================
/// ������� ��� ������� 4 ����� 1.

void exercise4Part1 (void)
{
    initwindow(800,600); /// ������� ���� ��� ������� �������� 800 �� 600 ��������
    setcolor(WHITE); /// ���������� ����� ����
    floodfill(1,1,BROWN);
    setcolor(BLACK);
    rectangle(10,10,350,100);
    //====================================================================================================
    /// �
    setcolor(BLUE);
    setlinestyle(1,0,1);
    moveto(15,90);
    lineto(15,15);
    lineto(35,15);
    lineto(35,90);
    //====================================================================================================
    /// �
    setcolor(RED);
    setlinestyle(2,0,1);
    moveto(50,90);
    lineto(65,50);
    lineto(80,90);
    moveto(55,80);
    lineto(75,80);
    //====================================================================================================
    /// �
    setcolor(GREEN);
    setlinestyle(3,0,1);
    moveto(90,90);
    lineto(90,50);
    arc(90,60,-90,90,10);
    arc(90,80,-90,90,12);
    //====================================================================================================
    /// �
    setcolor(YELLOW);
    setlinestyle(1,0,2);
    moveto(115,90);
    lineto(115,50);
    lineto(130,50);
    moveto(115,70);
    lineto(130,70);
    moveto(115,90);
    lineto(130,90);
    //====================================================================================================
    /// �
    setcolor(MAGENTA);
    setlinestyle(2,0,2);
    moveto(145,90);
    lineto(160,50);
    lineto(175,90);
    //====================================================================================================
    getch(); /// ������� ����� �������.
    closegraph(); /// ������� ��������� ������ � ��������.
}

//====================================================================================================
/// ������� ��� ������� 9 ����� 1.

void exercise9Part1 (int x, int y, int lineStyle, int lineColor, int styleFill, int colorFill)
{
    int poly[8]; /// ������, � ������� ����� ��������� ���������� �����
    floodfill(1,1,WHITE);
    poly[0] = x;
    poly[1] = y;
    poly[2] = poly[0] + 50;
    poly[3] = poly[1] - 50;
    poly[4] = poly[2] + 50;
    poly[5] = poly[1];
    poly[6] = poly[0];
    poly[7] = poly[1];
    setcolor(lineColor);
    setlinestyle(lineStyle,0,3);
    setfillstyle(styleFill, colorFill);
    fillpoly(4,poly);
}

//====================================================================================================
/// ������� ��� ������� 4 ����� 2.

void motionRectangle (int startX, int startY, int stepX, int stepY, int endX, int endY)
{
    int i, j;
    for (i = 0, j = 0; abs(i) < endX || abs (j) < endY; i+=stepX, j+=stepY)
    {
        setcolor(RED); /// ���������� ������� ����
        rectangle(startX + i, startY + j, startX + 40 + i, startY + 20 + j);
        if (kbhit()) break; /// ���� ����� ������ ����� �������, �� ���������� ����� �� ����� (kbhit() ���������� ��������� ��������, ���� ���� ������ ����� ������� ).
        delay(10); /// ��������� 1 ������������
        setcolor(WHITE); /// ���������� ����� ����.
        rectangle(startX + i, startY + j, startX + 40 + i, startY + 20 + j);
    }
}

//====================================================================================================
/// ������� ��� ������� 9 ����� 2.

void numberGroup (int x, int y)
{
    //====================================================================================================
    /// 3
    moveto(x,y);
    lineto(x+25,y);
    lineto(x+25,y+50);
    lineto(x,y+50);
    moveto(x+25,y+25);
    lineto(x,y+25);
    //====================================================================================================
    /// 1
    moveto(x+50,y+25);
    lineto(x+75,y);
    lineto(x+75,y+50);
    //====================================================================================================
    /// 0
    moveto(x+100,y);
    lineto(x+125,y);
    lineto(x+125,y+50);
    lineto(x+100,y+50);
    lineto(x+100,y);
    //====================================================================================================
    /// 2
    moveto(x+150,y);
    lineto(x+175,y);
    lineto(x+150,y+50);
    lineto(x+175,y+50);
    //====================================================================================================
}

void motionNumberGroup (int startX, int startY, int stepX, int stepY, int endX, int endY)
{
    int i, j;
    for (i = 0, j = 0; abs(i) < endX || abs (j) < endY; i+=stepX, j+=stepY)
    {
        setcolor(RED); /// ���������� ������� ����
        numberGroup(startX + i, startY + j);
        if (kbhit()) break; /// ���� ����� ������ ����� �������, �� ���������� ����� �� ����� (kbhit() ���������� ��������� ��������, ���� ���� ������ ����� ������� ).
        delay(10); /// ��������� 1 ������������
        setcolor(WHITE); /// ���������� ����� ����.
        numberGroup(startX + i, startY + j);
    }
}

//====================================================================================================

int main()
{
    //====================================================================================================
    /// ����������.

    int variableMenu = 4;
    int x = 50;
    int y = 100;

    //====================================================================================================

    if (variableMenu == 1)
    {
        exercise4Part1();
    }
    if (variableMenu == 2)
    {
        initwindow(800,600);
        exercise9Part1(x, y, 0, RED, SOLID_FILL, LIGHTBLUE);
        exercise9Part1(x+= 110, y, 1, RED, LINE_FILL, LIGHTRED);
        exercise9Part1(x+= 110, y, 2, RED, XHATCH_FILL, LIGHTGREEN);
        exercise9Part1(x+= 110, y, 3, RED, LTBKSLASH_FILL, LIGHTCYAN);
        exercise9Part1(x+= 110, y, 4, RED, HATCH_FILL, LIGHTMAGENTA);
        getch();
        closegraph();
    }
    if (variableMenu == 3)
    {
        initwindow(800,600); /// ������� ���� ��� ������� �������� 800 �� 600 ��������
        setcolor(WHITE); /// ���������� ����� ����
        floodfill(1,1,GREEN); /// ��������� ��� ����� ������, ���� �� ���������� �������, � �� �� ����������
        while (!kbhit())   /// ���� ����� ������������, ���� �� ����� ������ �����-���� �������
        {
            motionRectangle(600, 100, -1, 1, 100, 100);
            motionRectangle(500, 200, -1, -1, 100, 100);
            motionRectangle(400, 100, -1, 1, 100, 100);
            motionRectangle(300, 200, -1, -1, 100, 100);
        }
        getch();
        closegraph(); /// ������� ���� � ��������
    }
    if (variableMenu == 4)
    {
        initwindow(800,600);
        setcolor(WHITE); /// ���������� ����� ����
        floodfill(1,1,GREEN); /// ��������� ��� ����� ������, ���� �� ���������� �������, � �� �� ����������
        while (!kbhit())   /// ���� ����� ������������, ���� �� ����� ������ �����-���� �������
        {
            motionNumberGroup(10,500,1,0,250,0);
            motionNumberGroup(250,500,0,-1,0,250);
            motionNumberGroup(250,250,1,0,250,0);
            motionNumberGroup(500,250,0,1,0,250);
        }
        getch();
        closegraph();
    }
    return 0;
}
