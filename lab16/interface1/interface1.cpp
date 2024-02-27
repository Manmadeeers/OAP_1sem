#include <iostream>
using namespace std;


int MinimalElementOfARow(int* matrix1, int amm_of_colomns)//функция для вычисления минимального элемента в каждой строке
{
	int min_element = matrix1[0];//переменной для минимального элемента присвоить первый элемент строки
	for (int j = 0; j < amm_of_colomns; j++) {//цикл для вычисления минимального элемента в конкретной строке
		if (matrix1[j] < min_element) {
			min_element = matrix1[j];
		}
	}
	return min_element;//функця возвращает минимальный элемент строки
}

void MatrixChange(int** matrix1, int amm_of_rows, int amm_of_colomns)//функция для вывода преобразованной матрицы
{
	cout << "Матрица после преобразования:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			if (i == j) {//замена элементов главной диагонали на минимальные элементы для каждой строки
				matrix1[i][j] = MinimalElementOfARow(matrix1[i], amm_of_colomns);//использование функции выше
			}
			cout << matrix1[i][j] << ' ';//вывод элемента матрицы
		}
		cout << "\n";
	}
}

void MatrixCheck(int** matrix2,int size_of_matrix2)//функция для проверки равенства соответствующих строки и столбца
{
	int k;//создание переменной для хранения номера равных строки и столбца
	for (int i = 0; i < size_of_matrix2; i++) {//цикл в цикле для проверки соответствующих строки и столбца на равенство
		int control_var = 0;//создание контольной счётной переменной для проверки на равенство
		for (int j = 0; j < size_of_matrix2; j++) {
			if (matrix2[i][j] == matrix2[j][i]) {//если элемент строки равен соответствующему элементу столбца
				control_var++;//увеличение счётной переменной на 1
			}
		}
		if (control_var == 4) {//если контольная переменная равне длине строки или столбца
			k = i;//присвоение переменной к номера строки
			cout << k + 1 << "-ая строка равна " << k + 1 << "-ому столбцу" << endl;//вывод номера такой строки и столбца
		}
	}
}


void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	cout << "Первая матрица" << endl;
	int amm_of_rows;//ввод кол-ва строк первой марицы
	cout << "Введите кол-во строк:";
	cin >> amm_of_rows;
	int amm_of_colomns;//ввод кол-ва столбцов первой матрицы
	cout << "Введите кол-во столбцов:";
	cin >> amm_of_colomns;
	int** matrix1;//создание указателя на область памяти для динамиеского массива
	matrix1 = new int* [amm_of_rows * amm_of_colomns];//выделение динамической памяти под первую матрицу
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элементов первой матрицы
		matrix1[i] = new int[amm_of_rows];//выделение динамической памяти под строку
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix1[i][j];//ввод элемента матрицы
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix1[i][j] << ' ';
		}
		cout << "\n";
	}

	cout << "Вторая матрица" << endl;//вторая матрица
	int size_of_matrix2 = 4;//задание переменной для размерности массива
	int** matrix2;//создание указателя на область памяти для динамического массива
	matrix2 = new int* [size_of_matrix2];//выделение динамической памяти
	for (int i = 0; i < size_of_matrix2;i++){//цикл в цикле для ввода элементов матрицы
		matrix2[i] = new int[size_of_matrix2];//выделение динамической памяти под строку
		for (int j = 0; j < size_of_matrix2; j++) {
			cout << "Введите элемент матрицы:";
			cin >> matrix2[i][j];//ввод элемента матрицы
		}
	}
	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < size_of_matrix2; i++) {//цикл в цикле для вывода второй матрицы
		for (int j = 0; j < size_of_matrix2; j++) {
			cout << matrix2[i][j] << ' ';
		}
		cout << "\n";
	}
	int sw;//создание переменной для работы с оператором switch
	cout << "Выберите , как хотите использовать программу:\n\t1-Заполнение главной диагонали матрицы минимальными элементами соответствующей строки.\n\t2-Вывод номера строки , которая равна соответствующему столбцу." << endl;
	cin >> sw;//ввод варіанта іспользованія программы
	switch (sw) {
	case 1:MatrixChange(matrix1, amm_of_rows, amm_of_colomns); break;//первый вариант
	case 2:MatrixCheck(matrix2, size_of_matrix2); break;//второй вариант
	}
	for (int i = 0; i < amm_of_colomns; i++) {//цикл для удаления динамической памяти по строки перой матрицы
		delete[]matrix1[i];
	}
	delete[]matrix1;//удаление динамической памяти под первую матрицу
	for (int i = 0; i < size_of_matrix2; i++) {//цикл для удаления динамической памяти под строки второй матрицы
		delete[]matrix2[i];
	}
	delete[]matrix2;//удаление динамической памяти под вторую матрицу
}