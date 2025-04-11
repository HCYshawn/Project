#pragma once
#include <stdio.h>
#include "class.h"

// 欢迎菜单以及一级菜单
void print_welcome()
{
    printf("/---------------------------\\\n");
    printf("|/-------------------------\\|\n");
    printf("||      welcome mine!      ||\n");
    printf("||-------------------------||\n");
    printf("||       1. play           ||\n");
    printf("||       2. description    ||\n");
    printf("||       0. oever          ||\n");
    printf("|\\-------------------------/|\n");
    printf("\\---------------------------/\n");
}

// 游戏菜单以及二级菜单
void print_menu()
{
    printf("/-------------------------\\\n");
    printf("|/-----------------------\\|\n");
    printf("||     please select     ||\n");
    printf("||-----------------------||\n");
    printf("||      1. 10 mine       ||\n");
    printf("||      2. 40 mine       ||\n");
    printf("||      3. 99 mine       ||\n");
    printf("||      4. custom        ||\n");
    printf("||      0.  exit         ||\n");
    printf("|\\-----------------------/|\n");
    printf("\\-------------------------/\n");
}

// 游戏说明
void print_description_english()
{
    printf("/------------------------------------------------------------------\\\n");
    printf("|/----------------------------------------------------------------\\|\n");
    printf("||        There are four levels of difficulty in the game:        ||\n");
    printf("||         1. 10 mine  2. 40 mine  3. 99 mine  4. custom          ||\n");
    printf("||                                                                ||\n");
    printf("|| > The game clears mines by entering coordinates.               ||\n");
    printf("|| > When there are mines within 8 blocks around the coordinates, ||\n");
    printf("||   the number of mines whill be displayed int the coordinate    ||\n");
    printf("||   grid.                                                        ||\n");
    printf("|| > The game will automatically help you exclude the grid that   ||\n");
    printf("||   doesn't meet the above criteria.                             ||\n");
    printf("|| > Enter ' 0 0 ' to enter the annotation mode, in which you can ||\n");
    printf("||   annotate the coordinates that may be mines. Enter ' 0 1 '    ||\n");
    printf("||   again to exit the annotation mode.                           ||\n");
    printf("|| > The game stipulates that ' * ' is thunder, and the           ||\n");
    printf("||   coordinate grid marke in the labeling mode is disaplayed     ||\n");
    printf("||   as ' ! ' .                                                   ||\n");
    printf("||----------------------------------------------------------------||\n");
    printf("||       Please enter ' 0 ' to exit the instrucitons.             ||\n");
    printf("|\\----------------------------------------------------------------/|\n");
    printf("\\------------------------------------------------------------------/\n");
}

// 打印边框上
void print_upperborder(int row)
{

    printf("/");
    for (int i = 0; i <= row * 2 + 6; i++)
    {
        printf("-");
    }
    printf("\\");
    printf("\n");
    printf("|/");
    for (int i = 0; i <= row * 2 + 4; i++)
    {
        printf("-");
    }
    printf("\\|\n");
}

// 打印边框下
void print_lowerborder(int row)
{
    printf("|\\");
    for (int i = 0; i <= row * 2 + 4; i++)
    {
        printf("-");
    }
    printf("/|\n");
    printf("\\");
    for (int i = 0; i <= row * 2 + 6; i++)
    {
        printf("-");
    }
    printf("/\n");
}

// 打印上行标
void print_uppercolsign(int i, int row)
{
    if (i + 1 == 1)
    {
        printf("|| ");
        for (int i = 0; i <= row; i++)
        {
            if (i % 10 == 0 && i != 0)
            {
                printf("%d", i);
            }
            else
                printf("%d ", i % 10);
        }
        printf("  ||\n");
    }
}

// 打印下行标
void print_lowercolsign(int i, int col, int row)
{
    if (i + 1 == col)
    {
        printf("|| ");
        for (int i = 0; i <= row; i++)
        {
            if (i % 10 == 0 && i != 0)
            {
                printf("%d", i);
            }
            else
                printf("%d ", i % 10);
        }
        printf("  ||\n");
    }
}