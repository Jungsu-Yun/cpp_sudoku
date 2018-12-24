#include "pch.h"
#include <iostream>
#include "Board.h"
#include "Level.h"
#include "Answer.h"
#include "Question.h"
#include "input.h"
#include "Windows.h"

using namespace std;

int main()
{
	Input data;
	data.Generate();
	data.printboard();

	while (true)
	{
		data.init();
		if (data.ResetCheck() == false)
		{
			if (data.InterruptCheck() == true)
				break;
			else
			{
				data.ExpectionCheck();
				if (data.ExpectionCheck() == true)
					data.DuplicateCheck();
				if (data.ExpectionCheck() == true && data.DuplicateCheck() == true)
					data.FillintheBlank();
				if (data.NumbofBlankCheck() == true)
					break;
			}
			data.printboard();
		}
	}
	system("cls");
	cout << "                     _         _ " << endl <<
		"                    | |       | |" << endl <<
		"     ____ _    _   _| | ____  | | ___  _   _" << endl <<
		"    / ___| |  | |/ _  |/ __ ＼| |/  / | | | |" << endl <<
		"    ＼__ ＼|__| | (_| || (_) ||   <   | |_| |" << endl <<
		"    |____/＼____/＼___|＼____/|_|＼_＼＼____/" << endl;

	return 0;
}
