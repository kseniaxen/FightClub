#pragma once
#include <string>

class Alerts 
{
	string playerLogin;
	int x_Alerts, y_Alerts;
	string partsBody[3] = { "Голову","Живот","Ноги" };
	int x_drawAlert, y_drawAlert;
public:
	Alerts(string login)
	{
		if (login == "Компьютер")
		{
			this->playerLogin = login;
			this->x_Alerts = 65;
			this->y_Alerts = 30;
		}
		else
		{
			this->playerLogin = login;
			this->x_Alerts = 65;
			this->y_Alerts = 27;
		}
	}

	void deleteAlert()
	{
		SetCursorPosition(x_Alerts, y_Alerts);
		cout << "                                           ";
		SetCursorPosition(x_Alerts, y_Alerts+1);
		cout << "                                           ";
	}

	void drawAlertsDamage(int part, int health)
	{
		SetCursorPosition(x_Alerts, y_Alerts);
		cout << "Игрок: " << playerLogin << " получил урон в " << partsBody[part - 1];
		SetCursorPosition(x_Alerts, y_Alerts + 1);
		cout << "Осталось здоровья: " << health;
	}

	void drawWinAlertPlayer()
	{
		SetCursorPosition(x_Alerts, y_Alerts);
		cout << "Игрок: " << playerLogin << " выиграл!";
		SetCursorPosition(x_Alerts, y_Alerts+1);
		cout << "Начать игру занова нажмите клавишу SPACE... ";
	}

	void drawDrawAlert()
	{
		SetCursorPosition(x_Alerts, y_Alerts);
		cout << "Ничья!" << endl;
		SetCursorPosition(x_Alerts, y_Alerts + 1);
		cout << "Начать игру занова нажмите клавишу SPACE... ";
	}

	void drawDrawProcessGame()
	{
		this->x_drawAlert = 65;
		if (playerLogin == "Компьютер") 
		{
			this->y_drawAlert = 30;
		}
		else
		{
			this->y_drawAlert = 27;
		}
		SetCursorPosition(x_drawAlert, y_drawAlert);
		cout << "Игроки попали друг в друга" << endl;
		SetCursorPosition(x_drawAlert, y_drawAlert + 1);
		cout << "В этом сражении побеждает "<<playerLogin;
	}

};
