#pragma once
#include <string>
class Operator
{
public:
	std::string GetSymbol();
	int GetPriority();
	void SetSymbol(std::string newSymbol);
	void SetPriority();
	void AutoSet(std::string newSymbol);

private:
	std::string symbol;
	int priority = 0;

};


