#include <iostream>
using namespace std;
void ColomnCheck(int**matrix,int amm_of_rows,int amm_of_colomns)//функция для изменения матрицы
{
	int* num_of_colomns;//создание указателя на область памяти 
	num_of_colomns = new int[amm_of_rows];//выделение динамической памяти под массив , содержащий номера положительных столбцов
	int amm = 0;//создание счётной переменной для подсчёта кол-ва положительных столбцов
	for (int i = 0; i < amm_of_colomns; i++) {//цикл в цикле для вычисления таких столбцов
		int control_var = 0;//создание контрольной счётной переменной для контроля элементво столбцов
		for (int j = 0; j < amm_of_rows; j++) {
			if (matrix[j][i] > 0) {//если элемент положителен
				control_var++;//увеличение контрольной переменной на 1
			}
		}
		if (control_var == amm_of_rows) {//если контролльная переменная равна кол-ву строк
			*(num_of_colomns + amm) = i;//добавить номер столбца в массив
			amm++;//увеличение счётной переменной на 1
		}
	}
	cout << "Номера положительных столбцов:";
	for (int i = 0; i < amm; i++) {//цикл для вывода номеров положительных столбцов
		cout << *(num_of_colomns + i)+1 << ' ';
	}
	for (int i = 0; i < amm; i++) {//цикл в цикле для изменения заданых по условию столбцов
		for (int j = 0; j < amm_of_rows; j++) {
			matrix[j][*(num_of_colomns + i) - 1] = -matrix[j][*(num_of_colomns + i) - 1];//поменять знаки предыдущих положительным столбцов
		}
	}
	cout << "\nМатрица после изменения:" << endl;	
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	delete[]num_of_colomns;//очистка динамической памяти под массив
}



void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация 
	int amm_of_rows;//ввод кол-ва строк
	cout << "Введите кол-во строк:";
	cin >> amm_of_rows;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буффера после ввода
	int amm_of_colomns;//ввод кол-ва столбцов
	cout << "Введите кол-во столбцов:";
	cin >> amm_of_colomns;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буффера после ввода
	int** matrix;//создание указателя на область памяти для массива
	matrix = new int* [amm_of_rows];//выделеие динамеческой памяти под матрицу
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элементов матрицы
		matrix[i] = new int[amm_of_colomns];//создание динамической памяти под строку
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];//ввод элемента
		}
	}
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода введённой матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	ColomnCheck(matrix, amm_of_rows, amm_of_colomns);//использование вышеописанной функции
	for (int i = 0; i < amm_of_colomns; i++) {//цикл для очистки динамической памяти под строки
		delete[]matrix[i];
	}
	delete[]matrix;//очистка динамической памяти под матрицу
}