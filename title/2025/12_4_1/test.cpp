// 通过键盘输入任意一些字符，统计字母、数字、空格及其他字符的个数，当键盘输入$时结束

#include <iostream>
#include <cstdio>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    char s;
    while (scanf("%c", &s) != EOF && s != '$')
    {
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        {
            i++;
        }
        else if (s >= '0' && s <= '9')
        {
            j++;
        }
        else if (s == ' ')
        {
            k++;
        }
        else
        {
            m++;
        }
    }
    printf("%d %d %d %d ", i, j, k, m);
    return 0;
}