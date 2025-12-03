// 编程求2~100内的素数

#include <iostream>
#include <cstdio>

int main()
{
    for (int i = 2; i <= 100; i++)
    {
        int k = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                k = 0;
        }
        if (k)
            printf("%d ", i);
    }

    return 0;
}