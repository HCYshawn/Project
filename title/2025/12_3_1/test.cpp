// 编程实现，输入一个字符，如果它是一个小写字母，则把它变成大写字母进行输出，反之则输出小写，其他字符原样输出

#include <iostream>
#include <cstdio>
int main()
{
    char s;
    std::cin >> s;
    if (s >= 'a' && s <= 'z')
    {
        printf("%c", s - 32);
        char mid = s - 32;
    }
    else if (s >= 'A' && s <= 'Z')
    {
        printf("%c", s + 32);
    }
    else
    {
        printf("%c", s);
    }
    return 0;
}