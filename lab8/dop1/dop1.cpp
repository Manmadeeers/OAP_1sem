//dop1
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int n[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };//массив n ,представляющий собой числовую последовательность
	int lengthn = sizeof(n) / sizeof(n[0]);//вычисление размера массива n
	int sum = 0;
	for (int i = 0; i < lengthn; i++) {//цикл, вычисляющий сумму чётных элементов массива
		if (i % 2 != 0) {
			sum += n[i];
		}
	}
	cout << "Сумма чётных элементов массива: " << sum << endl;//вывод суммы на экран
}