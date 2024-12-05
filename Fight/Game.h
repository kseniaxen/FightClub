#pragma once
#include <Windows.h>
#include <string>
#include "Interface Game.h"
#include "Interface Players.h"
#include "Interface Alerts.h"
#include "Logic players.h"

enum Keys
{
	ARROW_UP = 72, ARROW_DOWN = 80, ARROW_LEFT = 77, ARROW_RIGHT = 75, EXIT = 27, ENTER = 13, SPACE = 32
};

class Game
{
	string namePlayer;
	InterfaceMenu menu;

	Player* player; /*= new RealPlayer(new RealPlayerInterface, new Alerts(namePlayer));*/
	Player* computer = new Player(new ComputerPlayerInterface, new Alerts("Компьютер"));

	
	int turnKeyPlayer;
	int blockKeyPlayer;

	int turnComputer;
	int blockComputer;
	
	int currentPoint = 0;
	int pointsPlayer;
	int winsPlayer;

	const int POINTS = 100;

	bool exit = false;
	bool isDamageComputer = false;
	//int key;
public:
	Game(string namePlayer, int points, int wins, Player *player)
	{
		this->namePlayer = namePlayer;
		this->pointsPlayer = points;
		this->winsPlayer = wins;
		this->player = player;

	}

	void startPlay()
	{
		int positionTurn = 1;
		int positionBlock = 1;
		bool timeToChoiceHit = true;
		bool timeToChoiceBlock = false;
		int key;

		int countArrowLeft = 0;
		bool checkChoiceBlock = false;
		bool checkComputerTurn = false;

		bool showDeleteBlocks = true;

		bool startAgainGame = true;
		

		do
		{
			system("cls");
			mainDontChange();
			menu.drawChoiceProtection(positionBlock);
			menu.drawWinsPlayer(winsPlayer);
			menu.drawPoints(pointsPlayer);
			menu.drawCurrentPoints(currentPoint);
			computer->currentHealth();
			player->currentHealth();
			//Время когда выбирается место удара
			if (timeToChoiceHit)
			{
				menu.drawChoiceHit(positionTurn);
			}
			//Время когда выбирается место блока
			if (timeToChoiceBlock)
			{
				menu.drawChoiceProtection(positionBlock);
				checkChoiceBlock = true;
			}

			key = _getch();

			if (startAgainGame)
			{
				//Движение по меню выбору 
				if (key == ARROW_UP || key == ARROW_DOWN)
				{
					if (timeToChoiceHit)
					{
						positionTurn = menu.position(positionTurn, key);
					}
					else{ positionBlock = menu.position(positionBlock, key); }
				}
				//Клавиша влево если выбрали место для удара
				if (key == ARROW_LEFT)
				{
					countArrowLeft++;
					if (countArrowLeft < 2)
					{
						timeToChoiceHit = false;
						turnKeyPlayer = positionTurn;
						timeToChoiceBlock = true;
						countArrowLeft = 0;
					}
				}
				if (showDeleteBlocks)
				{
					player->Delete(turnKeyPlayer, blockKeyPlayer);
					computer->Delete(turnComputer,blockComputer);
					menu.drawDraw(false, turnKeyPlayer);
				}
				//Отрисовка места блока и удара
				if (key == ENTER)
				{
					if (checkChoiceBlock)
					{
						showDeleteBlocks = false;
						blockKeyPlayer = positionBlock;
						timeToChoiceBlock = false;
						player->turnToEnemy(turnKeyPlayer);
						player->blockMyself(blockKeyPlayer);

						Sleep(1000);
						turnComputer = computer->random();
						blockComputer = computer->random();
						computer->turnToEnemy(turnComputer);
						computer->blockMyself(blockComputer);
						resultOfFight();
						if (isDamageComputer)
						{
							currentPoint += POINTS;
						}
						Sleep(5000);
					}
					timeToChoiceHit = true;
					checkChoiceBlock = false;
					showDeleteBlocks = true;
					isDamageComputer = false;
					player->deleteHealth();
					computer->deleteHealth();
				}

				if (player->getHealth() <= 0 || computer->getHealth() <= 0)
				{
					endGame();
					pointsPlayer += currentPoint;
					key = _getch();
					//Здесь прибавляются победы и общий счет
					if (key == SPACE)
					{
						player->setHealth();
						computer->setHealth();
						startAgainGame = true;
					}
					else {
						startAgainGame = false;
					}
				}
			}

			if (key == EXIT)
			{
				exit = true;
			}
		} while (!exit);
	}


	void mainDontChange()
	{
		menu.drawInfoLoginPlayer(namePlayer);
		menu.drawExit();
		player->drawPicture();
		computer->drawPicture();
	}

	void isWinPlayer()
	{
		computer->damageHealth(player->damageEnemy());
		computer->currentDamageHealth(turnKeyPlayer);
		isDamageComputer = true;
	}

	void isWinComputer()
	{
		player->damageHealth(computer->damageEnemy());
		player->currentDamageHealth(turnComputer);
	}

	void isDraw(int random)
	{
		if (random == 1)
		{
			player->drawDrawInGame();
			isWinPlayer();
		}
		else
		{
			computer->drawDrawInGame();
			isWinComputer();
		}
	}

	void resultOfFight()
	{
		if (turnKeyPlayer != blockComputer)
		{
			isWinPlayer();
		}
		 if (turnComputer != blockKeyPlayer)
		{
			isWinComputer();
		}
		 if (turnKeyPlayer == turnComputer)
		{
			menu.drawDraw(true,turnKeyPlayer);
			int random = 1 + rand() % 2;
			switch (random)
			{
			case 1:
				isDraw(random);
				break;
			case 2:
				isDraw(random);
				break;
			default:
				break;
			}
		}
	}

	void endGame()
	{
		player->deleteAlerts();
		computer->deleteAlerts();
		if (player->getHealth() <= 0)
		{
			computer->drawWin();
		}
		else if (computer->getHealth() <= 0)
		{
			player->drawWin();
			this->winsPlayer++;
		}
		else if (player->getHealth() <= 0 && computer->getHealth() <= 0)
		{
			player->drawDraw();
			
		}
	}

	int getAllPointsGame()
	{
		return this->pointsPlayer;
	}

	int getWinsGame()
	{
		return this->winsPlayer;
	}

};