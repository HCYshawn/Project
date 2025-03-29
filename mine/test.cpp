#include "game.h"
#include "class.h"

/*
2025_3_29 ~ 

*/

int main()
{
    Chessinitial_Factory *minefactory = new MineFactory();
    Chessinitial_Factory *showfactory = new ShowFactory();

    // 生产不同产品
    Chessinitial *mineMap = minefactory->create(ROW2, COL2, MINE);
    Chessinitial *showLayer = showfactory->create(ROW2, COL2, SHOW);
    // 使用产品
    mineMap->print();
    std::cout << std::endl;
    showLayer->print();
    std::cout << std::endl;

    // 手动释放内存
    delete mineMap;
    delete showLayer;
    delete minefactory;
    delete showfactory;

    return 0;
}