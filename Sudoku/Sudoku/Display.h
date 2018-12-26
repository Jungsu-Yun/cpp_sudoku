#pragma once
#include <ctime>

class Display
{
protected:
	int **questionsheet;
	int **worksheet;
public:
	bool Check(int data);
	void ending(clock_t start, clock_t end);
	void shutdown();
};