//метод парабол
#include <iostream>
using namespace std;
double func(double x)//функция , определяющая фнкцию из условия
{
	double y = exp(x) + 6;//функция из условия 
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double S1 = 0, S2 = 0, n, a, b;//определение s1,s2 и ввод a,b,n
	cout << "Ввод а:";
	cin >> a;
	cout << "Ввод b:";
	cin >> b;
	cout << "Ввод кол-ва разбиений:";
	cin >> n;
	double h = (b - a) / (2*n);//вычисление значения h
	double x = a + 2 * h;//вычисление значения x
	for (int i = 1; i <= n; i++) {//цикл , котрый проходится по каждому из разбиений 
		S1 += func(x);//уыеличение s1
		x += h;//увеличение х
		S2 += func(x);//увеличение s2
		x += h;//увеличение х
	}
	double S = h / 3 * (func(a) + 4 * func(a + h) + 4 * S1 + 2 * S2 + func(b));//вычисление итогового значения суммы площадей
	cout << "S = " << S << endl;//вывод ответа на экран

}