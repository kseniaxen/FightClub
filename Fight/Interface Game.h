#pragma once
#include <string>
#include <iostream>
#include "SetCursor.h"
#include "Color.h"

using namespace std;

class InterfaceMenu
{
	int x_ChoiceHit = 5, y_ChoiceHit = 27;
	int x_infoPlayer = 40, y_infoPlayer = 1;
	int x_Wins = 70, y_Wins = 2;
	int x_Points = 70, y_Points = 1;
	int x_CurrPoints = 4, y_CurrPoints = 2;
	int x_Exit = 100, y_Exit = 1;

	int y_turnHead = 12;
	int y_turnStomach = 16;
	int y_turnLegs = 22;

	int x_draw = 50;
public:
	void printColor(int pos, int ch)
	{
		if (pos == ch) {
			SetColor(White, Red);
		}
		else SetColor(White, Black);

	}

	void drawChoiceHit(int pos)
	{
		SetCursorPosition(x_ChoiceHit, y_ChoiceHit);
		printColor(pos, 1);
		cout << " Удар в голову. ";
		SetCursorPosition(x_ChoiceHit, y_ChoiceHit + 1);
		printColor(pos, 2);
		cout << " Удар в живот. ";
		SetCursorPosition(x_ChoiceHit, y_ChoiceHit + 2);
		printColor(pos, 3);
	    cout << " Удар в ноги. ";
		SetColor(White, Black);
	}

	//Движение по пунктам меню
	int position(int pos, char ch)
	{
		if (ch == 80) {
			//вниз
			if (pos >= 3) {
				pos = 1;
			}
			else  pos++;
		}
		if (ch == 72) {
			//вверх
			if (pos <= 1) {
				pos = 3;
			}
			else  pos--;
		}
		return pos;
	}

	void drawChoiceProtection(int pos)
	{
		SetCursorPosition(x_ChoiceHit + 18, y_ChoiceHit);
		printColor(pos, 1);
		cout << " Защита головы.";
		SetCursorPosition(x_ChoiceHit + 18, y_ChoiceHit + 1);
		printColor(pos, 2);
		cout << " Защита живота.";
		SetCursorPosition(x_ChoiceHit + 18, y_ChoiceHit + 2);
		printColor(pos, 3);
		cout << " Защита ног.";
		SetColor(White, Black);
	}

	void drawInfoLoginPlayer(string login)
	{
		SetCursorPosition(x_infoPlayer, y_infoPlayer);
		cout << "Игрок: " << login;
	}

	void drawWinsPlayer(int wins)
	{
		SetCursorPosition(x_Wins, y_Wins);
		cout << "Побед: " << wins;
	}

	void drawCurrentPoints(int points)
	{
		SetCursorPosition(x_CurrPoints, y_CurrPoints);
		cout << "Текущий счет: " << points;
	}

	void drawPoints(int points)
	{
		SetCursorPosition(x_Points, y_Points);
		cout << "Счет: " << points;
	}

	void drawExit()
	{
		SetCursorPosition(x_Exit, y_Exit);
		cout << "Exit = ESC";
	}

    void isDrawX(bool draw, int y)
	{
		if (draw)
		{  SetColor(LightRed, Black);
	    SetCursorPosition(x_draw, y);
		cout << "\\";
		SetCursorPosition(x_draw + 1, y);
		cout << "/";
		SetCursorPosition(x_draw, y + 1);
		cout << "/";
		SetCursorPosition(x_draw + 1, y + 1);
		cout << "\\";
		SetColor(White, Black);
		}
		else
		{
			SetCursorPosition(x_draw, y);
			cout << "  ";
			SetCursorPosition(x_draw + 1, y);
			cout << "  ";
			SetCursorPosition(x_draw, y + 1);
			cout << "  ";
			SetCursorPosition(x_draw + 1, y + 1);
			cout << "  ";
			SetColor(White, Black);
		}
	   
	}

	void drawDraw(bool draw,int part)
	{
		int y;
		if (draw)
		{
			if (part == Head)
			{
				y = y_turnHead;
				isDrawX(true, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				isDrawX(true, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				isDrawX(true, y);
			}
		}
		else
		{
			if (part == Head)
			{
				y = y_turnHead;
				isDrawX(false, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				isDrawX(false, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				isDrawX(false, y);
			}
		}
		
	}

	
};