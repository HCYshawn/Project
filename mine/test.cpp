#include "game.h"
#include "class.h"

/*
2025_3_29 ~ 

*/

int main()
{
    Chessinitial_Factory *minefactory = new MineFactory();
    Chessinitial_Factory *showfactory = new ShowFactory();

    // ������ͬ��Ʒ
    Chessinitial *mineMap = minefactory->create(ROW2, COL2, MINE);
    Chessinitial *showLayer = showfactory->create(ROW2, COL2, SHOW);
    // ʹ�ò�Ʒ
    mineMap->print();
    std::cout << std::endl;
    showLayer->print();
    std::cout << std::endl;

    // �ֶ��ͷ��ڴ�
    delete mineMap;
    delete showLayer;
    delete minefactory;
    delete showfactory;

    return 0;
}