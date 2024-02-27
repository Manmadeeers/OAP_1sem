// метод трапеций
#include <iostream>
using namespace std;
double f(double x)//функция , озвращающая функцию из условия
{
	double y = pow(x, 4) + 4;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 1, b = 4, n = 200;//ввод типа данных и определение значений переменных
	double h = (b - a) / n, S = 0;
	for (double  x=a; x <= (b-h); x+=h) {//цикл , проходящийся по каждому из разбиений
		S += h * (f(x) + f(x + h)) / 2;//увеличение суммы площадей с каждой итерацией
	}
	cout << "S=" << S << endl;//вывод ответа на экран
}