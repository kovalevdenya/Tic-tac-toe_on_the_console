﻿#include<iostream>
#include<string>
#include<vector>
#include <cstdlib> // Для библиотеки случайных чисел
#include <ctime>   // Для инициализации генератора случайных чисел

void Menu() {  
	std::cout << "\t\t\t\t\t\t" << "Tic-Tac" << std::endl;
	std::cout << "\tМеню:" << std::endl;
	std::cout << "1. Начать играть" << std::endl;
	std::cout << "2. Выход" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите номер и нажмите Enter..." << std::endl;
}   // Вывод меню игры  

void DrowingField(std::vector<std::vector<std::string>> orig, std::string& Player1,std::string& Player2) { // Рисовка поля
	system("cls");
	for (size_t i = 0; i != orig.size(); ++i) {
		for (size_t j = 0; j != orig[i].size(); ++j) {
			
				std::cout << orig[i][j];
			
		}
		if (i == 0) {
			std::cout << "\t\t\t\tX - " << Player1;
		}
		else if (i == 1) {
			std::cout << "\t\t\t\tO - " << Player2;
		}
		std::cout << std::endl;
	}
}

void RandomChoiceAndFirstDrawing(std::string& xPlayer, std::string& oPlayer, const std::string& Player1, const std::string& Player2, std::vector<std::vector<std::string>>& field) { /*выбор рандомного игрока и рисовка пустого поля*/
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int randomNumber = std::rand() % 10;
	if (randomNumber < 5) {
		xPlayer = Player1;
		oPlayer = Player2;
	}
	else {
		xPlayer = Player2;
		oPlayer = Player1;
	}
	DrowingField(field, xPlayer, oPlayer);
} // выбор фигуры для игроков и прорисовка поля

void createX(std::vector<std::vector<std::string>>& field, int& X) {
	switch (X) {
	case 1:
		field[0][0] = " X ";
		break;
	case 2:
		field[0][2] = " X ";
		break;
	case 3:
		field[0][4] = " X ";
		break;
	case 4:
		field[2][0] = " X ";
		break;
	case 5:
		field[2][2] = " X ";
		break;
	case 6:
		field[2][4] = " X ";
		break;
	case 7:
		field[4][0] = " X ";
		break;
	case 8:
		field[4][2] = " X ";
		break;
	case 9:
		field[4][4] = " X ";
		break;
	}
}

void createO(std::vector<std::vector<std::string>>& field, int& O) {
	switch (O) {
	case 1:
		field[0][0] = " O ";
		break;
	case 2:
		field[0][2] = " O ";
		break;
	case 3:
		field[0][4] = " O ";
		break;
	case 4:
		field[2][0] = " O ";
		break;
	case 5:
		field[2][2] = " O ";
		break;
	case 6:
		field[2][4] = " O ";
		break;
	case 7:
		field[4][0] = " O ";
		break;
	case 8:
		field[4][2] = " O ";
		break;
	case 9:
		field[4][4] = " O ";
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Ru");
	std::vector<std::vector<std::string>> field = { {" 1 ","|"," 2 ","|"," 3 "},{"-----------"},{" 4 ","|"," 5 ","|"," 6 "},{"-----------"},{" 7 ","|"," 8 ","|"," 9 "}};
	
	while (true) {
		Menu();
		std::string numMenu;
		std::cin >> numMenu;
		while (numMenu != "1" && numMenu != "2") {
			std::cout << "Ошибка: выбранного номера меню не существует" << std::endl << "Введите номер еще раз и нажмите Enter..." << std::endl;
			std::cin >> numMenu;
		}
		if (numMenu == "1") {
			std::vector<std::vector<std::string>> thisField = field;
			bool tie = false, winX = false, winO = false;
			std::string Player1, Player2;
			std::cout << "Введите имя Игрока №1" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, Player1);
			std::cout << "Введите имя Игрока №2" << std::endl;
			std::getline(std::cin, Player2);
			std::string xPlayer, oPlayer;
			RandomChoiceAndFirstDrawing(xPlayer, oPlayer, Player1, Player2, thisField);
			while (!(tie || winX || winO)) {
				std::cout << std::endl << "Крестики ваш ход, выберите поле:";
				int X;
				std::cin >> X;
				createX(thisField, X);
				DrowingField(thisField, xPlayer, oPlayer);
				// здесь нужна проверка на выйгрыш
				std::cout << std::endl << "Нолики ваш ход, выберите поле:";
				int O;
				std::cin >> O;
				createO(thisField, O);
				DrowingField(thisField, xPlayer, oPlayer);
				// здесь тоже проверка
			}

		}
		else if (numMenu == "2") {
			break;
		}
	}
}