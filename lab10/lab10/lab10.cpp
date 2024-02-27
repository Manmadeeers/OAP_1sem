#include <iostream>
#include <ctime>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 100;
	int sz,rmn=0,rmx=99;
	cout << "Введите размер массива:";
	cin >> sz;
	double M[N] = {};
	srand((unsigned)time(NULL));
	for (int i = 0; i < sz; i++) {
		M[i] = (int)(((double)rand()/(double)RAND_MAX)*(rmx-rmn)+rmn);
		cout << M[i] << endl;
	}
	double min = M[0];
	for (int i = 0; i < sz; i++) {
		if (M[i] < min) {
			min = M[i];
		}
	}
	cout << "Минимальное значение:" << min << endl;
	cout << "Новый массив:" << endl;
	for (int i = 0; i <= sz; i++) {
		if (i % 2 == 0) {
			M[i] = min;
		}
		cout << M[i] << endl;
	}

}