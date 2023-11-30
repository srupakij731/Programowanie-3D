#pragma once
class Operator
{
public:
	char GetSymbol();
	int GetPriority();
	void SetSymbol(char _symbol);
	void SetPriority();
	void AutoSet(char _symbol);
private:
	char symbol;
	int priority;

};


