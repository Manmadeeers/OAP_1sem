//доп 6
#include <iostream>
#include <string>//подключение библиотеки string для работы со строками
void main()
{
	using namespace std;//можно не прописывать std
	setlocale(LC_CTYPE, "Russian");//локализация
	int n;
	cout << "Введите число: " << endl;//ввод числа с клавиатуры 
	cin >> n;
	string str = to_string(n);//преобразование числа n в строку
	for (int i = 0; i <= str.length(); i++) {//цикл 
		if (str[i] == '3' || str[i] == '6') {//проверка , есть ли в строке элементы 3 или 6
			str.erase(i, 1);//удаление элементов 3 ии 6
		}
	}
	cout << "Ответ: " << str << endl;//вывод ответа на экран
}