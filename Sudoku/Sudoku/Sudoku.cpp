#include "pch.h"
#include <iostream>
#include "Sudoku.h"
#include "input.h"

using namespace std;

int main()
{
	while (true)
	{
		Input data;
		data.init();
		if (data.ExpectionCheck() == true)
			continue;
		else if (data.DuplicateCheck() == true)
			continue;
		else
			data.FillintheBlank();

		if (data.NumbofBlankCheck == true)
			break;
	}
	cout << "축하합니다! 모든 문제를 다 풀어내셨습니다!!" << endl;
	return 0;
}