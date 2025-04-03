#pragma once
#include <stdio.h>

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