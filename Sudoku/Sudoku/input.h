#pragma once
#include "Question.h"
#include "Board.h"

class Input : public Board
{
protected:
	int row;
	int column;
	int value;
	int cnt;

public:
	Input();
	void init();
	bool ExpectionCheck();
	bool DuplicateCheck();
	bool NumbofBlankCheck();
	int& FillintheBlank();
	void countprint();
	void reset();
	~Input();
};
