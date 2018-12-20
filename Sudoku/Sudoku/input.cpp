#include "pch.h"
#include "input.h"
#include <iostream>

using namespace std;

void Input::init()
{
	cout << "입력하고자 하는 행/열/값을 입력해주세요 : ";
	cin >> this->row >> this->coloum >> this->value;

	cout << this->row << this->coloum << this->value << endl;
}
bool Input::ExpectionCheck()
{
	if (this->row < 1 || this->row > 9)
	{
		cout << "한 행에는 1~9사이의 수만 존재합니다. 다시 입력하세요" << endl;
		return false;
	}

	else if (this->coloum < 1 || this->coloum > 9)
	{
		cout << "한 열에는 1 ~ 9 사이의 수만 존재합니다" << endl;
		return false;
	}

	else if (this->value < 1 || this->value > 9)
	{
		cout << "1 ~ 9 사이의 값만 입력할 수 있습니다." << endl;
		return false;
	}
	
	return true;
}

bool Input::DuplicateCheck()
{
	Question q;
	for(int )
	return true;
}

bool Input::NumbofBlankCheck()
{
	if (Question->NumberofBlank == this -> count)
		return false;

	return true;
}

void Input::FillintheBlank()
{
	Question.row = this->row;
	Question.colum = this->coloum;
	Question.value = this->value;
	// board.board(this -> row, this -> col, this -> value);
	= this->data;

	count++;
}

void Input::reset()
{
}