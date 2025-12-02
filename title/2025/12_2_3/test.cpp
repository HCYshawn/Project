// 编程实现，随机产生两个三位自然数，并求其平均值

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    int x = std::rand() % 900 + 100;
    int y = std::rand() % 900 + 100;

    double av = (x + y) / 2.0;

    std::cout << "平均值为: " << av << std::endl;

    return 0;
}