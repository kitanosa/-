#include "figures.h"
#include "functions.h"
#include <iostream>
#include <tuple>

void menu() {
    std::cout << "Enter 0-5 to:" << std::endl;
    std::cout << "1 - add a pentagon" << std::endl;
    std::cout << "2 - add a hexagon" << std::endl;
    std::cout << "3 - add an octagon" << std::endl;
    std::cout << "4 - print all coordinates of figures" << std::endl;
    std::cout << "5 - find the total square" << std::endl;
    std::cout << "0 - exit" << std::endl;
}

void error() {
    std::cout << "Incorrect value!" << std::endl;
}

int main() {
    int choice, type;
    double side;
    menu();
    std::tuple<Pentagon<double>, Pentagon<int>, Hexagon<double>, Hexagon<int>, Octagon<double>, Octagon<int>> all; // <int> приведению к типу int, кортежи описываются шаблонным классом std::tuple<>
    std::cout << "Your choice: ";

    do {
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                std::cout << "What datatype of shape coordinates do you want? int(1) or double(2)? ";
                std::cin >> type;
                if (type > 2) {
                    error();
                }
                else {
                    std::cout << "Enter pentagon side: ";
                    std::cin >> side;
                    if (type == 2) {
                        get_coords_pentagon(std::get<0>(all), side);// all это название наверное
                    }
                    else if (type == 1) {
                        get_coords_pentagon(std::get<1>(all), int (side));
                    }
                }
                break;
            case 2:
                std::cout << "What datatype of shape coordinates do you want? int(1) or double(2)? ";
                std::cin >> type;
                if (type > 2) {
                    error();
                }
                else {
                    std::cout << "Enter hexagon side: ";
                    std::cin >> side;
                    if (type == 2) {
                        get_coords_hexagon(std::get<2>(all), side);
                    }
                    else if (type == 1) {
                        get_coords_hexagon(std::get<3>(all), int (side));
                    }
                }
                break;
            case 3:
                std::cout << "What datatype of shape coordinates do you want? int(1) or double(2)? ";
                std::cin >> type;
                if (type > 2) {
                    error();
                }
                else {
                    std::cout << "Enter octagon side: ";
                    std::cin >> side;
                    if (type == 2) {
                        get_coords_octagon(std::get<4>(all), side);
                    }
                    else if (type == 1) {
                        get_coords_octagon(std::get<5>(all), int (side));
                    }
                }
                break;

            case 4:
                print_tuple<decltype(all), 0>(all);
                break;
            case 5:
                std::cout <<"Total square of figures is "<< square(all)<<std::endl;
                break;
            case 0:
                std::cout << "The program is closed, goodbye!\n";
                return false;
                break;
            default:
                std::cout << "Incorrect values! Try again.\n";
                break;
        }
        std::cout << "What's next?\n";
        std::cout << ">>";
    } while (choice);

    return 0;
}
