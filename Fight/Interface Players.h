#pragma once
#include <string>
#include <iostream>
#include "SetCursor.h"
#include "Color.h"

using namespace std;

enum Parts
{
	Head = 1, Stomach, Legs
};

class InterfacePlayer
{
public:
	virtual void drawCharacter() = 0;
	virtual void drawTurn(bool draw,int part) = 0;
	virtual void drawBlock(bool draw,int part) = 0;
	virtual void drawHealth(bool draw,int health) = 0;
	virtual void drawPicTurn(bool draw, int y) = 0;
	virtual void drawPicBlock(bool draw, int y) = 0;
};

class RealPlayerInterface :public InterfacePlayer
{
	int x = 5;
	int x_turn = 42, x_block = 37;
	int y_turnHead = 12;
	int y_turnStomach = 16;
	int y_turnLegs = 22;

public:
	void drawCharacter()override
	{
		SetColor(White, Black);
		SetCursorPosition(x, 5);
		cout << "    / \\    ";
		SetCursorPosition(x, 6);
		cout << "	 | |        ";
		SetCursorPosition(x, 7);
		cout << "	 |.|";
		SetCursorPosition(x, 8);
		cout << "	 |.|";
		SetCursorPosition(x, 9);
		cout << "    |:|     ___";
		SetCursorPosition(x, 10);
		cout << " ,_ |:| _, /   )";
		SetCursorPosition(x, 11);
		cout << "	(Oo    /__I__";
		SetCursorPosition(x, 12);
		cout << "	+\\ \\  || __ |";
		SetCursorPosition(x, 13);
		cout << "	  \\ \\ ||____|";
		SetCursorPosition(x, 14);
		cout << "	    \\  / .:.\\-\\";
		SetCursorPosition(x, 15);
		cout << "	      | .:. /-----\\";
		SetCursorPosition(x, 16);
		cout << "         | __ |::oOo::|";
		SetCursorPosition(x, 17);
		cout << "         /    |:<_T_>:|";
		SetCursorPosition(x, 18);
		cout << "        |_____ \\ ::: /";
		SetCursorPosition(x, 19);
		cout << "         | | \\  \\:/";
		SetCursorPosition(x, 20);
		cout << "         | |  | |";
		SetCursorPosition(x, 21);
		cout << "         \\ /  | \\___";
		SetCursorPosition(x, 22);
		cout << "         / |  \\_____\\";
		SetCursorPosition(x, 23);
		cout << "         `-'";
	}

	void drawPicTurn(bool draw, int y)override
	{
		if (draw)
		{
			SetColor(LightRed, Black);
			SetCursorPosition(x_turn, y);
			cout << "====>";
			SetColor(White, Black);
		}
		else
		{
			//SetColor(LightRed, Black);
			SetCursorPosition(x_turn, y);
			cout << "       ";
			SetColor(White, Black);
		}
	}

	void drawTurn(bool draw,int part)override
	{
		int y;
		if (draw)
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicTurn(true, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicTurn(true, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicTurn(true, y);
			}
		}
		else
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicTurn(false, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicTurn(false, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicTurn(false, y);
			}
		}
	}

	void drawPicBlock(bool draw, int y)override
	{
		if (draw)
		{
			SetColor(Green, Green);
			SetCursorPosition(x_block, y);
			cout << "###";
			SetCursorPosition(x_block, y + 1);
			cout << "###";
			SetColor(White, Black);
		}
		else
		{
			//SetColor(Green, Green);
			SetCursorPosition(x_block, y);
			cout << "    ";
			SetCursorPosition(x_block, y + 1);
			cout << "    ";
			SetColor(White, Black);
		}
	}

	void drawBlock(bool draw,int part)override
	{
		int y;
		if (draw)
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicBlock(true, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicBlock(true, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicBlock(true, y);
			}
		}
		else
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicBlock(false, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicBlock(false, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicBlock(false, y);
			}
		}
	}

