#pragma once
#include "Level.h"
#include "Answer.h"

class Question : public Level, Answer
{
protected:
	int **questionsheet;
	int **worksheet;
public:
	Question();
	void Generate();
	~Question();
};