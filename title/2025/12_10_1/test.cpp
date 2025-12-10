// #include <stdio.h>
// // 43.从键盘输入一个正整数 $n$，判断该数是否为素数（质数）。如果是素数，输出 "Yes"，否则输出 "No"。(注：素数是指只能被 1 和它本身整除的大于 1 的整数)

// int main()
// {
//     int sc = 0;
//     int m = 1;
//     scanf("%d", &sc);
//     for (int i = 2; i <= sc / 2; i++)
//     {
//         if (sc / i == 0)
//         {
//             m = 0;
//         }
//     }
//     if (m == 1)
//     {
//         printf("YES\n");
//     }
//     else
//     {
//         printf("NO\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// // 44.编写程序，定义一个包含 10 个整数的一维数组。(1) 从键盘输入 10 个整数存入数组；(2) 计算并输出这 10 个整数的平均值（保留两位小数）；(3) 输出数组中最大值及其对应的下标（位置）。

// int main()
// {
//     int arr[10] = {0};
//     double av = 0.0;
//     int sum = 0;
//     int am = 0;
//     int j = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr[i]);
//         sum += arr[i];
//         if(am<arr[i])
//         {
//             am = arr[i];
//             j = i;
//         }
//     }
//     av = sum / 10.0;
//     printf("数组平均值为: %lf\n", av);
//     printf("数组中最大值为 %d ,其下标为 %d\n", am, j);
//     return 0;
// }

#include <stdio.h>
// 45.某班级有 5 名学生，每个学生的信息包括：学号（整型）和 C语言成绩（整型）。请定义一个结构体数组来存储这 5 名学生的信息，从键盘输入数据，然后找出成绩最高的学生，并在屏幕上输出该学生的学号和成绩。
struct student
{
    int id = 0;
    int m = 0;
};

int main()
{
    struct student sd[5];
    int mm = 0;
    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d %d", &sd[i].id, &sd[i].m);
        if (mm < sd[i].m)
        {
            mm = sd[i].m;
            j = i;
        }
    }
    printf("成绩最高的学生学号为: %d ,成绩为: %d\n", sd[j].id, sd[j].m);
    return 0;
}
