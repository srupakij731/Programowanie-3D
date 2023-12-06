#include "Operator.h"
#include <string>

void Operator::AutoSet(std::string newSymbol)
{
	symbol = newSymbol;
	SetPriority();
}
std::string Operator::GetSymbol()
{
	return symbol;
}

int Operator::GetPriority()
{
	return priority;
}

void Operator::SetSymbol(std::string newSymbol)
{
	symbol = newSymbol;
}

void Operator::SetPriority()
{
	if (GetSymbol() == "(")
		priority = 0;
	else if (GetSymbol() == "+" || GetSymbol() == "-" || GetSymbol() == ")")
		priority = 1;
	else if (GetSymbol() == "*" || GetSymbol() == "/" || GetSymbol() == "%")
		priority = 2;
	else if (GetSymbol() == "^")
		priority = 3;
}

