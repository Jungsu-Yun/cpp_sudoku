#include "pch.h"
#include <iostream>
#include "Board.h"
#include "Level.h"
#include "Answer.h"
#include "Question.h"
#include "input.h"
#include "Windows.h"
#include <mmsystem.h>
#include <ctime>

#pragma comment(lib, "Winmm.lib")
#define SOUND_FILE_NAME ".\\sound\\bgm.wav"
using namespace std;

int main()
{
	system("mode con: cols=92 lines=30");
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	clock_t start, end;

	Input data;
	data.Generate();
	data.printboard();
	start = clock();
	while (true)
	{
		data.init();
		if (data.ResetCheck() == false)
		{
			if (data.InterruptCheck() == true)
				break;
			else
			{
				if (data.ExpectionCheck() == true)
				{
					if (data.DuplicateCheck() == true)
						data.FillintheBlank();
				}
				if (data.NumbofBlankCheck() == true)
					break;
			}
		}
		data.printboard();
	}
	end = clock();
	system("cls");
	cout.precision(2);

	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "                                  소요 시간 : " << (((end - start) / CLOCKS_PER_SEC) / 60) % 60 << " 분  " << (end - start) / CLOCKS_PER_SEC % 60 << " 초" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "                                         _         _ " << endl <<
		"                                        | |       | |" << endl <<
		"                         ____ _    _   _| | ____  | | ___  _   _" << endl <<
		"                        / ___| |  | |/ _  |/ __ ＼| |/  / | | | |" << endl <<
		"                        ＼__ ＼|__| | (_| || (_) ||   <   | |_| |" << endl <<
		"                        |____/＼____/＼___|＼____/|_|＼_＼＼____/" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << endl << "                               Designed by 'Team Bed Smell'" << endl
		<< "                                 Thank you for enjoying!!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Sleep(5000);

	return 0;
}
