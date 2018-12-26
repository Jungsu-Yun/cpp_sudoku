#include "pch.h"
#include "Board.h"
#include "Question.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Board::Board()
{
	colorset = new char *[COLUME];
	for (int i = 0; i < COLUME; i++)
	{
		colorset[i] = new char[ROW];
		memset(colorset[i], 0, sizeof(char)*ROW);
	}


	question = new char[81];
	userdata = new char[81];
}

void Board::init(char* array, int** data)
{
	int cnt = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (data[i][j] == 0)
				array[cnt] = ' ';
			else
			{
				array[cnt] = data[i][j] + '0';
			}
			cnt++;
		}
}

void Board::input()
{
	init(question, questionsheet);
	init(userdata, worksheet);
	int count = 0;
	for (int i = 4; i < 21; i++)
	{
		for (int j = 7; j < 42; j++)
		{
			if (i % 2 == 0 && j % 4 == 3)
			{
				if (question[count] == ' ')
				{
					board[i][j] = userdata[count];
					colorset[i][j] = 'g';
				}
				else
				{
					board[i][j] = question[count];
					colorset[i][j] = 'y';
				}
				count++;
			}
		}
	}
}

void Board::printboard()
{
	input();

	system("cls");
	cout << endl << endl;
	for (int i = 0; i < COLUME; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (colorset[i][j] == 'g')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << board[i][j];
			}
			else if (colorset[i][j] == 'y')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << board[i][j];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				cout << board[i][j];
			}
		}
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

}

Board::~Board()
{
	for (int i = 0; i < COLUME; i++)
		delete[] colorset[i];
	delete[] colorset;

	delete[] userdata;
	delete[] question;
}
