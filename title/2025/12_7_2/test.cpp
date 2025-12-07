// 按行顺序给2x3的二维数组赋予2、4、6等偶数，然后按列的顺序输出该数组

#include <iostream>

int main()
{
    int a[2][3] = {0};
    int k = 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] += k;
            k += 2;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", a[j][i]);
        }
    }
    return 0;
}