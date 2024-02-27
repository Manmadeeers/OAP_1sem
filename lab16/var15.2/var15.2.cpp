#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>
using namespace std;

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

void main()//главная функция
{
	setlocale(LC_ALL, "Russian");//локализация консоли
	SetConsoleCP(1251);//локализация вывода
	SetConsoleOutputCP(1251);
	string sentence;//ввод предложения
	cout << "Введите предложение:";
	getline(cin, sentence);
	cin.ignore(cin.rdbuf()->in_avail());//очистка буфера после ввода
	SentenceChange(sentence);//использование вышеописанной функции
}