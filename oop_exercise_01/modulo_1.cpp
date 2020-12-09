#include <iostream>

using namespace std;

class Modulo // программисты предпочитают называть класс с большой буквы
{
private:
		int result;

	public:
		int number, module_N;

		Modulo(int a, int N) {
			number = a;
			module_N = N;
		}

		void sum(Modulo m1, Modulo m2) {
			result = (m1.number + m2.number) % m1.module_N;
		}

		int get_sum() {
			return result;
		}

		void diff(Modulo m1, Modulo m2) {// разность
			result = (m1.number - m2.number) % m1.module_N;
		}
		int get_diff() {
			return result;
		}

		void mult(Modulo m1, Modulo m2) {// произведение
			result = (m1.number * m2.number) % m1.module_N;
		}
		int get_mult() {
			return result;
		}

		void division(Modulo m1, Modulo m2) {// деление
			result = (m1.number / m2.number) % m1.module_N;
		}
		int get_division() {
			return result;
		}

		void comparison(Modulo m1, Modulo m2) {// сравнение
			if ((m1.number % m1.module_N) > (m2.number % m1.module_N)) {
				cout << "Остаток первого больше чем второго" << "\n";
			}
			else if ((m1.number % m1.module_N) < (m2.number % m1.module_N)) {
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
	if (N <= 0 ) {
		cout << "Модуль введен неверно" << "\n";
		cin >> N;
	}

	Modulo Example_1(a, N);
	Modulo Example_2(b, N);
	Example_1.sum(Example_1, Example_2);
	cout << "Первое число = " << Example_1.number << " Второе число = " << Example_2.number << " Модуль = " << N << "\n";
	cout << "Сумма = " << Example_1.get_sum() << "\n";

	Example_1.diff(Example_1, Example_2);
	cout << "Разность = " << Example_1.get_diff() << "\n";

	Example_1.mult(Example_1, Example_2);
	cout << "Произведение = " << Example_1.get_mult() << "\n";
	if ((Example_1.number % N) == 0) {
		cout << "Нельзя сделать деление" << "\n";
	}
	else {
		Example_1.division(Example_1, Example_2);
		cout << "Деление = " << Example_1.get_division() << "\n";
	}
	Example_1.comparison(Example_1, Example_2);
	return 0;
}
