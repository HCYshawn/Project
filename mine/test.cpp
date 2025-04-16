#include "game.h"
#include "class.h"
#include "client.h"
#include "print.h"
/*
2.0 -> 2025_3_29 ~ 2025_4_16


*/

void game()
{
    int select = 1;
    do
    {
        print_welcome();
        std::cout << "please select: ";

        if (!(std::cin >> select))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            select = -1;
        }

        if (select == 1)
        {
            print_menu();
            int i = 0;
            std::cin >> i;
            switch (i)
            {
            case 0:
            {
                std::cout << "exit" << std::endl;
                break;
            }
            case 1:
            {
                Client client(ROW1, COL1, GAMEMINE1, 0, 0);
                client.Play();
                break;
            }
            case 2:
            {
                Client client(ROW2, COL2, GAMEMINE2, 0, 0);
                client.Play();
                break;
            }
            case 3:
            {
                Client client(ROW3, COL3, GAMEMINE3, 0, 0);
                client.Play();
                break;
            }
            case 4:
            {
                int row = 0;
                int col = 0;
                int mine = 0;
                std::cout << "please input row col win: ";
                std::cin >> row >> col >> mine;
                Client client(row, col, mine, 0, 0);
                client.Play();
                break;
            }
            default:
            {
                std::cout << "error" << std::endl;
                break;
            }
            }
        }
        else if (select == 2)
        {
            int lang_choice;
            bool exit_lang_menu = false;

            do
            {
                std::cout << "please select a description language: " << std::endl;
                std::cout << "1. 中文 2. ENGLISH 0.EXIT " << std::endl;
                int j = 0;
                std::cout << "please select: ";

                if (!(std::cin >> lang_choice))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Error: Please enter the numeric option!\n";
                    continue;
                }

                switch (lang_choice)
                {
                case 1:
                    print_description_chinese();
                    break;
                case 2:
                    print_description_english();
                    break;
                case 0:
                    exit_lang_menu = true;
                    break;
                default:
                    std::cout << "error,please re-enter" << std::endl;
                }
            } while (!exit_lang_menu);
        }
        else if (select == 0)
        {
            std::cout << "game exit...\n";
            break;
        }
        else
        {
            std::cout << "error,please re-enter\n";
        }
    } while (true);
}

int main()
{
    // SetConsoleOutputCP(CP_UTF8);
    game();
    return 0;
}