#include <iostream>//Подключение стандартной библиотеки 
#include <iomanip>//Подключение библиотеки манипуляторов
void main()//объявление функции main
{
	using namespace std;//множно не прописывать std
	setlocale(LC_CTYPE, "Russian");//Локализация
	char c, pb = ' ';//объявление типа данных переменных с и pb , и задание значения переменной pb
	cout << "Введите символ: ";//ввод значения переменной c с клавиатуры
	cin >> c;//ввод значения переменной c в систему
	cout << setw(20) << setfill(pb) << pb << setw(5) << setfill(c) << c << setw(4) << setfill(pb) << pb << setw(5) << setfill(c) << c << endl;//двадцать пробелов перед 7-ю символами , следом 4 пробела ,затем ещё 7 символов
	cout << setw(19) << setfill(pb) << pb;//19 пробелов перед следующей строкой символов 
	cout << setw(7) << setfill(c) << c << setw(2) << setfill(pb) << pb << setw(7) << setfill(c) << c << endl;//7 символов , затем 2 пробела ,после строка из семи символов 
	cout << setw(18) << setfill(pb) << pb;//18 пробелов перед следующей строкой 
	cout << setw(18) << setfill(c) << c << endl;//строка из 18 символов
	cout << setw(17) << setfill(pb) << pb;//17 пробелов перед следующей строкой 
	cout << setw(20) << setfill(c) << c << endl;//строка из 20 символов
	cout << setw(17) << setfill(pb) << pb;//17 пробелов перед следующей строкой
	cout << setw(20) << setfill(c) << c << endl;//строка из 20 символов 
	cout << setw(18) << setfill(pb) << pb;//18 пробелов перед следующей строкой
	cout << setw(18) << setfill(c) << c << endl;//строка из 18 символов 
	cout << setw(19) << setfill(pb) << pb;//19 пробелов перед следующей строкой
	cout << setw(16) << setfill(c) << c << endl;//строка из 16 символов
	cout << setw(20) << setfill(pb) << pb;//20 символов перед следующей строкой 
	cout << setw(14) << setfill(c) << c << endl;//строка из 14 символов 
	cout << setw(21) << setfill(pb) << pb;//21 пробел перед следующей строкой 
	cout << setw(12) << setfill(c) << c << endl;//строка из 12 символов 
	cout << setw(22) << setfill(pb) << pb;//22 пробела перед следующей строкой 
	cout << setw(10) << setfill(c) << c << endl;//строка из 10 символов
	cout << setw(23) << setfill(pb) << pb;//23 символа перед следующей строкой
	cout << setw(8) << setfill(c) << c << endl;//строка из 8 символов
	cout << setw(24) << setfill(pb) << pb;//24 пробела перед следующей строкой
	cout << setw(6) << setfill(c) << c << endl;//строка из 6 символов
	cout << setw(25) << setfill(pb) << pb;//25 пробелов перед следующей строкой 
	cout << setw(4) << setfill(c) << c << endl;//строка из 4 символов 
	cout << setw(26) << setfill(pb) << pb;//26 пробелов перед следующей строкой 
	cout << setw(2) << setfill(c) << c << endl;//строка из 2 символов 
}