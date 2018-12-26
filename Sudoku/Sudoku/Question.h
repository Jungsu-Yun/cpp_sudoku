#pragma once
#include "Level.h"
#include "Answer.h"

class Question : public Level, Answer
{
protected:
	char **questionsheet;
	char **worksheet;
public:
	Question();
	void Generate();
	~Question();
};