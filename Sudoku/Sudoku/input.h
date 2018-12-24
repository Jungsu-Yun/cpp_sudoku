#pragma once
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
	bool ResetCheck();
	bool InterruptCheck();
	void reset();
};
