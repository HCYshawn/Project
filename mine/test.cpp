#include "game.h"
#include "class.h"
#include "client.h"
#include "print.h"
/*
2025_3_29 ~

*/

void test1()
{

    print_welcome();
    int start = 0;
    while (std::cin >> start)
    {
        Client *client;
        if (start == 1)
        {
            print_menu();
            int i = 0;
            std::cin >> i;
            // switch (i)
            // {
            // case1:
            // {
            //     client = new Client(ROW1, COL1, i);
            //     client->client_print();
            //     break;
            // }
            // case2:
            // {
            //     client = new Client(ROW2, COL2, i);
            //     client->client_print();
            //     break;
            // }
            // case3:
            // {
            //     client = new Client(ROW3, COL3, i);
            //     client->client_print();
            //     break;
            // }
            // case4:
            // {
            //     int row = 0, col = 0;
            //     std::cout << "please input row and col:";
            //     std::cin >> row >> col;
            //     client = new Client(row, col, i);
            //     client->client_print();
            //     break;
            // }
            // }
        }
    }
}
int main()
{

    // Chessinitial_Factory *minefactory = new MineFactory();
    // Chessinitial_Factory *showfactory = new ShowFactory();

    // // 生产不同产品
    // Chessinitial *mineMap = minefactory->create(ROW2, COL2, MINE);
    // Chessinitial *showLayer = showfactory->create(ROW2, COL2, SHOW);
    // // 使用产品
    // mineMap->print();
    // std::cout << std::endl;
    // showLayer->print();
    // std::cout << std::endl;

    // // 手动释放内存
    // delete mineMap;

    // delete showLayer;
    // delete minefactory;
    // delete showfactory;
    test1();
    return 0;
}