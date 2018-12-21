#pragma once
// "board.h"
#include <cstddef>

class  Answer //: public Cell
{
protected:
	int row;
	int column;
	int value;

public:
	int generate_answer(int row, int column, int value);
	void duplicate_check();

};
