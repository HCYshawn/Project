// 已有变量定义和函数调用语句"int a = 1,b = -5,c;c=fun(a,b);"fun()函数的作用是计算俩数差的绝对值，并将差值返回调用函数，请编写程序
#include <stdio.h>

int fun(int a, int b)
{
    if (a - b < 0)
    {
        return -(a - b);
    }
    else if (a - b > 0)
    {
        return a - b;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a = 1, b = -5, c;
    c = fun(a, b);
    printf("%d \n", c);
    return 0;
}