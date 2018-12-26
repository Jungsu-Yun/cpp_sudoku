#pragma once
#include "Level.h"
#include "Answer.h"

class Question : public Answer
{
protected:
	char **questionsheet;
	char **worksheet;
	int NumberOfBlank;
public:
	Question();
	void Generate(int NumberOfBlank);
	~Question();
};