#include "pch.h"
#include "input.h"
#include <iostream>
#include <string.h>
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
	cout << "입력하고자 하는 행/열/값을 입력해주세요 : ";
	cin >> this->row >> this->column >> this->value;
}
bool Input::ExpectionCheck()
{
	if (this->row < 1 || this->row > 9)
	{
		cout << "한 행에는 1~9사이의 수만 존재합니다." << endl;
		Sleep(1000);
		return false;
	}

	else if (this->column < 1 || this->column > 9)
	{
		cout << "한 열에는 1 ~ 9 사이의 수만 존재합니다" << endl;
		Sleep(1000);
		return false;
	}

	else if (this->value < 1 || this->value > 9)
	{
		cout << "1 ~ 9 사이의 값만 입력할 수 있습니다." << endl;
		Sleep(1000);
		return false;
	}

	return true;
}

bool Input::DuplicateCheck()
{
	if (questionsheet[this->row - 1][this->column - 1] != 0)
	{
		cout << "해당 칸에는 이미 값이 있습니다! 다시 입력해주세요!" << endl;
		Sleep(1000);
		return false;
	}

	for (int i = 0; i < 9; i++)
		if (worksheet[this->row - 1][i] == value || worksheet[i][this->column - 1] == value)
		{
			cout << "중복값이 존재합니다. 다시 입력해주세요!" << endl;
			Sleep(1000);
			return false;
		}

	return true;
}

int& Input::FillintheBlank()
{
	++cnt;
	return worksheet[this->row - 1][this->column - 1] = this->value;
}

bool Input::NumbofBlankCheck()
{
	if (cnt != NumberofBlank)
		return false;

	return true;
}


void Input::reset()
{
	Question::copy();
}

void Input::countprint()
{
	cout << this->cnt << endl;
}

Input::~Input()
{
}
