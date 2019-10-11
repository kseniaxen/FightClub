#pragma once
#include "Interface Players.h"



class Player
{
	InterfacePlayer *in_Player;
	Alerts *alerts;
	int health;
	int damage = 100;
public:
	Player(InterfacePlayer *in_Player, Alerts *alerts)
	{
		this->in_Player = in_Player;
		this->alerts = alerts;
		this->health = 1000;
	}

	void setHealth()
	{
		this->health = 1000;
	}

	void drawPicture()
	{
		in_Player->drawCharacter();
	}

	int getHealth()const
	{
		return health;
	}

	void damageHealth(int damage)
	{
		this->health -= damage;
	}

	int damageEnemy()const
	{
		return damage;
	}

	void currentHealth()
	{
		in_Player->drawHealth(true,getHealth());
	}

	void turnToEnemy(int part)
	{
		in_Player->drawTurn(true,part);
	}

	void blockMyself(int part)
	{
		in_Player->drawBlock(true,part);
	}

	void currentDamageHealth(int part)
	{
		alerts->drawAlertsDamage(part, getHealth());
	}

	void Delete(int partTurn, int partBlock)
	{
		in_Player->drawTurn(false, partTurn);
		in_Player->drawBlock(false, partBlock);
		alerts->deleteAlert();
	}

	void deleteAlerts()
	{
		alerts->deleteAlert();
	}

	void deleteHealth()
	{
		in_Player->drawHealth(false, health);
	}

	void drawWin()
	{
		alerts->drawWinAlertPlayer();
	}

	void drawDraw()
	{
		alerts->drawDrawAlert();
	}

	int random()const
	{
		return 1 + rand() % 3;
	}

	void drawDrawInGame()
	{
		alerts->drawDrawProcessGame();
	}

};

