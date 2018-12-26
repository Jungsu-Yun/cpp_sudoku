#include "pch.h"
#include "input.h"
#include "Display.h"
#include "Windows.h"
#include <mmsystem.h>
#include <ctime>
#include <iostream>

#pragma comment(lib, "Winmm.lib")
#define SOUND_FILE_NAME ".\\sound\\bgm.wav"

using namespace std;

int main()
{
	system("mode con: cols=92 lines=30");
	
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	clock_t start, end;

	Input data;

	data.init();
	data.print();
	/*
	Display ending;
	while(true)
	{
		data.Generate();
		data.printboard();
		start = clock();
		while (true)
		{
			data.init();
			if (data.UserMode == 1)
				break;
			else if (data.UserMode == 2)
				data.reset();
			else if (data.UserMode == 3)
				break;
			else
			{
				if (data.ExpectionCheck() == true)
				{
					if (data.DuplicateCheck() == true)
						data.FillintheBlank();
				}
				if (data.NumbofBlankCheck() == true)
				{
					ending.Check(data.UserMode);
					break;
				}
				data.printboard();
			}
		}
		if (ending.Check(data.UserMode) == false)
		{
			ending.shutdown();
			break;
		}
		else
		{
			end = clock();
			ending.ending(start, end);
			break;
		}
	}
	*/
	return 0;
}