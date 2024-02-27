#include <iostream>
using namespace std;
double f(double x)//функция , возвращающа функцию из условия
{
	double y = pow(x, 3) + x - 2;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 1, b = 4, e = 0.0001,x;//задание значений  и определение типпа данных переменных
	do {//цикл, реализующий метод дихотомии
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) <= 2 * e);//условие завершения цикла
	cout << "X=" << x << endl;//вывод ответа на экран
}