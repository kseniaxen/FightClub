#pragma once
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <fstream>
#include <regex>
#include <sstream>
#include "SetCursor.h"

#pragma comment(lib,"ws2_32.lib")

using namespace std;

std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	}
	catch (...) {
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return result;
}

class User
{
	string userLogin;
	string userPassword;
	int points;
	int wins;
public:
	User()
	{
		userLogin = "";
		userPassword = "";
		points = 0;
		wins = 0;
	}
	User(string userLogin, string userPassword, int points, int wins)
	{
		this->userLogin = userLogin;
		this->userPassword = userPassword;
		this->points = points;
		this->wins = wins;
	}

	void setUserLogin(string login)
	{
		this->userLogin = login;
	}

	void setUserPassword(string pas)
	{
		this->userPassword = pas;
	}

	void setPointsWins(int points, int wins)
	{
		this->points = points;
		this->wins = wins;
	}

	string getUserLogin()const
	{
		return userLogin;
	}

	string getUserPassword()const
	{
		return userPassword;
	}

	int getPoints()const
	{
		return points;
	}

	int getWins()const
	{
		return wins;
	}

	string getAllInfo()const
	{
		return userLogin + " " + userPassword;
	}
};

class Registr :public User
{
	string fileName;
	User user;
public:
	Registr(string fileN, User user)
	{
		this->fileName = fileN;
		this->user = user;
	}

	int checkStrings()
	{
		string temp;
		ifstream file(fileName);
		int n = 0;
		if (file.is_open())
		{
			while (getline(file, temp))
			{
				n++;
			}
		}
		file.close();
		return n;
	}

	void Registration()
	{
		ifstream file(fileName);
		string temp;
		int counter = 0;
		if (!(file.is_open()))
		{
			ofstream ofFile(fileName);
			ofFile << "Login = " << "\"" << user.getUserLogin() << "\"" << " " << "Password = " << "\"" << user.getUserPassword() << "\"" << " " << "Points = " << "\"" <<user.getPoints()<< "\"" << " " << "Wins = " << "\"" << user.getWins() << "\""<<"\n";
			cout << "Регистрация прошла успешно!" << endl;
			file.close();
		}
		else
		{
			while (getline(file, temp))
			{
				regex rx("Login = \"(.+?)\" Password = \"(.+?)\"");
				cmatch res;
				regex_search(temp.c_str(), res, rx);
				if (res[1] != user.getUserLogin())
				{
					counter++;
				}
				else
				{
					counter = 0;
					break;
				}
			}
			createUser(counter);
		}
	}

	void createUser(int counter)
	{
		user.setPointsWins(0, 0);
		if (counter == 0)
		{
			cout << "Пользователь с таким именем уже зарегистрирован!" << endl;
		}
		else {
			ofstream ofFile(fileName, ios::app);
			ofFile << "Login = " << "\"" << user.getUserLogin() << "\"" << " " << "Password = " << "\"" << user.getUserPassword() << "\"" << " " << "Points = " << "\"" << user.getPoints() << "\"" << " " << "Wins = " << "\"" << user.getWins() << "\"" << "\n";
			cout << "Регистрация прошла успешно!" << endl;
		}
	}

};

class Autorization : public User
{
	string fileName;
	User user;
	int x_Reg = 5, y_Reg = 4;
public:

	Autorization(string fileName)
	{
		this->fileName = fileName;
	}

	Autorization(string fileName, User user)
	{
		this->fileName = fileName;
		this->user = user;
	}

	void Autorizat()
	{
		ifstream file(fileName);
		string temp;
		int counter = 0;
		string loginPlayer, passwordPlayer;
		if (!file.is_open())
		{
			cout << endl;
			cout << "Авторизация не может быть произведенна!" << endl;
		}
		else
		{
			bool isLogin = false;
			SetCursorPosition(x_Reg, y_Reg);
			cout << "Введите логин:";
			cin >> loginPlayer;
			while (getline(file, temp))
			{
				regex rx("Login = \"(.+?)\" Password = \"(.+?)\" Points = \"(.+?)\" Wins = \"(.+?)\"");
				cmatch res;
				regex_search(temp.c_str(), res, rx);
				if (res[1] == loginPlayer)
				{
					isLogin = true;
					user.setUserLogin(loginPlayer);
					SetCursorPosition(x_Reg, y_Reg + 2);
					cout << "Введите пароль:";
					cin >> passwordPlayer;
					if (res[2] == passwordPlayer)
					{
						user.setUserPassword(passwordPlayer);
						cout << endl;
						cout << "Пользователь: " << user.getUserLogin() << endl;

						stringstream strRes3, strRes4;
						strRes3 << res[3];
						strRes4 << res[4];

						int valRes3, valRes4;
						strRes3 >> valRes3;
						strRes4 >> valRes4;

						user.setPointsWins(valRes3,valRes4);
						cout << "Авторизация прошла успешно!" << endl;
						break;
					}
					else {
						cout << endl;
						cout << "Неверный пароль!" << endl;
						break;
					}
				}
			}
			if (!isLogin) {
				cout << endl;
				cout << "Нет такого пользователя!" << endl;
			}
		}
	}

