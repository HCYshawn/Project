#include "game.h"
#include "class.h"
#include "client.h"
#include "print.h"
/*
2025_3_29 ~

*/

void test1()
{

    int select = 1;

    do
    {
        print_welcome();
        std::cout << "please select: ";
        std::cin >> select;
        if (select == 1)
        {
            print_menu();
            // int i = 0;
            // while (std::cin >> i)
            // {
            //     switch(i)
            //     case 0:
            //         std::cout << "exit" << std::endl;
            //         break;
            //     case 1:
            //         Client client(ROW1, COL1, WIN1);
            //         client.play();
            //         break;
            //     case 2:
            //         Client client(ROW2, COL2, WIN2);
            //         client.play();
            //         break;
            //     case 3:
            //         Client client(ROW3, COL3, WIN3);
            //         client.play();
            //         break;
            //     case 4:
            //         int row = 0;
            //         int col = 0;
            //         int win = 0;
            //         std::cout << "please input row col win: ";
            //         std::cin >> row >> col >> win;
            //         Client client(row, col, win);
            //         client.play();
            //         break;
            //     default:
            //         std::cout << "error" << std::endl;
            //         break;
        }
        else if (select == 2)
        {
            std::cout << "please select a description language: " << std::endl;
            std::cout << "1. 中文 2. ENGLISH " << std::endl;
            int j = 0;
            std::cout << "please select: ";
            std::cin >> j;
            if (j == 1)
            {
            }
            else if (j == 2)
            {
                print_description_english();
            }
            else
                std::cout << "exit..." << std::endl;
        }
        else
        {
            std::cout << "game exit..." << std::endl;
            break;
        }
    } while (select);
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