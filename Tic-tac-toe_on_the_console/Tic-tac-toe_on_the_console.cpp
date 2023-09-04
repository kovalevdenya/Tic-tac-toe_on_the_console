#include<iostream>
#include<string>

void Menu() {
	std::cout << "\t\t\t\t\t\t" << "Tic-Tac" << std::endl;
	std::cout << "\tМеню:" << std::endl;
	std::cout << "1. Начать играть" << std::endl;
	std::cout << "2. Выход" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите номер и нажмите Enter..." << std::endl;
}



int main() {
	setlocale(LC_ALL, "Ru");
	while (true) {
		Menu();
		std::string numMenu;
		std::cin >> numMenu;
		while (numMenu != "1" && numMenu != "2") {
			std::cout << "Ошибка: выбранного номера меню не существует" << std::endl << "Введите номер еще раз и нажмите Enter..." << std::endl;
			std::cin >> numMenu;
		}
		if (numMenu == "1") {
			std::string Player1, Player2;
			std::cout << "Введите имя Игрока №1" << std::endl;
			std::getline(std::cin, Player1);
			std::cout << "Введите имя Игрока №2" << std::endl;
			std::getline(std::cin, Player2);
		}
		else if (numMenu == "2") {
			break;
		}
	}
}