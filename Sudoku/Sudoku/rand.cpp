#include <iostream>
#include "pch.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int random = 0;
	for (int i = 0; i < 10; i++)
	{
		random = rand() % 10 + 1;

		//printf("", ramdom);
	}

	return 0;
}