#include <iostream>
using namespace std;
double f(double x)//функция , возвращающая функцию из условия
{
	double y = pow(sin(x), 2) + 1;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 1, b = 7, n = 200;//задание значений и определение типа данных переменных
	double h = (b - a) / (2 * n), x = a + 2 * h, S1 = 0, S2 = 0;
	for (int i = 0; i <= n; i++) {//цикл, реализующий метод параол
		S1 += f(x);
		x += h;
		S2 += f(x);
		x+=h;
	}
	double S = (h / 3) * (f(a) + 4 * f(a + h) + 4 * S1 + 2 * S2 + f(b));//рассчёт итогового значения площади
	cout << "S=" << S << endl;//вывод ответа на экран
}