// 已有函数调用语句"c=add(a,b);"，计算两个实数的和并返回该值
#include <stdio.h>

double add(double a, double b)
{
    return a + b;
}

int main()
{
    double a = 0;
    double b = 0;
    scanf("%lf %lf", &a, &b);
    double c = add(a, b);
    printf("%lf \n", c);
    return 0;
}