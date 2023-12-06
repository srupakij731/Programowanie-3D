#pragma once
class Operator
{
public:
	std::string GetSymbol();
	int GetPriority();
	void SetSymbol(std::string _symbol);
	void SetPriority();
	void AutoSet(std::string _symbol);
private:
	std::string symbol;
	int priority;

};


