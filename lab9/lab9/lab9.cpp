//метод трапеций
#include <iostream>
using namespace std;
double f(double x) {//функция , определяющая функцию f(x)
	return exp(x) + 6;//возврат функции из условия
}
double trap(double a,double b,int n)//функция , считающая лощадь криволинейной трапеции по заданным данным 
{
	double h = (b - a) / n, S = 0;//определение интервала h
	for (int i = 0; i <= n; i++) {//цикл , отвечающий за суммирование площадей каждого разбиения
		double x = a + i * h;//изменение переменной х с каждой итерацией
		double y = f(x);//функция f(x) , заданная в условии
		if (i == 0 || i == n) {
			S += y;
		}
		else {
			S += 2 * y;
		}
	}
	return (h / 2) * S;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b;
	int n;
	cout << "Ввод а: ";
	cin >> a;
	cout << "Ввод b:";
	cin >> b;
	cout << "Ввод кол-ва разбиений:";
	cin >> n;
	double Sq = trap(a, b, n);//вычисление площади функцией trap по введённым a,b,n
	cout << "Площадь трапеции равна " << Sq << endl;//вывод ответа на экран
}