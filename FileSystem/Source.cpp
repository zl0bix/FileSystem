#include<iostream>
#include<fstream>//file stream
#include<string>


bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;
	}
	else
		return false;
}

bool clear_file(std::string file_path) {
	std::ofstream clear;
	clear.open(file_path);
	if (clear.is_open()) {
		clear.close();
		return true;
	}
	return false;
}


bool statistic(std::string word);


int main() {
	setlocale(LC_ALL, "rus");
	int n;

	std::string path = "file.txt";
	// Класс ofstream
	/*
	std::ofstream out;//std::ofstream out(path); конструктор
	out.open(path, std::ios::app);// метод app добавление без стерания
	// проверка на открытие
	if (out.is_open()) {
		std::cout << "Файл открыт для записи\n";
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		out << str << std::endl;
		std::cout << "Запись добавлена в файл\n";
	}
	else 
		std::cout << "Ошибка открытия\n";
	// Возможные ошибки при открытии файла
	// 1. Неправильный синтаксис указания пути к файлу
	// 2. Нет доступа к файлу
	// 3. Файл открыт другим объектом или приложением




	out.close();
	

	*/
	// Класс ifsream
	/*
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "Файл открыт для чтения.\n";
		std::cout << "Содержимое файла: \n";
		std::string file_text;

		// Посимвольное считывание
		//char sym;
		//while (in.get(sym))
			//std::cout << sym;//только вывод
		////{file_text+=sym; std::cout<<file_text<<std::endl;} // вывод и сохранение в строке

		// Пословное считывание
		//while (!in.eof()) {
		//	std::string tmp;
		//	in >> tmp;
		//	file_text += tmp + '\n';
		//}
		//std::cout << file_text << std::endl;

		// Построчное считывание
		std::string line;
		while (std::getline(in, line))
			file_text += line + '\n';
		std::cout << file_text << std::endl;
	}
	else
		std::cout << "Ошибка открытия файла.\n";


	// Возможные ошибки при откпытии файла
	// 1. Неправильный синтаксис указания пути к файлу
	// 2. Нет доступа к файлу
	// 3. Файла не существует

	in.close();
	*/
	// Удоление файла
	/*
	if (remove(path.c_str()) == 0)
		std::cout << "Файл " << path << " удален. ";

	else
		std::cout << "Ошибка удоления ";
	// Возможные проблемы при удолении
	// 1. Неправильный синтаксис указания пути к файлу
	// 2. Нет доступа к файлу
	// 3. Файла не существует
	// 4. Файл открыт
	*/

	// Ex1-2 Слова в файл
	std::cout << "Ex1.\n";
	int action;

	do {
		std::cout << "Выберите дейчтвие -> \n";
		std::cout << "1. Добавление статистики\n";
		std::cout << "2. Вывод файла\n";
		std::cout << "3. Очистка файла\n";
		std::cout << "4. Завершение работы\n";
		std::cout << "Введите команду -> ";
		std::cin >> action;
		std::string str1;
		switch (action) {
		case 1:
			std::cout << "Введите строку -> ";
			std::cin.ignore();
			std::getline(std::cin, str1);

			if (statistic(str1)) {
				std::cout << "Запись добавлена в файл\n\n";
				
			}
			else std::cout << "Ошибка выполнения функции\n\n";
			break;
		case 2:
			std::cout << "Содержимое файла:\n\n";
			print_file("stats.txt");
			break;
		case 3:
			clear_file("stats.txt");
			std::cout << "Файл очищен\n\n";
			break;
		case 4:
			std::cout << "Программа завершина\n\n";
			break;
		default:
			std::cout << "Ошибка ввода\n\n";
		}
		


		
	} while(action!=4);
	std::cout << "Программа завершена\n\n";

	return 0;
}


bool statistic(std::string word) {
	std::ofstream out;
	out.open("stats.txt", std::ios::app);

	if (out.is_open()) {
		out << word << ' ' << word.length() << '\n';
		out.close();
		return true;
	}
	else
		return false;
}