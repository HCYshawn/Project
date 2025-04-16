#pragma once
#include <stdio.h>

// 打印欢迎界面
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

// 雷菜单
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
    printf("|| > The row number and col number are calculated in %10, such as ||\n");
    printf("||   11 -> 1, 12 -> 2(20 -> 20). Please enter the original value  ||\n");
    printf("||   when entering.                                               ||\n");
    printf("|| > Enter ' 0 0 ' to enter the annotation mode, in which you can ||\n");
    printf("||   annotate the coordinates that may be mines. Enter ' 0 1 ' to ||\n");
    printf("||   cancel the label, and enter ' 0 0 ' again to exit the        ||\n");
    printf("||   labeling mode.                                               ||\n");
    printf("|| > The game stipulates that ' * ' is thunder, and the           ||\n");
    printf("||   coordinate grid marke in the labeling mode is disaplayed     ||\n");
    printf("||   as ' ! ' .                                                   ||\n");
    printf("||----------------------------------------------------------------||\n");
    printf("||       Please enter ' 0 ' to exit the instrucitons.             ||\n");
    printf("|\\----------------------------------------------------------------/|\n");
    printf("\\------------------------------------------------------------------/\n");
}

void print_description_chinese()
{
    printf("/------------------------------------------------------------------\\\n");
    printf("|/----------------------------------------------------------------\\|\n");
    printf("||                   游戏中有四个难度等级:                        ||\n");
    printf("||         1. 10 雷  2. 40 雷  3. 99 雷  4. 自定义                ||\n");
    printf("||                                                                ||\n");
    printf("|| > 游戏通过输入坐标来排雷                                       ||\n");
    printf("|| > 当坐标周围8格内有雷时, 坐标格子会显示雷的数量                ||\n");
    printf("|| > 游戏会自动帮你排除不符合上述条件的格子                       ||\n");
    printf("|| > 行号和列号以 %10 计算, 如 11 -> 1, 12 -> 2(20 -> 20), 输入时 ||\n");
    printf("||   请按原值输入                                                 ||\n");
    printf("|| > 输入 ' 0 0 ' 进入标注模式，在该模式下可以对可能是雷的坐标    ||\n");
    printf("||   格子进行标注，输入' 0 1 '以取消标记，再次输入 ' 0 0 ' 则     ||\n");
    printf("||   退出标注模式                                                 ||\n");
    printf("|| > 游戏规定 ' * ' 为雷，标注模式下的坐标格子标记为 ' ! ' .      ||\n");
    printf("||----------------------------------------------------------------||\n");
    printf("||                    请按 ' 0 ' 键退出说明。                     ||\n");
    printf("|\\----------------------------------------------------------------/|\n");
    printf("\\------------------------------------------------------------------/\n");
}

// 打印上边框
void print_upperborder(int col)
{

    printf("/");
    for (int i = 0; i <= col * 2 + 6; i++)
    {
        printf("-");
    }
    printf("\\");
    printf("\n");
    printf("|/");
    for (int i = 0; i <= col * 2 + 4; i++)
    {
        printf("-");
    }
    printf("\\|\n");
}

// 打印下边框
void print_lowerborder(int col)
{
    printf("|\\");
    for (int i = 0; i <= col * 2 + 4; i++)
    {
        printf("-");
    }
    printf("/|\n");
    printf("\\");
    for (int i = 0; i <= col * 2 + 6; i++)
    {
        printf("-");
    }
    printf("/\n");
}

// 打印行号
void print_col_numbers(int cols)
{
    printf("|| ");
    for (int j = 0; j <= cols; j++)
    {
        if (j % 10 == 0 && j != 0)
        {
            printf("%-2d", j);
        }
        else
            printf("%-2d", j % 10);
    }
    printf("  ||\n");
}

// 打印棋盘边框
void print_chessborder(int col)
{
    printf("||  ");
    for (int j = 0; j <= col * 2; j++)
    {
        printf("-");
    }
    printf("  ||\n");
}

// 打印雷数及标注说明
void print_mine(int col, int mine)
{
    printf("||");
    for (int i = 0; i <= col * 2 + 4; i++)
    {
        printf("-");
    }
    printf("||\n");
    printf("||");
    printf(" mine: %d||", mine);
    printf("tab->(0, 0) ");
    if (col > 9)
    {
        for (int i = 0; i < col * 2 - 18; i++)
        {
            printf(" ");
        }
    }

    printf("||\n");
}