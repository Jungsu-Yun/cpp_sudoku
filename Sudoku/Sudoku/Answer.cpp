#include "pch.h"
#include "Answer.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

Answer::Answer()
{
	this->answer = new int *[9];
	for (int i = 0; i < 9; i++)
	{
		answer[i] = new int[9];
	}
}

void Answer::Generate()
{
	char inputString[1000];
	std::ifstream inFile("1.txt");
	if (!inFile.is_open())
	{
		cout << "Error"; exit(1);
	}
	while (!inFile.eof())
	{
		inFile.getline(inputString, 100);
	}
	inFile.close();

	int tmp[81] = { 0, };
	for (int i = 0; i < 81; i++)
		tmp[i] = (int)inputString[i] - 48;

	int cnt = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			answer[i][j] = tmp[cnt];
			cnt++;
		}
}

Answer::~Answer()
{
	for (int i = 0; i < 9; i++)
		delete[] answer[i];
	delete answer;
}
