#include <iostream>
using namespace std;
double f(double x)//функция , возвращающая функцию из условия
{
	double y = sin(x) + 2 + x;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "RUS");
	double a = 2, b = 7, e = 0.0001, x;//ввод значений и поределение типов данных переменных
	do {//цикл, реализующий метод дихотомии
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}

	} 
	while (abs(a - b) <= 2 * e);//условие завершения цикла
	cout << "X=" << x << endl;//вывод ответа на экран

}