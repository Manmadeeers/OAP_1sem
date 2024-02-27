#include <iostream>//подключение стандартной библиотеки
int nod(int a, int b)//функция , выполняющая Евклидов алгоритм
{
	while (b != 0) {//цикл
		int temp = b;
		b = a % b;//если большее число делится на меньшее , то меньшее и будет из НОД
		a = temp;
	}
	return a;
}
int nod3(int x, int y, int z)//спецификация алгоритма Евклида для трёх чисел
{
	return nod(nod(x, y), z);
}
void main()//функция main
{
	using namespace std;//можно не прописывать std
	setlocale(LC_CTYPE, "Russian");//локализация
	int x, y, z;//объявление типа данных для переменных
	//ввод x,y,z с клаиатуры и в систему
	cout << "Введите х: ";
	cin >> x;
	cout << "Введите у: ";
	cin >> y;
	cout << "Введите z: ";
	cin >> z;
	int result = nod3(x, y, z);//вычисление НОД 
	cout << "Наибольший общий делитель: " << result;//вывод НОД на экран
}