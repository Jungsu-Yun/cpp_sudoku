#pragma once
//#include "Question.h"

class input
{
private:
	int row;
	int coloum;
	int value;

public:
	void init();
	void ExpectionCheck(int value);
	void DuplicateCheck(int value);
	void FillintheBlank(int row, int coloum, int value);
	void reset();
};

