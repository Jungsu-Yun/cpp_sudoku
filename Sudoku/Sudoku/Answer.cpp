#include "pch.h"
#include "Answer.h"
#include <fstream>
#include <iostream>
#include <string>
#define GameCount 9

using namespace std;

Answer::Answer() {

	answer = new int *[9];
	for (int i = 0; i < 9; i++)
		answer[i] = new int[9];
}

void Answer::Generate() {

	int RandomFileNumber = rand() % 9;
	string FileName[GameCount] =
	{ "data\\1.txt", "data\\2.txt", "data\\3.txt", "data\\4.txt", "data\\5.txt", "data\\6.txt", "data\\7.txt", "data\\8.txt", "data\\9.txt" };

	char inputString[100] = { 0, };
	ifstream inFile(FileName[RandomFileNumber]);
	if (!inFile.is_open()) {
		cout << " Error. There is no Answer File." << endl;
		cout << " Please, check your Computer File." << endl;
		exit(1);
	}
	while (!inFile.eof()) {
		inFile.getline(inputString, 100);
	}
	inFile.close();

	int count = 0;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			answer[i][j] = inputString[count] - '0';
			++count;
		}
}

Answer::~Answer() {

	for (int i = 0; i < 9; i++)
		delete[] answer[i];
	delete answer;
}