// 43.编写一个 C 语言程序，求 1! + 2! + 3! + ... + n! 的值，其中 $n$ 是从键盘输入的正整数（假设结果不超过 long 类型的范围）。(提示：可以尽量优化算法，避免双重循环)编写一个 C 语言程序，
// #include <stdio.h>
// int main()
// {
//     long n = 0;
//     scanf("%d", &n);
//     long long sum = 0;
//     long long mid = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         sum += mid;
//         mid *= i;
//     }
//     printf("其值为：%d\n", sum);
//     return 0;
// }

// 44.实现 矩阵转置 的功能。要求：定义一个 $3 \times 3$ 的整型二维数组，从键盘输入数据，将其行和列互换（转置），然后输出转置后的矩阵。
// #include <stdio.h>
// int main()
// {
//     int a[3][3] = {0};
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             scanf("%d", &a[i][j]);
//         }
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = i; j < 3; j++)
//         {
//             int temp = a[i][j];
//             a[i][j] = a[j][i];
//             a[j][i] = temp;
//         }
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 45.编写一个 C 语言程序（含结构体定义和 main 函数），实现以下功能：建立一个包含学生信息（学号、分数）的单链表。编写代码删除链表中所有分数低于 60 分的结点。最后打印剩余链表中的学生学号。(注：只需写出核心逻辑代码，输入数据部分可简化)
#include <stdio.h>
int main()
{

    return 0;
}