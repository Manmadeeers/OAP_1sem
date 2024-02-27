﻿#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


void MatrixChange(int** matrix1, int amm_of_rows, int amm_of_colomns, int a, int b)//функция для изменения матрицы
{
	int str_for_a;//создание переменной для хранения номера строки с вхождением числа а
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для нахождения такого номера строки
		for (int j = 0; j < amm_of_colomns; j++) {
			if (matrix1[i][j] == a) {
				str_for_a = i;
			}
		}
	}
	cout << "Вхождение числа а в строке " << str_for_a + 1 << endl;//вывод номера такой строки
	int str_for_b;//создание переменной для хранения номера строки с вхождением числа b
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для нахождения номера такой строки
		for (int j = 0; j < amm_of_colomns; j++) {
			if (matrix1[i][j] == b) {
				str_for_b = i;
			}
		}
	}
	cout << "Вхождение числа b в строке " << str_for_b + 1 << endl;//вывод номера такой строки
	cout << "Матрица после изменения:" << endl;
	int** matrix_dop;//создание указателя на область паяти для дополнительной матрицы
	matrix_dop = new int* [amm_of_rows * amm_of_colomns];//выделение динамической памяти под такой матрицу
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для создания матрицы
		matrix_dop[i] = new int[amm_of_rows];//выделение динамиеской памяти под каждую строку
		for (int j = 0; j < amm_of_colomns; j++) {
			matrix_dop[i][j] = 0;//создание нулевой матрицы
		}
	}
	if (str_for_a < str_for_b) {//если строка с а поябляется раньше , чем трока с б
		for (int i = 0; i < str_for_a; i++) {//цикл для вывода элементов матрицы до строки с а
			for (int j = 0; j < amm_of_colomns; j++) {
				matrix_dop[i][j] = matrix1[i][j];
			}
		}
		for (int j = 0; j < amm_of_colomns; j++) {//вывод строки с вхождением а , заменённой на строку с вхождением б
			matrix_dop[str_for_a][j] = matrix1[str_for_b][j];
		}
		for (int i = str_for_a + 1; i < str_for_b; i++) {//вывод элементов от строки с вхождением  до строки с вхождением б
			for (int j = 0; j < amm_of_colomns;) {
				matrix_dop[i][j] = matrix1[i][j];
			}
		}
		for (int j = 0; j < amm_of_colomns; j++) {//вывод строки с вхожлением б ,заменённую на строку с вхождением а
			matrix_dop[str_for_b][j] = matrix1[str_for_a][j];
		}
		for (int i = str_for_b + 1; i < amm_of_rows; i++) {//вывод оставшихся элементов матрицы
			for (int j = 0; j < amm_of_colomns; j++) {
				matrix_dop[i][j] = matrix1[i][j];
			}
		}
	}
	if (str_for_b < str_for_a) {//если вхождение б раньше , чем вхождение а
		for (int i = 0; i < str_for_b; i++) {//цикл для вывода элементов матрицы до строки с вхождением б
			for (int j = 0; j < amm_of_colomns; j++) {
				matrix_dop[i][j] = matrix1[i][j];
			}
		}
		for (int j = 0; j < amm_of_colomns; j++) {//цикл для вывода строки с вхожением б ,заменённую на строку с вхождением а 
			matrix_dop[str_for_b][j] = matrix1[str_for_a][j];
		}
		for (int i = str_for_b + 1; i < str_for_a; i++) {//цикл для вывода элементов матрицы междоу строками с вхождениями а и б
			for (int j = 0; j < amm_of_colomns;) {
				matrix_dop[i][j] = matrix1[i][j];
			}
		}
		for (int j = 0; j < amm_of_colomns; j++) {//цикл для вывода строки с вхожлением а ,заменённую на строку с вхождением б
			matrix_dop[str_for_a][j] = matrix1[str_for_b][j];
		}
		for (int i = str_for_a + 1; i < amm_of_rows; i++) {//цикл для вывода отсавшихся элементов матрицы
			for (int j = 0; j < amm_of_colomns; j++) {
				matrix_dop[i][j] = matrix1[i][j];
			}
		}
	}
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для вывода получившейся матрицы
		for (int j = 0; j < amm_of_colomns; j++) {
			cout << matrix_dop[i][j] << ' ';
		}
		cout << "\n";
	}
	for (int i = 0; i < amm_of_rows; i++) {//цикл для удаления динамической памяти под строки
		delete[]matrix_dop[i];
	}
	delete[]matrix_dop;//цикл для удаления динамической памяти под массив

}

