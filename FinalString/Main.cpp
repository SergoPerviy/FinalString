#include <iostream>
#include <string>

std::string spaces_str(std::string str) {
	for (int i = str.size() - 1; i > 0; i--) {
		str.insert(i, " ");
	}
	return str;
}

bool have_spam(std::string str) {
	//Обеспечение нерегистрозависимости функции
	for (int i = 0; i < str.length(); i++) {
		str[i] = std::tolower(str[i]);
	}
	//Создание массива словосочитаний, обозначающих спам.
	const int spams_number = 4;
	static const std::string spams_messeges[spams_number]{ //static сохраняет массив до завершения работы программы
		"100% free",									   //чтобы массив не создавался каждый раз при вызове функции
		"sales increase",								   //const нужен чтобы не было возможности случайно поменять 
		"only today"									   //содержимое массива
	};
	//Перебор спамовых словосочетаний с целью выявления их в строке
	for (int i = 0; i < spams_number; i++)				   
		if (str.find(spams_messeges[i]) < str.length()) //если позиция подстроки в строке меньше значения длины самой строки
			return true;								//то значит она присутствует в строке, тк если элимента нет в строке
														//тк если элимента нет в строке, то функция вернет максимальное значение 
														//типа данных unsignes long long
	return false;
}

int main() {
	system("chcp 1251>null");

	/*
	Задача 1. Пробелы в строку
	*/

	std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";

	/*
	Задача 2. Проверка спам
	*/
	
	std::cout << "Задача 2.\nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);

	if (have_spam(str2)) //Функции типа bool лучше всего проверять при помощи if
		std::cout << "Обнаружен спам!\n\n";
	else
		std::cout << "Спама не обнаружено.\n\n";

	return 0;
}