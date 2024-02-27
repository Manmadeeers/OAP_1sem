#include <iostream>
using namespace std;
double f(double x)//функция , возвращающая функцию из условия
{
	double y = pow(x, 4) + 4;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a = 1, b = 4, n = 200;//ввод значений и определегие типов данных переменных
	double h = (b - a) / (2 * n), x = a + 2 * h, S1 = 0, S2 = 0;
	for (int i = 1; i <= n; i++) {//цикл , реалтизующий метод парабол 
		S2 += f(x);
		x += h;
		S1 += f(x);
		x += h;
	}
	double S = (h / 3) * (f(a) + 4 * f(a + h) + 4 * S1 + 2 * S2 + f(b));//Вычисление итоговой площади
	cout << "S=" << S << endl;//вывод ответа на экран
}