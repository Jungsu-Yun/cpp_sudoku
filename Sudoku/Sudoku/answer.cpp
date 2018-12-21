#include <iostream>
#include "pch.h"
#include "answer.h"
#include <fstream>

using namespace std;

int Answer::generate_answer(int row, int column, int value)
{
	Board answer;
	int i, j, k;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			k = rand() % 9 + 1;
			answer(i, j, k);

		}
	}

	char inputString[1000];
	std::ifstream inFile("1.txt");
	if (!inFile.is_open()) {
		std::cout << "Error"; exit(1); }
	while (!inFile.eof()) {
		inFile.getline(inputString, 82);
		std::cout << inputString << std::endl;
	}
	inFile.close();

	return 0;
}

void Answer::duplicate_check()
{
}