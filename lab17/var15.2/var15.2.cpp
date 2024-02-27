#include <iostream>
using namespace std;


void MatrixCheck(int** matrix, int amm_of_colomns, int amm_of_rows)//функция для изменения матрицы
{
	int* col;//создание указателя на область памяти
	col = new int[amm_of_colomns];//выделение динамической памяти
	int amm = 0;//создание счётной переменной для размерности массива
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для проверки столбцов на отррицательны элементы
		for (int j = 0; j < amm_of_colomns; j++) {
			if (matrix[i][j] < 0) {//если элемент отрицательный
				*(col + amm) = j;//присвоить номер столбца массиву
				amm++;//увеличение счётной переменной на 1
				break;//выход из цикла
			}
		}
	}
	for (int i = 0; i < amm; i++) {//цикл в цикле для изменения знаков нужных столбцов
		for (int j = 0; j < amm_of_rows; j++) {
			matrix[j][i] = -matrix[j][i];
		}
	}
	cout << "Получившаяся матрица:" << endl;//цил в цикле для вывода получившейсся матрицы
	for (int i = 0; i < amm_of_rows; i++) {
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	delete[]col;//очистка динамиечской памяти под вспомогательный массив
}


void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int amm_of_rows;//ввод кол-ва строк
	cout << "Введите кол-во строк:";
	cin >> amm_of_rows;
	cin.ignore(cin.rdbuf()->in_avail());//очитска буфера после ввода
	int amm_of_colomns;//ввод-кол-ва столбцов
	cout << "Введите кол-во столбцов:";
	cin >> amm_of_colomns;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	int** matrix;//создание указателя на область памяти
	matrix = new int* [amm_of_rows];//выделение динамической памяти под матрицу
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элементов матрицы
		matrix[i] = new int[amm_of_colomns];//выделение динамической памяти под строку
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];//ввод элемента матрицы
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	MatrixCheck(matrix, amm_of_colomns, amm_of_rows);//использование вышеописанной функции
	for (int i = 0; i < amm_of_colomns; i++) {//цикл для очистки динамической памяти , выделенной под строки
		delete[]matrix[i];
	}
	delete[]matrix;//очистка динамической памяти под матрицу
}