// 设计一个乘法程序，输出九九乘法表

#include <iostream>
#include <cstdio>

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%d ", j, i, j * i);
        }
        printf("\n");
    }
    return 0;
}