#include "pch.h"
#include "Question.h"
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

Question::Question()
{
	this->questionsheet = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		questionsheet[i] = new int[9];
		memset(questionsheet[i], 0, sizeof(int) * 9);
	}

	this->worksheet = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		worksheet[i] = new int[9];
		memset(worksheet[i], 0, sizeof(int) * 9);
	}
}

void Question::Generate()
{
	Answer::Generate();
	Level::DecisionBlankNumber();

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			this->questionsheet[i][j] = this->answer[i][j];

	srand(time(0));
	for (int k = 0; k < NumberofBlank; k++)
	{
		int i = rand() % 9;
		int j = rand() % 9;
		if (questionsheet[i][j] == 0)
			k--;
		else
			questionsheet[i][j] = 0;
	}
	copy();
}

void Question::copy()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			worksheet[i][j] = questionsheet[i][j];
}

void Question::Printsheet()
{
	system("cls");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << worksheet[i][j];
		cout << endl;
	}
}

Question::~Question()
{
	for (int i = 0; i < 9; i++)
		delete[] questionsheet[i];
	delete[] questionsheet;

	for (int i = 0; i < 9; i++)
		delete[] worksheet[i];
	delete[] worksheet;
}