	void drawHealth(bool draw,int health)override
	{
		if (draw)
		{
			SetColor(White, Green);
			SetCursorPosition(x, 4);
			cout << "HP :" << health;
			SetColor(White, Black);
		}
		else
		{
			SetColor(White, Black);
			SetCursorPosition(x, 4);
			cout << "                  ";
			SetColor(White, Black);
		}
		
	}

};

class ComputerPlayerInterface: public InterfacePlayer
{
	int x = 70;
	int x_turn = 54 , x_block = 60, y_turnHead = 12;
	int y_turnStomach = 16;
	int y_turnLegs = 22;
	int x_draw = 46;
public:
	void drawCharacter()override
	{
		SetCursorPosition(x, 8);
		cout <<"|\\             //";
		SetCursorPosition(x, 9);
		cout <<" \\\\           _!_";
		SetCursorPosition(x, 10);
		cout <<"  \\\\         /___\\";
		SetCursorPosition(x, 11);
		cout <<"	 \\\\        [+++]";
		SetCursorPosition(x, 12);
		cout <<"	  \\\\    _ _\\^^^/_ _";
		SetCursorPosition(x, 13);
		cout <<"	   \\\\/ (    '-'  ( )";
		SetCursorPosition(x, 14);
		cout <<"	  /( \\/ |  {&}   /\\ \\";
		SetCursorPosition(x, 15);
		cout <<"	    \\  / \\      / _> )";
		SetCursorPosition(x, 16);
		cout <<"       \"`   >:::;- '`\"\"\'-.";
		SetCursorPosition(x, 17);
		cout <<"		 /:::/          \\";
		SetCursorPosition(x, 18);
		cout <<"	        /  /||    {&}   |";
		SetCursorPosition(x, 19);
		cout <<"         (  / (\\          /";
		SetCursorPosition(x, 20);
		cout <<"	       / /   \\ '-.___.-'";
		SetCursorPosition(x, 21);
		cout <<"	     _/ /     \\ \\";
		SetCursorPosition(x, 22);
		cout <<"	   /___|     /___|";
	}

	void drawPicTurn(bool draw, int y)override
	{
		if (draw)
		{
			SetColor(LightRed, Black);
			SetCursorPosition(x_turn, y);
			cout << "<====";
			SetColor(White, Black);
		}
		else
		{
			//SetColor(LightRed, Black);
			SetCursorPosition(x_turn, y);
			cout << "       ";
			SetColor(White, Black);
		}
	}

	void drawTurn(bool draw, int part)override
	{
		int y;
		if (draw)
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicTurn(true, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicTurn(true, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicTurn(true, y);
			}
		}
		else
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicTurn(false, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicTurn(false, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicTurn(false, y);
			}
		}
	}

	void drawPicBlock(bool draw, int y)override
	{
		if (draw)
		{
			SetColor(Green, Green);
			SetCursorPosition(x_block, y);
			cout << "###";
			SetCursorPosition(x_block, y + 1);
			cout << "###";
			SetColor(White, Black);
		}
		else
		{
			//SetColor(Green, Green);
			SetCursorPosition(x_block, y);
			cout << "    ";
			SetCursorPosition(x_block, y + 1);
			cout << "    ";
			SetColor(White, Black);
		}
	}

	void drawBlock(bool draw, int part)override
	{
		int y;
		if (draw)
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicBlock(true, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicBlock(true, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicBlock(true, y);
			}
		}
		else
		{
			if (part == Head)
			{
				y = y_turnHead;
				drawPicBlock(false, y);
			}
			else if (part == Stomach)
			{
				y = y_turnStomach;
				drawPicBlock(false, y);
			}
			else if (part == Legs)
			{
				y = y_turnLegs;
				drawPicBlock(false, y);
			}
		}
	}

	void drawHealth(bool draw, int health)override
	{
		if (draw)
		{
			SetColor(White, Red);
			SetCursorPosition(x+10, 4);
			cout << "HP :" << health;
			SetColor(White, Black);
		}
		else
		{
			SetColor(White, Black);
			SetCursorPosition(x+10, 4);
			cout << "                  ";
			SetColor(White, Black);
		}

	}

};