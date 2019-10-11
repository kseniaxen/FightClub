#pragma once
#include <string>

class Alerts 
{
	string playerLogin;
	int x_Alerts, y_Alerts;
	string partsBody[3] = { "������","�����","����" };
	int x_drawAlert, y_drawAlert;
public:
	Alerts(string login)
	{
		if (login == "���������")
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
		cout << "�����: " << playerLogin << " ������� ���� � " << partsBody[part - 1];
		SetCursorPosition(x_Alerts, y_Alerts + 1);
		cout << "�������� ��������: " << health;
	}

	void drawWinAlertPlayer()
	{
		SetCursorPosition(x_Alerts, y_Alerts);
		cout << "�����: " << playerLogin << " �������!";
		SetCursorPosition(x_Alerts, y_Alerts+1);
		cout << "������ ���� ������ ������� ������� SPACE... ";
	}

	void drawDrawAlert()
	{
		SetCursorPosition(x_Alerts, y_Alerts);
		cout << "�����!" << endl;
		SetCursorPosition(x_Alerts, y_Alerts + 1);
		cout << "������ ���� ������ ������� ������� SPACE... ";
	}

	void drawDrawProcessGame()
	{
		this->x_drawAlert = 65;
		if (playerLogin == "���������") 
		{
			this->y_drawAlert = 30;
		}
		else
		{
			this->y_drawAlert = 27;
		}
		SetCursorPosition(x_drawAlert, y_drawAlert);
		cout << "������ ������ ���� � �����" << endl;
		SetCursorPosition(x_drawAlert, y_drawAlert + 1);
		cout << "� ���� �������� ��������� "<<playerLogin;
	}

};
