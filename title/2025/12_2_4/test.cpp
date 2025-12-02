// 编程实现从键盘输入3个整数， 并按从小到大的顺序进行输出

#include <iostream>

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    std::cin >> x >> y >> z;
    if (x > y)
    {
        int mid = x;
        x = y;
        y = mid;
    }
    if (x > z)
    {
        int mid = x;
        x = z;
        z = mid;
    }
    if (y > z)
    {
        int mid = y;
        y = z;
        z = mid;
    }
    std::cout << x << y << z;
    return 0;
}