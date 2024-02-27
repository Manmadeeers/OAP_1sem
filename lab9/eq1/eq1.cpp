//dop1 метод трапеций
#include <iostream>
using namespace std;
double f(double x)//функция ,возвращающая функуию из условия
{
	double y = 2 + pow(x, 3);//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 8, b = 14, n = 200,S=0;//определение типпа данных и вычисление значения переменных
	double h = (b - a) / n , x=a;
	for (int i = 0; i <= n; i++) {//цикл , который проходится по каждому из разбиений
		x = a + i * h;//увеличение х с каждой итерацией
		S += h * (f(x) + f(x + h)) / 2;//увеличение общей площади с каждой итерацией
	}
	cout << "S=" << S << endl;//вывод ответа на экран
}