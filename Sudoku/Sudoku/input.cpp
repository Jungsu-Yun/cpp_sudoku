#include "pch.h"
#include "input.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Input::Input()
{
	this->row = row;
	this->column = column;
	this->value = value;
	this->cnt = 0;
}

void Input::init()
{
	cout << endl;
	cout << "  입력하고자 하는 행/열/값을 입력해주세요! : ";
	cin >> this->row >> this->column >> this->value;
}
bool Input::ExpectionCheck()
{
	if (this->row < 1 || this->row > 9)
	{
		cout << endl;
		cout << "  한 행에는 1~9사이의 수만 존재합니다." << endl;
		Sleep(1000);
		return false;
	}
	else if (this->column < 1 || this->column > 9)
	{
		cout << endl;
		cout << "  한 열에는 1 ~ 9 사이의 수만 존재합니다" << endl;
		Sleep(1000);
		return false;
	}
	else if (this->value < 0 || this->value > 9)
	{
		cout << endl;
		cout << "  0 ~ 9 사이의 값만 입력할 수 있습니다." << endl;
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
			if (worksheet[this->column - 1][i] == value || worksheet[i][this->row - 1] == value)
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
	if (value != 0)
		++cnt;
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

bool Input::NumbofBlankCheck()
{
	if (cnt != NumberOfBlank)
		return false;

	return true;
}

void Input::reset()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			worksheet[i][j] = 0;
}