void SentCheck(string sentence)//функция для сортировки по окончанию
{
	int sent_length = sentence.length();//создание переменной для вычисления длины предложения (включая пробелы)
	string tmp[100];//создание массива для добавления в него только слов из предложения
	int n = 0;//создание счётной переменной для вычисления размерности массива
	for (int i = 0; i < sent_length; i++) {//цикл для добавления только слов из предложения в массив
		if (sentence[i] != ' ') {//если не пробел
			tmp[n] += sentence[i];//добавление симолов слова по очереди
		}
		else {//если пробел - уыеличить счётную переменную на 1
			n++;
		}
	}
	string check = "ая";//строка , хранящая окончание
	int check_length = check.length();//вычисление размера строки с окончанием
	cout << "Слова , заканчивающиеся на ая:";
	for (int i = 0; i <= n; i++) {//цикл в цикле для вывода слов с заданным окончанием
		int control_var = 0;//создание счётной переменной для контроля окончания
		int tmp_length = tmp[i].length();//вычисление длины слова (нового для новой итерации)
		for (int j = tmp_length - 1; j >= tmp_length - check_length; j--) {//цикл для проверки двух последних символов слова
			if (tmp[i][j] == check[check_length - (tmp_length - j)]) {//если соответствующий элемент окончания слова равен соответствующему элементу окончания
				control_var++;//увелиечние контольной переменной на 1
			}
			if (control_var == 2) {//еслди контольная переменная равна 2,то окончания равны и вывести это слово
				cout << tmp[i] << ' ';
			}
		}


	}
}




void main()
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	SetConsoleCP(1251);//локализация вывода консоли
	SetConsoleOutputCP(1251);
	cout << "Первая часть:" << endl;
	int amm_of_rows;//ввод кол-ва строк матрицы
	cout << "Введите количество строк:";
	cin >> amm_of_rows;
	while (amm_of_rows < 0 || amm_of_rows >= 12) {//проверка на дурачка , согласно условию
		cout << "Сообщение для дурачка!" << endl;
		cout << "Введите кол-во строк:";
		cin >> amm_of_rows;
	}
	int amm_of_colomns;//ввод кол-ва столбцов матрицы
	cout << "Введите кол-во столбцов:";
	cin >> amm_of_colomns;
	while (amm_of_colomns < 0 || amm_of_colomns >= 8) {//проверка на дурачка ,согласно условию
		cout << "Сообщение для дурачка!" << endl;
		cout << "Введите кол-во столбцов:";
		cin >> amm_of_colomns;
	}
	int a;//ввод числа а
	cout << "Введите число а:";
	cin >> a;
	int b;//ввод числа б
	cout << "Введите число b:";
	cin >> b;
	int** matrix1;//создание указателя на область памяти с матрицей
	matrix1 = new int* [amm_of_rows * amm_of_colomns];//выделение динамической памяти под двумерный массив
	for (int i = 0; i < amm_of_rows; i++) {//цикл в цикле для ввода элементов мтарицы
		matrix1[i] = new int[amm_of_rows];//выделение динамической памяти под строки
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
	cin.ignore(cin.rdbuf()->in_avail());//чистка буффера
	cout << "Вторая часть:" << endl;
	string sentence;//ввод предложения с клавиатуры
	cout << "Введите предложение:" << endl;
	getline(cin, sentence);
	cin.ignore(cin.rdbuf()->in_avail());//чистка буффера
	int sw;
	cout << "Выберите,как хотите использоать программу:\n\t1-В матрице поменять местами строки с вхождением числа а и б\n\t2-Во введённом с клавиатуры предложении вывести все слова , заканчивающиеся на ая";
	cin >> sw;
	cin.ignore(cin.rdbuf()->in_avail());//чистка буффера
	switch (sw) {
	case 1:MatrixChange(matrix1, amm_of_rows, amm_of_colomns, a, b); break;
	case 2:SentCheck(sentence); break;
	}
}