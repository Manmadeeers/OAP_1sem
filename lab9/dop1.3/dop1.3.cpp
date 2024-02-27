//метод дихотомии
#include <iostream>
using namespace std;
double f(double x)//функция , возвращающая функцию из условия
{
	double y = exp(x) + x - 4;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 8, b = 14, e = 0.0001,x;//задание типпа данных и вычисление значений переменных
	do {//цикл, реализующий метод дихотомии
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) <= 2 * e);//условие завершения цикл
	cout << "X=" << x << endl;//вывод ответа на экран
}