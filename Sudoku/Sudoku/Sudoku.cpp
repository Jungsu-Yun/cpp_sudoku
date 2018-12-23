#include "pch.h"
#include <iostream>
#include "input.h"
#include "Answer.h"
#include "Question.h"
#include "Board.h"
#include <Windows.h>

using namespace std;


int main()
{
	//오프닝 멘트
	Input data;
	data.Generate();

	//게임시작
	data.printboard();

	while (true)
	{
		data.init();
		data.ExpectionCheck();
		if (data.ExpectionCheck() == true)
			data.DuplicateCheck();
		if (data.ExpectionCheck() == true && data.DuplicateCheck() == true)
		{
			data.FillintheBlank();
		}
		data.printboard();
		if (data.NumbofBlankCheck() == true)
			break;
	}
	//rest 검증
	//엔딩멘트

	return 0;
}