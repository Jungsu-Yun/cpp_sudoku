#pragma once
#include "Question.h"
#include "Level.h"

class Input : public Question, Level
{
protected:
	int row;
	int coloum;
	int value;
	int count = 0;

public:
	void init();
	bool ExpectionCheck();
	bool DuplicateCheck();
	bool NumbofBlankCheck();
	void FillintheBlank();
	void reset();
};

