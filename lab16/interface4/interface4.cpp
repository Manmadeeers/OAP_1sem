#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>
using namespace std;

void OperationsWithMassive(double* mas, int size, double C)//функция для операций с массивом
{
	int element_count = 0;//создание счётной переменной для подсчёта кол-ва элементов ,больших введённого
	cout << "Числа,большие введённого:";
	for (int i = 0; i < size; i++) {//цикл для вывода таких элементов
		if (mas[i] > C) {
			cout << mas[i] << ' ';
		}
	}
	double* max = mas;//создание указателя на массив
	int position_of_max;//создание переменной для хранения позиции максимального элемента
	for (int i = 0; i < size; i++) {//цикл для вычисления максимальног по модул элемента массива
		if (abs(*(mas + i)) > abs(*max)) {
			max = (mas + i);
			position_of_max = i;//присвоение переменной номера элемента
		}
	}
	cout << "\nПозиция максимального по модулю элемента:" << position_of_max + 1 << endl;//вывод позиции максимальног элемента
	double mult = 1;//создание переменной для вычисления произведения элементов , стоящих после максимальног по модулю
	for (int i = position_of_max + 1; i < size; i++) {
		mult = mult * mas[i];
	}
	cout << "Произведение элементов,стоящих псле максимального по модулю:" << mult << endl;//вывод произведения
}

void SentenceChange(string sentence)//функция для изменения строки
{
	int sent_length = sentence.length();//вычисление длины предложения
	string tmp[100];//создание вспомогательного массива
	for (int i = 0; i < sent_length; i++) {//цикл для добавления всех символов предложения до первого пробела во вспомогательный массив строк
		if (sentence[i] != ' ') {
			tmp[0] += sentence[i];//последовательное дабавление символов до пробела
		}
		else {
			break;//выход из цикла
		}
	}
	int tmp_length = tmp[0].length();//вычисление длины добавленого слова
	for (int i = 0; i < tmp_length; i++) {//цикл для преобразования строчных букв в прописные
		tmp[0][i] = toupper(tmp[0][i]);
	}
	cout << "Преобразование до первого пробела:";
	for (int i = 0; i < tmp_length; i++) {//цикл для вывода полученного результата
		cout << tmp[i];
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Первая часть:" << endl;
	int size;//ввод размерности массива
	cout << "Введите размерность массива:";
	cin >> size;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	double* mas;//создание указателя  на областьпамяти
	mas = new double[size];//выделение динамиекой памяти под массив
	for (int i = 0; i < size; i++) {//цикл для ввода элементов массива
		cout << "Введите элемент массива:";
		cin >> mas[i];
	}
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	double C;//ввод числа , с которым будет сравнение
	cout << "Введите число,с которым будет сравнение:";
	cin >> C;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	cout << "Вторая часть:" << endl;
	string sentence;//ввод предложения
	cout << "Введите предложение:";
	getline(cin, sentence);
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	int sw;
	cout << "Выберите,как хотите использовать программу:\n\t1-В массиве вещественных элементов вывести все элементы большие С и произведение элементов,расположенных после наибольшего по модулю\n\t2-В предложении преобразовать строчные буквы в прописные до первого пробела\n";
	cin >> sw;
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	switch (sw) {
	case 1:OperationsWithMassive(mas, size, C); break;//первый вариант
	case 2:SentenceChange(sentence); break;//второй вариант
	}
	delete[]mas;//очистка динамической памяти	
}