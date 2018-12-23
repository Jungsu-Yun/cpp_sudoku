#include "pch.h"
#include "Level.h"
#include  <iostream>

using namespace  std;


Level::Level()
{
}

int& Level::DecisionBlankNumber()
{
	int tmp;
	while (true)
	{
		cout << "레벨을 선택하세요! : ";
		cin >> tmp;
		if (tmp == 1)
		{
			NumberofBlank = 30;
			break;
		}
		else if (tmp == 2)
		{
			NumberofBlank = 40;
			break;
		}
		else if (tmp == 3)
		{
			NumberofBlank = 50;
			break;
		}
		else
			cout << "레벨은 1 ~ 3 사의 숫자로만 가능합니다! 다시 입력해주세요." << endl;
	}
	return this->NumberofBlank;
}

Level::~Level()
{
}
