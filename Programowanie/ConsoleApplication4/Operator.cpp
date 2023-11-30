#include "Operator.h"

void Operator::AutoSet(char c)
{
	symbol = c;
	SetPriority();
}
char Operator::GetSymbol()
{
	return symbol;
}

int Operator::GetPriority()
{
	return priority;
}

void Operator::SetSymbol(char c)
{
	symbol = c;
}

void Operator::SetPriority()
{
	if (GetSymbol() == '(')
		priority = 0;
	else if (GetSymbol() == '+' || GetSymbol() == '-' || GetSymbol() == ')')
		priority = 1;
	else if (GetSymbol() == '*' || GetSymbol() == '/' || GetSymbol() == '%')
		priority = 2;
	else if (GetSymbol() == '^')
		priority = 3;
}