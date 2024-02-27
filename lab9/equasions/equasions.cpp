//метод дихотомии
#include <iostream>
using namespace std;
double f(double x)//функция , определяющая функцию из условия
{
	double y = pow(x, 3) +( 2 * x) - 4;//функция из условия
	return y;
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 5, b = 11, e = 0.0001,x;//ввод значений и определение типов двнных переменных 
	do {//цикл , реализующий метод дихотомии
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