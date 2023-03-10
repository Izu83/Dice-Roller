#include <iostream>
#include <ctime>
#include <unistd.h>

void menu()
{
    std::cout << "\t\tDice roller (D6)\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "Do you want to start? [Y/N]: ";
}

int random_num(int min, int max)
{
    srand(time(NULL));
    return rand() % max + min;
}

enum Dice_6
{
    D1 = 1, D2 = 2, D3 = 3, D4 = 4, D5 = 5, D6 = 6
    
};



void num_to_dice(Dice_6 &dice, int &num)
{
    if(num == 1)
    {
        dice = D1;
    }
    else if(num == 2)
    {
        dice = D2;
    }
    else if(num == 3)
    {
        dice = D3;
    }
    else if(num == 4)
    {
        dice = D4;
    }
    else if(num == 5)
    {
        dice = D5;
    }
    else if(num == 6)
    {
        dice = D6;
    }
}

int main()
{
                    START:         // Now we can use the goto method to start over
    // Menu
    system("cls");
    Dice_6 dice;
    menu();
    // Option for quit
    std::string *y_n_choice = new std::string;
    getline(std::cin, *y_n_choice);
    if((*y_n_choice) == "N" || (*y_n_choice) == "n")
    {
        std::cout << "\nOk, bye!!!";
        return 0;
    }
    system("cls");
    std::cout << "----------------------------------------------\n";
    // countdown
    for(size_t i = 3; i > 0; i--)
    {
        std::cout << "The dice will roll after: " << i << " seconds\n";
        sleep(1);
    }
    // random number generator
    int rand_num = random_num(1, 6);
    num_to_dice(dice, rand_num);
    // display dice
    std::cout << "----------------------------------------------\n";
    std::cout << "Dice turned out to be: " << dice << std::endl;
    std::cout << "\n\n\n";
    switch(dice)
    {
        case D1:
            std::cout   << "/---------------\\\n"
                        << "|               |\n"
                        << "|               |\n"
                        << "|       *       |\n"
                        << "|               |\n"
                        << "|               |\n"
                        << "\\---------------/\n";
        break;
        case D2:
            std::cout   << "/---------------\\\n"
                        << "|               |\n"
                        << "|    *          |\n"
                        << "|               |\n"
                        << "|          *    |\n"
                        << "|               |\n"
                        << "\\---------------/\n";
        break;
        case D3:
            std::cout   << "/---------------\\\n"
                        << "|               |\n"
                        << "|    *          |\n"
                        << "|       *       |\n"
                        << "|          *    |\n"
                        << "|               |\n"
                        << "\\---------------/\n";
        break;
        case D4:
            std::cout   << "/---------------\\\n"
                        << "|               |\n"
                        << "|   *       *   |\n"
                        << "|               |\n"
                        << "|   *       *   |\n"
                        << "|               |\n"
                        << "\\---------------/\n";            
        break;
        case D5:
            std::cout   << "/---------------\\\n"
                        << "|               |\n"
                        << "|   *       *   |\n"
                        << "|       *       |\n"
                        << "|   *       *   |\n"
                        << "|               |\n"
                        << "\\---------------/\n";
        break;
        case D6:
            std::cout   << "/---------------\\\n"
                        << "|               |\n"
                        << "|   *       *   |\n"
                        << "|   *       *   |\n"
                        << "|   *       *   |\n"
                        << "|               |\n"
                        << "\\---------------/\n";
        break;

    }
    std::cout << "\n\n\n";
    std::cout << "----------------------------------------------\n";
    system("pause");
    goto START;
}