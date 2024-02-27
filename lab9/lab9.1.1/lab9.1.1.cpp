//метод трапеций
#include <iostream>
using namespace std;
double func(double x)//функция ,задающая переменной у функцию из условия
{
	double y = exp(x) + 6;//функция из условия
	return y;
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b, n;//ввод a,b,n
	cout << "Ввод а:";
	cin >> a;
	cout << "Ввод b";
	cin >> b;
	cout << "Ввод кол-ва разбиений:";
	cin >> n;
	double h = (b - a) / n,S=0;//вычисление h и присвоение S 0
	double x = a;
	for (int i=0; i <=n; i++) {//цикл ,который проходитс по каждому разбиению и суммирует площади
		x = a + i * h;//увеличение х с каждой итерацией
		S += h * (func(x) + func(x + h)) / 2;//увеличение суммы площадей с каждой итерацией

	}
	cout << "S=" << S << endl;//вывод ответа на экран
}