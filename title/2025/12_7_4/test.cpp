// 从键盘输入两个字符串a和b，把串b的前5个字符连接到串a中，要求不用库函数strcat()，如果b的长度小于5，则把b中的所有元素连接到a中

#include <iostream>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[80];
    char b[80];
    gets(a);
    gets(b);
    int i = 0;
    while (a[i++] != 0)
        ;
    for (int j = 0; j < 5 && b[j] != '\0'; j++, i--)
    {
        a[i++] = b[j];
    }
    a[i] = '\0';
    return 0;
}