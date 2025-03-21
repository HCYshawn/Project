#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<tgmath.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};