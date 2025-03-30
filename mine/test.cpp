#include "game.h"
#include "class.h"
#include "client.h"
#include "print.h"
/*
2025_3_29 ~

*/

void test1()
{
    Client *client = new Client;
    print_welcome();
    int start = 0;
    while (std::cin >> start)
    {
        if (start == 1)
        {
            print_menu();
            int select = 0;
            std::cin >> select;
            switch (select)
            {
            case 1:
                client = new Client(ROW1, COL1, WIN1);
                break;
            case 2:
                client = new Client(ROW2, COL2, WIN2);
                break;
            case 3:
                client = new Client(ROW3, COL3, WIN3);
                break;
            case 4:
                int row, col, win;
                std::cout << "please input row, col, win" << std::endl;
                std::cin >> row >> col >> win;
                client = new Client(row, col, win);
                break;
            case 0:
                exit(0);
                break;
            default:
                std::cout << "please input again" << std::endl;
                break;
            }
        }
    }
}
int main()
{

    // Chessinitial_Factory *minefactory = new MineFactory();
    // Chessinitial_Factory *showfactory = new ShowFactory();

    // // ������ͬ��Ʒ
    // Chessinitial *mineMap = minefactory->create(ROW2, COL2, MINE);
    // Chessinitial *showLayer = showfactory->create(ROW2, COL2, SHOW);
    // // ʹ�ò�Ʒ
    // mineMap->print();
    // std::cout << std::endl;
    // showLayer->print();
    // std::cout << std::endl;

    // // �ֶ��ͷ��ڴ�
    // delete mineMap;
    // delete showLayer;
    // delete minefactory;
    // delete showfactory;

    return 0;
}