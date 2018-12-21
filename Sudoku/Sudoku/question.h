#pragma once
#include "answer.h"

class Question: public Answer
{
private:
	int* Question;

protected:
	int* WorkSheet;

public:

	void Generate_Question();

};