	string getAutLogin()
	{
		return user.getUserLogin();
	}

	string getAutPassword()
	{
		return user.getUserPassword();
	}

	int getAutPoints()
	{
		return user.getPoints();
	}

	int getAutWins()
	{
		return user.getWins();
	}

	void setScoreWins()
	{
		ifstream file(fileName);
		string temp;
		int counter = 0;
		int lineDelete;
		string tmpLine;
		if (file.is_open())
		{
			while (getline(file, temp))
			{
				regex rx("Login = \"(.+?)\" Password = \"(.+?)\" Points = \"(.+?)\" Wins = \"(.+?)\"");
				cmatch res;
				regex_search(temp.c_str(), res, rx);
				counter++;
				if (!(res[1] == user.getUserLogin() && res[2] == user.getUserPassword()))
				{
					lineDelete = counter;
					// TODO Сделать удаление текущий строки и перезапись ее же.
					/*ofstream ofFile(fileName, ios::app);
					ofFile << "Login = " << "\"" << user.getUserLogin() << "\"" << " " << "Password = " << "\"" << user.getUserPassword() << "\"" << " " << "Points = " << "\"" << user.getPoints() << "\"" << " " << "Wins = " << "\"" << user.getWins() << "\"" << "\n";
				*/
					tmpLine.insert(tmpLine.size(), temp);
					tmpLine.insert(tmpLine.size(), "\r\n");
				}
			}
		}
		file.close();
		ofstream ofstr;
		ofstr.open(fileName, std::ios::trunc | std::ios::binary);
		ofstr.write(tmpLine.c_str(), tmpLine.size());
		ofstr << "Login = " << "\"" << user.getUserLogin() << "\"" << " " << "Password = " << "\"" << user.getUserPassword() << "\"" << " " << "Points = " << "\"" << user.getPoints() << "\"" << " " << "Wins = " << "\"" << user.getWins() << "\"" << "\n";
		ofstr.clear();
	}

	int checkStrings()
	{
		string temp;
		ifstream file(fileName);
		int n = 0;
		if (file.is_open())
		{
			while (getline(file, temp))
			{
				n++;
			}
		}
		file.close();
		return n;
	}

	void leaderBoard()
	{
		ifstream file(fileName);
		string tempStr;
		int counter = 0;
		int length = checkStrings();
		int *masPoints = new int[length];
		int *ind = new int[length];

		string *masStr = new string[length];
		int* masWins = new int[length];
		if (file.is_open())
		{
			int i = 0;
			while (getline(file, tempStr))
			{
				regex rx("Login = \"(.+?)\" Password = \"(.+?)\" Points = \"(.+?)\" Wins = \"(.+?)\"");
				cmatch res;
				regex_search(tempStr.c_str(), res, rx);
				stringstream strRes3, strRes4;
				strRes3 << res[3];
				strRes4 << res[4];

				int valRes3, valRes4;
				strRes3 >> valRes3;
				strRes4 >> valRes4;
				masPoints[i] = valRes3;
				masWins[i] = valRes4;
				masStr[i] = res[1];
				ind[i] = i;
				i++;
			}
		}

		for (int i = 1; i < length; ++i)
		{
			for (int r = 0; r < length - i; r++)
			{
				if (masPoints[r] < masPoints[r + 1])
				{
						// Обмен местами
					int temp = masPoints[r];
					masPoints[r] = masPoints[r + 1];
					masPoints[r + 1] = temp;

					int tmpInd = ind[r];
					ind[r] = ind[r + 1];
					ind[r + 1] = tmpInd;
					}
				}
			}

		for (size_t i = 0; i < length; i++)
		{
			SetCursorPosition(x_Reg, y_Reg + i);
			cout << masStr[ind[i]];
			SetCursorPosition(x_Reg + 25, y_Reg + i);
			cout << masPoints[i];
			SetCursorPosition(x_Reg + 50, y_Reg + i);
			cout << masWins[ind[i]];
		}

		
	}
};
