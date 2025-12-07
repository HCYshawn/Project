// 从键盘输入若干个整数（数据个数应少于50），其值在0至4的范围内，用-1作为输入结束标志。统计每个整数的个数

#include <iostream>

int main()
{
    int a[5] = {0};
    int mid = 0;
    while (mid != -1)
    {
        scanf("%d", &mid);
        if (mid >= 0 && mid <= 4)
            a[mid]++;
    }
    for (int i = 0; i <= 4; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}