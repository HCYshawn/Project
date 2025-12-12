// 已有函数调用语句"mypow(x,n);"用于求x的n次方，请使用int mypow(int x,int n)函数来编写程序
#include <stdio.h>

int mypow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            x *= x;
        }
        return x;
    }
    else
    {
        int j = 1;
        for (int i = 0; i < n; i++)
        {
            j /= x;
        }
        return j;
    }
}

int main()
{
    int x = 0;
    int n = 0;
    scanf("%d %d", &x, &n);
    int ret = mypow(x, n);
    return 0;
}