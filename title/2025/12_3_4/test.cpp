// 编写程序，输出一个数字金字塔

#include <iostream>
#include <cstdio>

int main()
{
    int h = 0;
    scanf("%d", &h);
    for (int i = 1; i <= h; i++)
    {
        for (int k = h - i; k >= 0; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}