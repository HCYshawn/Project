// 编程实现输入一个100以内的实数x，可以在一行中按"f(x)=result"的格式输出，其中x与result都保留两位小数

#include <iostream>
#include <cstdio>

int main()
{
    double x = 0.0;
    std::cin >> x;
    if (x)
    {
        printf("f(%lf)=%lf", &x, 1.0 / x);
    }
    else
    {
        printf("f(%d)=0", &x);
    }
    return 0;
}