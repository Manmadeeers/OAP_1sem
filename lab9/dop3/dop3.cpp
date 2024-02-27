#include <iostream>
using namespace std;
double f(double x)//функция , возвращающая функицю из условия
{
	double y = pow(sin(x), 2) + 1;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 2, b = 7, n = 200;//задание значений и определение типа данных переменных
	double h = (b - a) / n, S = 0;
	for (double x = a; x <= (b - h); x += h) {//цикл, реализуюий метод трапеций
		S += h * (f(x) + f(x + h)) / 2;//увеличение суммы площадей каждого разбиения с каждой итерацией цикла
	}
	cout << "S=" << S << endl;//вывод ответа на экран
}