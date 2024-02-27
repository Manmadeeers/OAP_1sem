#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	cout << "Введите кол-во дней измерений:";//ввод кол-ва дней , в которые проодились измерения
	cin >> n;
	double X[100] = {};//массив , содержащий все измерения
	srand((unsigned)time(NULL));//функция для неповторяющихся значений 
	for (int i = 0; i < n; i++) {//цикл, вводящий рандомные элементы в массив
		X[i] = (int)(((double)rand() / (double)RAND_MAX)*99);
		cout << X[i]<<" ";//вывод элементов массива на экран
	}
	int Maxrainfall = 0;//задание переменной для максимального кол-ва осадков
	int maxweek = 0;//неделя с максимальным кол-вом осадков
	for (int i = 0; i < n-6; i+=7) {//цикл, проходящийся по неделям
		int weeklyrainfall = 0;
		for (int j = 0; j < 7; j++) {//цикл , проходяшийся по дням недели
			weeklyrainfall += X[i + j];//прибавление к осадкам за неделю
		}
		if (weeklyrainfall > Maxrainfall) {//условие для вычисления недели с макс. кол-вом осадков
			Maxrainfall = weeklyrainfall;
			maxweek = i / 7;
		}
	}
	cout << "\nНеделя с максимальным кол-вом осадков:" << maxweek + 1 << endl;//вывод ответа на экран
}