#include "pch.h"
#include "Answer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Answer::Answer() 
{
	answer = new char *[COLUME];
	for (int i = 0; i < ROW; i++)
		answer[i] = new char[ROW];
}

void Answer::Generate() {

	int RandomFileNumber = rand() % GAMECOUNT;
	string FileName[GAMECOUNT] =
	{ "data\\1.txt", "data\\2.txt", "data\\3.txt", "data\\4.txt", "data\\5.txt", "data\\6.txt", "data\\7.txt", "data\\8.txt", "data\\9.txt" };

	char inputString[FILEBUFFER] = { 0, };
	ifstream inFile(FileName[RandomFileNumber]);
	if (!inFile.is_open()) {
		cout << " Error. There is no Answer File." << endl;
		cout << " Please, check your Computer File." << endl;
		exit(1);
	}
	while (!inFile.eof()) {
		inFile.getline(inputString, FILEBUFFER);
	}
	inFile.close();

	int count = 0;
	for (int i = 0; i < COLUME; ++i)
		for (int j = 0; j < ROW; ++j) {
			answer[i][j] = inputString[count];
			++count;
		}
}

Answer::~Answer() {

	for (int i = 0; i < COLUME; i++)
		delete[] answer[i];
	delete answer;
}