#pragma once
#include "AutoRegPlayer.h"
#include "Interface Players.h"
#include "Interface Alerts.h"
#include "Logic players.h"
#include "Game.h"

class Menu
{
	int x_Sign = 35, y_Sign = 1;
	int x_SignMenu = 5, y_SignMenu = 3;
	int x_pic = 40, y_pic = 3;
	int x_Reg = 5, y_Reg = 4;
	int x_User = 5, y_User = 10;

	bool exit = false;
	int key;
	int choice;

	string loginPlayer;
	string passwordPlayer;
	int points;
	int wins;
public:

	Menu()
	{
		system("mode con cols=120 lines=35");
		int positionMenu = 0;
		int currentPosition = 0;
		do
		{
			printNameGame();
			printNameMenu();
			printPicture();
			currentUser();
			printSignMenu(positionMenu);
			key = _getch();
			if (key == ARROW_DOWN || key == ARROW_UP)
			{
				positionMenu = position(positionMenu, key);
				currentPosition = positionMenu;
			}

			if (key == ENTER)
			{
				system("cls");
				switch (currentPosition)
				{
				case 1:
					Authorization();
					_getch();
					system("cls");
					break;
				case 2:
					Registration();
					_getch();
					system("cls");
					break;
				case 3:
					Tutorial();
					_getch();
					system("cls");
					break;
				case 4:
					if (points >= 0 && wins >= 0 && loginPlayer != "" && passwordPlayer != "")
					{
						auto game = new Game(loginPlayer, points, wins, new Player(new RealPlayerInterface, new Alerts(loginPlayer)));
						game->startPlay();
						auto scoreWins = new Autorization("Users.txt", User(loginPlayer, passwordPlayer, game->getAllPointsGame(), game->getWinsGame()));
						scoreWins->setScoreWins();
						system("cls");
					}
					else {
						SetCursorPosition(x_Reg, y_Reg);
						cout << "Вы не авторизовались!" << endl;
						_getch();
						system("cls");
						break;
					}
					break;
				case 5:
					frameLeaderBoard();
					leaderBoard();
					_getch();
					system("cls");
					break;
				case 6:
					exit = true;
					break;
					/*default:
						break;*/
				}
			}

		} while (!exit);
	}

	void Tutorial()
	{
		SetCursorPosition(x_Reg, y_Reg);
		cout << "Правила игры Бойцовский клуб";
		SetCursorPosition(x_Reg, y_Reg + 2);
		cout << "Игра между компьютером и человеком. У каждого игрока есть персонажи - рыцари, которые имеет одинаковое количество \nздоровья. ";
		cout << "Бой состоит из последовательного обмена ударами (разменами) между двумя соперниками. Во время размена игрокам\nпредоставляется выбор между зонами удара и блока. Зонами являются голова, живот и ноги. \n ";
		cout << "Побеждает игрок тогда, когда у противники остается 0 здоровья.\n";
		
		SetCursorPosition(x_Reg, y_Reg + 7);
		cout << "Игровой процесс\n\n";
		SetCursorPosition(x_Reg, y_Reg + 9);
		cout << "Перед началом игры, игроку необходимо авторизоваться в свой профиль, если он его еще не завел, то необходимо\nзарегистрироваться.";
		cout << "В самой игре, игроку с помощью стрелочек вверх и вниз необходимо выбрать зону для удара. Затем нужно нажать стрелочку вправо и так же выбрать зону для блока.";
		cout << "Если игрок выбрал зону удара и блока, он нажимает клавишу ENTER и он увидит отображение его хода и хода противника.\n";
		cout << "После того как оба игрока сделают свой ход. Игра продолжится, когда игрок нажмет стрелочку вверх или вниз.\n";
		cout << "В игре может возникнуть момент, когда оба игрока ударят и заблокируют одно и то же место, то шанс получения урона у \nодного из игроков 50 на 50. ";
		cout << "В игре начисляются очки и количество побед, они сохраняются после каждой игры.";
	}

	void Registration()
	{
		SetColor(LightGreen, Black);
		SetCursorPosition(x_Reg, y_Reg-2);
		cout << "Регистрация";
		SetColor(White, Black);

		SetCursorPosition(x_Reg, y_Reg);
		cout << "Введите логин:";
		cin >> loginPlayer;
		SetCursorPosition(x_Reg, y_Reg+2);
		cout << "Введите пароль:";
		cin >> passwordPlayer;

		User user(loginPlayer, passwordPlayer,0,0);
		auto reg = new Registr("Users.txt", user);
		reg->Registration();
		loginPlayer = "";
		passwordPlayer = "";
	}

