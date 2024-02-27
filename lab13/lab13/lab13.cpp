#include <iostream>
#include <cstring>
using namespace std;

void main()//главная функция
{
	setlocale(LC_ALL, "Russian");
	char str[100];//создание массива строки
	cout << "Введите строку:";
	cin >> str;//ввод строки с клавиатуры
	int n =strlen(str);//вычисление размерности массива
	char str1[100];//задание нового массива для вывода ответа
	cout << "Размерность массива: " << n << endl;//вывод размерности массива
	for (int i = 0; i < n; i+=2) {//цикл для перестановки соответствующих элементов
		str1[i] = str[i + 1];
		str1[i + 1] = str[i];
	}
	cout << "Строка после шифрования: ";//цикл для вывод ответа на экран
	for (int i = 0; i < n; i++) {
		cout << str1[i];
	}
}