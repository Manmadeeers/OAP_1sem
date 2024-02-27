#include <iostream>
using namespace std;



int MinimalElementOfARow(int* matrix, int amm_of_colomns)//функция для вычисления минимального элемента в каждой строке
{
	int min_element = matrix[0];//переменной для минимального элемента присвоить первый элемент строки
	for (int j = 0; j < amm_of_colomns; j++) {//цикл для вычисления минимального элемента в конкретной строке
		if (matrix[j] < min_element) {
			min_element = matrix[j];
		}
	}
	return min_element;//функця возвращает минимальный элемент строки
}

void MatrixChange(int** matrix, int amm_of_rows, int amm_of_colomns)//функция для вывода преобразованной матрицы
{
	cout << "Матрица после преобразования:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			if (i == j) {//замена элементов главной диагонали на минимальные элементы для каждой строки
				matrix[i][j] = MinimalElementOfARow(matrix[i], amm_of_colomns);//использование функции выше
			}
			cout << matrix[i][j] << ' ';//вывод элемента матрицы
		}
		cout << "\n";
	}
}

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
		cout << matrix[i][j] << ' ';
	}
	cout << "\n";
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int amm_of_rows;//ввод количества строк
	cout << "Введите кол-во строк(Не больше 16):";
	cin >> amm_of_rows;
	while (amm_of_rows < 0 || amm_of_rows>16) {//проверка на дурачка(на основе условия)
		cout << "Внимательнее читайте условие!" << endl;
		cout << "Введите кол-во строк(Не больше 16):";
		cin >> amm_of_rows;
	}
	int amm_of_colomns;//ввод количества столбцов
	cout << "Введите кол-во столбцов(Не больше 18):";
	cin >> amm_of_colomns;
	while (amm_of_colomns < 0 || amm_of_colomns>18) {//проверка на дурачка на основе условия
		cout << "Внимательнее читайте условие!" << endl;
		cout << "Введите кол-во столбоцов(Не больше 18):";
		cin >> amm_of_colomns;
	}
	int** matrix;//создание указателя на область памяти для двумерного массива
	matrix = new int* [amm_of_rows * amm_of_colomns];//выделение динамической памяти
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элементов матрицы
		matrix[i] = new int[amm_of_rows];//выделение памяти под строку
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix[i][j];//ввод элемента матрицы
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода элементов введённой матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix[i][j] << ' ';//вывод элемента матрицы
		}
		cout << "\n";
	}
	int size_of_matrix2 = 4;

	int sw;
	cout << "Каким способом вы хотите использовать программу?\n1-Заменить каждый элемент матрицы,стоящий на главной диагонали на минимальный элемент строки.\n2-Вывести номер строки, которая равна соответствующему столбцу."<<endl;
	cin >> sw;
	switch (sw) {
	case 1: MatrixChange(matrix, amm_of_rows, amm_of_colomns); break;
	case 2:  break;
	}


	for (int k = 0; k < (amm_of_rows * amm_of_colomns); k++) {//цикл для очистки динамической памяти в каждой строке
		delete[]matrix[k];
	}
	delete[]matrix;//очистка динамической памяти выделенной под матрицу
}