	void Authorization()
	{
		SetColor(LightGreen, Black);
		SetCursorPosition(x_Reg, y_Reg - 2);
		cout << "Авторизация";
		SetColor(White, Black);

		auto aut = new Autorization("Users.txt");

		aut->Autorizat();

		this->loginPlayer = aut->getAutLogin();
		this->passwordPlayer = aut->getAutPassword();
		this->points = aut->getAutPoints();
		this->wins = aut->getAutWins();
	}

	void currentUser()
	{
		SetColor(LightCyan, Black);
		SetCursorPosition(x_User, y_User);
		cout << "Пользователь:";
		SetColor(White, Black);
		SetCursorPosition(x_User, y_User+1);
		cout << loginPlayer;
	}

	void leaderBoard()
	{
		auto leaderBoard = new Autorization("Users.txt");
		leaderBoard->leaderBoard();
	}

	void frameLeaderBoard()
	{
		SetColor(LightGreen, Black);
		SetCursorPosition(x_Reg+25, y_Reg - 4);
		cout << "Таблица лидеров";
		SetCursorPosition(x_Reg, y_Reg - 2);
		cout << "Логин";
		SetCursorPosition(x_Reg + 25, y_Reg - 2);
		cout << "Очки";
		SetCursorPosition(x_Reg + 50, y_Reg - 2);
		cout<< "Победы";
		SetColor(White, Black);
	}

	void printNameGame()
	{
		SetColor(LightRed, Black);
		SetCursorPosition(x_SignMenu, y_Sign);
		cout << "Бойцовский клуб";
		SetColor(White, Black);
	}

	void printPicture()
	{
		SetCursorPosition(x_pic, y_pic);
		cout << "               ! ";
		SetCursorPosition(x_pic, y_pic + 1);
		cout << "	     . - .     ";
		SetCursorPosition(x_pic, y_pic + 2);
		cout << "	   __| = |__  ";
		SetCursorPosition(x_pic, y_pic + 3);
		cout << "	  (_ /`-`\\ _)  ";
		SetCursorPosition(x_pic, y_pic + 4);
		cout << "	  // \\___/ \\\\   ";
		SetCursorPosition(x_pic, y_pic + 5);
		cout << "          <> /   \\ <>     ";
		SetCursorPosition(x_pic, y_pic + 6);
		cout << "	   \\ |_._| /      ";
		SetCursorPosition(x_pic, y_pic + 7);
		cout << "	     <_I_>       ";
		SetCursorPosition(x_pic, y_pic + 8);
		cout << "	      |||        ";
		SetCursorPosition(x_pic, y_pic+9);
		cout<<"	     /_|_\\     ";
			

	}

	void printNameMenu()
	{
		SetCursorPosition(x_Sign, y_Sign);
		SetColor(LightGreen, Black);
		cout << "Меню";
		SetColor(White, Black);
	}

	void printColor(int pos, int ch)
	{
		if (pos == ch) {
			SetColor(LightGreen, Black);
		}
		else SetColor(White, Black);

	}

	void printSignMenu(int pos)
	{
		SetCursorPosition(x_SignMenu, y_SignMenu);
		printColor(pos, 1);
		cout << " Авторизация ";
		SetCursorPosition(x_SignMenu, y_SignMenu + 1);
		printColor(pos, 2);
		cout << " Регистрация ";
		SetCursorPosition(x_SignMenu, y_SignMenu + 2);
		printColor(pos, 3);
		cout << " Правила ";
		SetCursorPosition(x_SignMenu, y_SignMenu + 3);
		printColor(pos, 4);
		cout << " Играть ";
		SetCursorPosition(x_SignMenu, y_SignMenu + 4);
		printColor(pos, 5);
		cout << " Таблица лидеров ";
		SetCursorPosition(x_SignMenu, y_SignMenu + 5);
		printColor(pos, 6);
		cout << " Выход ";
		SetColor(White, Black);
	}

	int position(int pos, char ch)
	{
		if (ch == ARROW_DOWN) {
			//вниз
			if (pos >= 6) {
				pos = 1;
			}
			else  pos++;
		}
		if (ch == ARROW_UP) {
			//вверх
			if (pos <= 1) {
				pos = 6;
			}
			else  pos--;
		}
		return pos;
	}

};