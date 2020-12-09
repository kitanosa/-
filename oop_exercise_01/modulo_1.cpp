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

	void sum(int first_number, int second_number, int module_N) {
		result = (first_number + second_number) % module_N;
	}
	int get_sum() {
		return result;
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
	Example.sum(N);
	cout << "Первое число = " << Example_1.number << " Второе число = " << Example_2.number << " Модуль = " << N << "\n";
	cout << "Сумма = " << Example.get_sum() << "\n";
	return 0;
}
