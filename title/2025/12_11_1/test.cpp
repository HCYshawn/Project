// #include <stdio.h>
// // 43. (基础算法)请编写一个程序，输入两个正整数 $a$ 和 $b$，计算并输出它们的最大公约数（Greatest Common Divisor, GCD）。提示：可以使用“辗转相除法”（欧几里得算法）或“更相减损法”。
// int main()
// {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     int m = a > b ? a : b;
//     int s = 0;
//     for (int i = 1; i < m; i++)
//     {
//         if (a % i == 0 && b % i == 0)
//         {
//             s = i;
//         }
//     }
//     printf("最大公约数为: %d\n", s);
//     return 0;
// }

// #include <stdio.h>
// // 44. (字符串处理)请编写一个程序，从键盘输入一个包含数字和字母的字符串（假设最大长度不超过 100），统计并输出该字符串中数字字符（'0'-'9'）的个数。
// int main()
// {
//     char s[100];
//     int a[10] = {0};
//     for (int i = 0; i < 100; i++)
//     {
//         scanf("%c", s[i]);
//         if (s[i] >= '0' && s[i] <= '9')
//         {
//             a[s[i] - '0']++;
//         }
//     }
//     printf("该字符串中数字字符个数分别为: \n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("数字: %d 个数为: %d", i, a[i]);
//     }
//     return 0;
// }

#include <stdio.h>
/*
45. (数据结构与指针) 已知一个单链表的结点结构定义如下：
struct Node {
    int data;
    struct Node *next;
};
请编写一个函数 void printList(struct Node *head)，该函数的功能是：遍历传入的链表 head，并将链表中所有结点的数据域 data 依次打印出来（用空格隔开）。如果链表为空，则打印 "NULL"。
*/
struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *nx = head;
    while (nx->next != NULL)
    {
        printf("%d ", nx->data);
        nx = nx->next;
    }
    printf("NULL\n");
}