// 通过循环及按行顺序为一个5x5的二维数组a赋 1~25 的自然数，然后输出该数组的左下半三角

#include <iostream>

int main()
{
    int a[5][5] = {0};
    int k = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = k++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}