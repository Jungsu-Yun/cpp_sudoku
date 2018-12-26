#include "pch.h"
#include "input.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Input::Input()
: cnt(0){}

void Input::init()
{
	cout << endl;
	cout << "  입력하고자 하는 행/열/값을 입력해주세요! : ";
	cin >> this->row;
	if (this->row == 'q' || this->row == 'Q')
		this->UserMode = 1;
	else if (this->row == 'w' || this->row == 'W')
		this->UserMode = 2;
	else if (this->row == 'e' || this->row == 'E')
		this->UserMode = 3;
	else
	{
		cin >> this->column >> this->value;
		this->UserMode = 0;
	}
		
}
bool Input::ExpectionCheck()
{
	if (this->row < 1 || this->row > 9 || this->column < 1 || this->column > 9 || this->value < 0 || this->value > 9)
	{
		cout << endl;
		cout << "  잘못된 값입니다. 다시 입력해 주세요." << endl;
		Sleep(1000);
		return false;
	}
	return true;
}

bool Input::DuplicateCheck()
{
	if (questionsheet[this->column - 1][this->row - 1] != 0)
	{
		cout << endl;
		cout << "  해당 칸에는 이미 값이 있습니다! 다시 입력해주세요!" << endl;
		Sleep(1000);
		return false;
	}
	if (value != 0)
		for (int i = 0; i < 9; i++)
			if (worksheet[this->column - 1][i] == value || worksheet[i][this->row - 1] == value || questionsheet[this->column - 1][i] == value || questionsheet[i][this->row - 1] == value)
			{
				cout << endl;
				cout << "  중복값이 존재합니다. 다시 입력해주세요!" << endl;
				Sleep(1000);
				return false;
			}
	return true;
}

int& Input::FillintheBlank()
{
	if (worksheet[this->column - 1][this->row - 1] == 0)
		cnt++;
	return worksheet[this->column - 1][this->row - 1] = this->value;
}

bool Input::ResetCheck()
{
	if (this->row == 0 && this->column == 0 && this->value == 0)
	{
		reset();
		return true;
	}
	return false;
}

bool Input::InterruptCheck()
{
	if (this->row == 10 && this->column == 10 && this->value == 10)
		return true;
	return false;
}

void Input::print()
{
	cout << this->row << this->column << this->value << this -> UserMode << endl;
}

bool Input::NumbofBlankCheck()
{
	if (cnt == NumberOfBlank)
		return true;

	return false;
}

void Input::reset()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			worksheet[i][j] = 0;
	cnt = 0;
}