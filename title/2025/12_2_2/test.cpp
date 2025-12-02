#include<iostream>

int main()
{
    int sc = 0;
    std::cin >> sc;
    while(sc)
    {
        int mid = sc % 10;
        std::cout << mid;
        sc/=10;
    }
    return 0;
}