// 编程计算1！+2！+3！+...+10！的值

#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            sum += j;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}