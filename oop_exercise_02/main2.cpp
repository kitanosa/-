#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>

const double MAX_AVAILABLE_ANGLE = 2 * M_PI;

class Complex{
    private:
        double  r;
        double phi;
        
    public:
        Complex(){
            r = 1;
            phi = 90;
        }
        Complex(double  newr, double  newphi){
            r = newr;
            phi = newphi;
        }
        bool operator==(const Complex &other){// Скрытый указатель *this. const здесь чтобы члучайно ничего не поменяли. Передаем по адресу чтобы не выделять память
            return (this->r == other.r) && (this->phi == other.phi);//&other мы передаем адрес чтобы не копировать значение а пользоваться ссылкой на тот же самый переданный элемент
        }// но код работает даже если other передавать и НЕ по ссылке
        bool operator!=(const Complex &other){// Синтаксис перегрузки операторов очень похож на определение функции с именем operator
            return !((this->r == other.r) && (this->phi == other.phi));
        }
        bool operator>(const Complex &other){
            return (this->r * cos(this->phi)) > (other.r * cos(other.phi));
        }
        bool operator>=(const Complex &other){
            return (this->r * cos(this->phi)) >= (other.r * cos(other.phi));
        }
        bool operator<(const Complex &other){
            return (this->r * cos(this->phi)) < (other.r * cos(other.phi));
        }
        bool operator<=(const Complex &other){
            return (this->r * cos(this->phi)) <= (other.r * cos(other.phi));
        }
        void SetR(double radius){
            if (radius < 0){
               std::cout << "Radius can't be lesser than zero!" << std::endl;
               return;
            }
            this->r = radius;
        }
        void SetAngle(double angle){
            this->phi = angle;
        }
        double GetR() const{
            return this->r;
        }
        double GetAngle() const{
            return this->phi;
        }
        friend std::istream& operator>>(std::istream &in, Complex &complex);// фрэндим чтобы пользоваться приватными элементами
    // френдить надо чтобы другому классу либо функции было доступны поля protected и privat
    // френдить можно как классы так и функции в других классах по отдельности
    // подробнее в "Дружеские функции класса C++"
    // причем в friend мы в аргументы передаем либо класс либо функцию которой разрешаем пользоваться другому классу
    // например
    // friend class Hunter;// тут зафрендили класс Hunter
    // frind Hunter::kill(Fox &); // тут разрешили классу Hunter где лежит функция kill пользоваться приватными элементами Fox. Передаем по адресу чтобы изменить приватное поле в самом Fox
};

void Check_bounds(double angle){
            if (angle > MAX_AVAILABLE_ANGLE){
                angle -= MAX_AVAILABLE_ANGLE;
            }
            if (angle < MAX_AVAILABLE_ANGLE){
                angle += MAX_AVAILABLE_ANGLE;
            }
        }

Complex Conj(Complex x){
    double res = x.GetAngle();
    res = -res;
    x.SetAngle(res);
    return x;
}
Complex operator+(Complex one, Complex other){// оператор перегрузки используется в сложении векторов например
    Complex res;
    double  fpart = one.GetR() * cos(one.GetAngle()) + other.GetR() * cos(other.GetAngle());// first part
    double  spart = one.GetR() * sin(one.GetAngle()) + other.GetR() * sin(other.GetAngle());
    res.SetR(sqrt(fpart * fpart + spart * spart));
    res.SetAngle(acos(fpart / res.GetR()));
    return res;
}

Complex operator-(Complex one, Complex other){
    Complex res;
    double  newangle = other.GetAngle() + M_PI;
    Check_bounds(newangle);
    return res + other;
}
Complex operator*(Complex &one, Complex &other){
    Complex res;
    res.SetR(one.GetR() * other.GetR());
    res.SetAngle(one.GetAngle() + other.GetAngle());
    Check_bounds(res.GetAngle());
    return res;
}
Complex operator/(Complex &one, Complex &other){
    Complex res;
    res.SetR(one.GetR() / other.GetR());
    res.SetAngle(one.GetAngle() - other.GetAngle());
    Check_bounds(res.GetAngle());
    return res;
}

const Complex operator"" _complex(const char *str, size_t size){// пользовательский литерал
    std::stringstream ss;
    double one, two;
    ss.str(str);
    ss.ignore(1);
    ss >> one;
    ss.ignore(1);
    ss >> two;
    return {one, two};
}

std::istream& operator>>(std::istream &in, Complex &complex){// оператор ввода
    in >> complex.r;
    in >> complex.phi;

    return in;
}

std::ostream& operator<<(std::ostream &out, const Complex &x){// оператор вывода
    out << "(" << x.GetR() << "," << x.GetAngle() << ")";
    return out;
}

Complex Sum(Complex a, Complex b){
    return a + b;
}

Complex Subtract(Complex &a, Complex &b){
    return a - b;
}

Complex Multy(Complex &a, Complex &b){
    return a * b;
}

Complex Divide(Complex &a, Complex &b){
    return a / b;
}

int main(){
    Complex example = "(14,36)"_complex;
    Complex a,b;
    int choice;
    bool work = true;
    while(work){
        std::cout << "Menu:" << std::endl << "1. Sum two complex numbers." << std::endl << "2. Subtract two complex numbers." << std::endl << "3. Multiply two complex numbers." << std::endl << "4. Divide two complex numbers." << std::endl << "5. Compare two complex numbers." << std::endl << "6. Print conjugate for complex number." << std::endl << "7. Quit." << std::endl << "Enter the menu item -> ";
        std::cin >> choice;
        switch (choice){
            case 1:
                std::cin >> a >> b;
                std::cout << a << " + " << b << " = "  << Sum(a,b) << std::endl << std::endl;
                break;
            case 2:
                std::cin >> a >> b;
                std::cout << a << " - " << b << " = "  << Subtract(a,b) << std::endl << std::endl;
                break;
            case 3:
                std::cin >> a >> b;
                std::cout << a << " * " << b << " = "  << Multy(a,b) << std::endl << std::endl;
                break;
            case 4:
                std::cin >> a >> b;
                std::cout << a << " / " << b << " = "  << Divide(a,b) << std::endl << std::endl;
                break;
            case 5:
                std::cin >> a >> b;
                if (a < b){
                    std::cout << a << " < " << b << " (lesser)" << std::endl;
                }
                else{
                    std::cout << a << " >= " << b << " (not lesser)" << std::endl;
                }
                if (a > b){
                    std::cout << a << " > " << b << " (greater)" << std::endl;
                }
                else{
                    std::cout << a << " <= " << b << " (not greater)" << std::endl;
                }
                if (a == b){
                    std::cout << a << " = " << b << " (equal)" << std::endl;
                }
                else{
                    std::cout << a << " != " << b << " (not equal)" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 6:
                std::cin >> a >> b;
                std::cout << "Conjugate number for " << a << " is " << Conj(a) << std::endl;
                std::cout << "Conjugate number for " << b << " is " << Conj(b) << std::endl << std::endl;
                break;
            case 7:
                work = false;
                break;
            default:
                std::cout << "Wrong menu item!" << std::endl << std::endl;
                work = false;
                break;
        }   
    return 0;
}
}
