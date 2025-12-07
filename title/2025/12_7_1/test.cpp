// 定义一个含有30个整型元素的数组按顺序分别赋予从2开始的偶数，然后按顺序每5个数求出一个平均值，放在另一个数组中并输出

#include <iostream>

int main()
{
    int a[30] = {0};
    int b[6] = {0};
    int sum = 0;
    int k = 0;
    for (int i = 1, j = 2; i <= 30, j <= 60; i++, j += 2)
    {
        a[i] = j;
        sum += j;
        if (i % 5 == 0)
        {
            b[k] = sum;
            sum = 0;
            k++;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}