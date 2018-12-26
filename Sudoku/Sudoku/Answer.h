#pragma once

class Answer
{
protected:
	char **answer;
public:
	Answer();
	void Generate();
	~Answer();
};