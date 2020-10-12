#include <iostream>

using namespace std;

class Modulo // программисты предпочитают называть класс с большой буквы
{
private:
		int result;

public: 
		int first_number, second_number;

		Modulo(int a, int b) {
			first_number = a;
			second_number = b;
		}

		void sum(int module_N) {
			result = (first_number + second_number) % module_N;
		}
		int get_sum() {
			return result;
		}

		void diff(int module_N) {// разность
			result = (first_number - second_number) % module_N;
		}
		int get_diff() {
			return result;
		}

		void mult(int module_N) {// произведение
			result = (first_number * second_number) % module_N;
		}
		int get_mult() {
			return result;
		}

		void division(int module_N) {// деление
			result = (first_number / second_number) % module_N;
		}
		int get_division() {
			return result;
		}

		void comparison(int module_N) {// сравнение
			if ((first_number % module_N) > (second_number % module_N)) {
				cout << "Остаток первого больше чем второго" << "\n";
			}
			else if ((first_number % module_N) < (second_number % module_N)) {
				cout << "Остаток первого меньше чем второго" << "\n";
			}
			else {
				cout << "Числа сравнимы" << "\n";
			}
		}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, N;
	cout << "Введите два числа и модуль" << "\n";
	cin >> a >> b >> N;
	if (N == 0) {
		cout << "Модуль введен неверно" << "\n";
		cin >> N;
	}
	Modulo Example(a, b);
	Example.sum(N);
	cout << "Первое число = " << Example.first_number << " Второе число = " << Example.second_number <<
		" Модуль = " << N << "\n" << "Сумма = " << Example.get_sum() << "\n";
	Example.diff(N);
	cout << "Разность = " << Example.get_diff() << "\n";
	Example.mult(N);
	cout << "Произведение = " << Example.get_mult() << "\n";
	if ((Example.second_number % N) == 0) {
		cout << "Нельзя сделать деление" << "\n";
	}
	else {
		Example.division(N);
		cout << "Деление = " << Example.get_division() << "\n";
	}
	Example.comparison(N);
	return 0;
}
