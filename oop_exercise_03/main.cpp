#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double deg72 = (72*M_PI)/180;
double deg36 = (36*M_PI)/180;
double deg60 = (60 * M_PI) / 180;
double deg45 = (45 * M_PI) / 180;

class Figure {
protected:
    int side;
    double area;

public:
    double getArea () {
        return this->area;
    }
    virtual void showCenter() = 0;
    virtual void showCoordinates() = 0;
    virtual void showArea() = 0;
};

class Pentagon : public Figure {
public:
    Pentagon(int side) {
        this->side = side;
        this->area = ((this->side*this->side)/4.0)*sqrt(25+10*sqrt(5));
    }

    void showCenter() override {
        cout << "Center coordinates: (" << side*cos(deg72)+0.5*side << ", " << (side*sin(deg72)+side*sin(deg36))/2 << ")" << endl;
    }

    void showCoordinates() override {
        cout << "A(" << side*cos(deg72) << "; " << 0 << ")" <<endl;
        cout << "B(" << side*cos(deg72)+side << "; " << 0 << ")" <<endl;
        cout << "C(" << 2*side*cos(deg72)+side << "; " << side*sin(deg72) << ")" <<endl;
        cout << "D(" << side*cos(deg72)+0.5*side << "; " << side*sin(deg72)+side*sin(deg36) << ")" <<endl;
        cout << "E(" << 0 << "; " << side*sin(deg72) << ")" <<endl;
    }

    void showArea() override {
        cout << "Area is: " << this->area << endl;
    }
};

class Hexagon : public Figure {
public:
    Hexagon(int side) {
        this->side = side;
        this->area = ((3*sqrt(3))/2)*side*side;
    }

    void showCenter() override {
        cout << "Center coordinates: (" << 1.5*side << "; " << side * sin(deg60) << ")" << endl;
    }

    void showCoordinates() override {
        cout << "A(" << 0.5 * side << "; " << 0 << ")" << endl;
        cout << "B(" << 1.5 * side << "; " << 0 << ")" << endl;
        cout << "C(" << 2 * side << "; " << side * sin(deg60) << ")" << endl;
        cout << "D(" << 1.5 * side << "; " << 2 * side * sin(deg60) << ")" << endl;
        cout << "E(" << 0.5 * side << "; " << side * sin(deg60) << ")" << endl;
        cout << "F(" << 0 << "; " << side * sin(deg60) << ")" << endl;
    }

    void showArea() override {
        cout << "Area is: " << this->area << endl;
    }

};

class Octagon : public Figure {
public:
    Octagon(int side) {
        this->side = side;
        this->area = 2*side*side*(1 + sqrt(2));
    }

    void showCenter() override {
        cout << "Center coordinates: (" << side * cos(deg45) + side/2 << ";" << side * cos(deg45) + side/2 << ")" << endl;
    }

    void showCoordinates() override {
        cout << "A(" << side*cos(deg45) << "; " << 0 << ")" << endl;
        cout << "B(" << side * cos(deg45) + side << "; " << 0 << ")" << endl;
        cout << "C(" << 2*side * cos(deg45) + side << "; " << side * sin(deg45) << ")" << endl;
        cout << "D(" << 2 * side * cos(deg45) + side << "; " << side * sin(deg45) + side << ")" << endl;
        cout << "E(" << side * cos(deg45) + side << "; " << 2 * side * cos(deg45) + side << ")" << endl;
        cout << "F(" << side * cos(deg45) << "; " << side * sin(deg45) << ")" << endl;
        cout << "G(" << 0 << "; " << side * cos(deg45) + side << ")" << endl;
        cout << "K(" << 0 << "; " << side * cos(deg45) << ")" << endl;
    }

    void showArea() override {
        cout << "Area is: " << this->area << endl;
    }

};

void menu() {
    cout << "Enter 0-7 to:" << endl;
    cout << "1 - add a pentagon" << endl;
    cout << "2 - add a hexagon" << endl;
    cout << "3 - add an octagon" << endl;
    cout << "4 - find the total area" << endl;
    cout << "5 - call all common functions" << endl;
    cout << "6 - delete the n-th object" << endl;
    cout << "7 - find out the area, coordinates and geometric center of the n-th figure" << endl;
    cout << "0 - exit" << endl;
}

int main() {

    vector<Figure*> vec;
    int a;
    double total = 0;
    int index, num = 1;

    Figure* figure;
    menu();

    int choice;
    do {
        cout << "Menu function: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter pentagon side: ";
                cin >> a;
                figure = new Pentagon(a);
                vec.push_back(figure);
                break;
            case 2:
                cout << "Enter hexagon side: ";
                cin >> a;
                figure = new Hexagon(a);
                vec.push_back(figure);
                break;
            case 3:
                cout << "Enter octagon side: ";
                cin >> a;
                figure = new Octagon(a);
                vec.push_back(figure);
                break;
            case 4:
                for (const auto&obj: vec) {
                    total += obj->getArea();
                }
                cout <<"The total area of the figures is " << total << endl;
                total = 0;
                break;
            case 5:
                for (const auto& obj : vec) {
                    std::cout << "Figure " << num <<":\n";
                    obj->showCenter();
                    obj->showCoordinates();
                    obj->showArea();
                    cout << "\n";
                    num++;
                }
                num = 1;
                break;
            case 6:
                cout << "Which figure number do you want to delete? ";
                cin >> index;
                vec.erase(vec.begin() + (index - 1));
                cout << "Done!\n";
                break;
            case 7:
                cout << "What figure do you want to print? (enter her number) ";
                cin >> index;
                vec[index - 1]->showCenter();
                vec[index - 1]->showCoordinates();
                vec[index - 1]->showArea();
                break;
            case 0:
                cout << "The program is closed, goodbye!\n";
                break;
            default:
                cout << "Incorrect values! Try again.\n";
                return 0;
                break;
        }
    } while (choice);


    return 0;
}
