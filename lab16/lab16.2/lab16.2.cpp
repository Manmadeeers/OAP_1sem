#include <iostream>
using namespace std;


void MatrixCheck(int** matrix,int amm_of_rows,int amm_of_colomns)//функция для проверки равенства соответствующих строки и столбца
{
	int k;//создание переменной для хранения номера равных строки и столбца
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для проверки соответствующих строки и столбца на равенство
		int control_var = 0;//создание контольной счётной переменной для проверки на равенство
		for (int j = 0; j < amm_of_colomns; j++) {
			if (matrix[i][j] == matrix[j][i]) {//если элемент строки равен соответствующему элементу столбца
				control_var++;//увеличение счётной переменной на 1
			}
		}
		if (control_var == 4) {//если контольная переменная равне длине строки или столбца
			k = i;//присвоение переменной к номера строки
			cout << k+1 << "-ая строка равна " << k+1 << "-ому столбцу" << endl;//вывод номера такой строки и столбца
		}
	}
}


void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	int amm_of_rows = 4;//задание количества строк
	int amm_of_colomns = 4;//задание количества столбцов
	int size_of_matrix = amm_of_rows * amm_of_colomns;//вычисление размера матрицы
	int** matrix;//создание указателя на область памяти для двумерного массива
	matrix = new int* [size_of_matrix];//выделение динамической памяти
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элеентов матрицы
		matrix[i] = new int[amm_of_rows];//выделение памяти под каждую строку
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];//ввод элементов матрицы
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout<< matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	MatrixCheck(matrix, amm_of_rows, amm_of_colomns);//использование вышеописанной функции 
	for (int k = 0; k < amm_of_rows; k++) {//цикл для удаления динамической памяти под строки
		delete[]matrix[k];
	}
	delete[]matrix;//удаление динамического массива
}