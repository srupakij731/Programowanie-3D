#include <iostream>
#include <vector>
#include "Operator.h"
#include <string>
#include <sstream>
#include <stack>


/*
*
* Program, który na wejœciu przyjmie rówanie w ONP a na wyjœciu wyœwietli wynik rówania.
*/

//*Napisz program, który bêdzie prosi³ o has³o.Nie przepuœci dalej dopóki nie zostanie ono podane prawid³owo.
void task1()
{
	std::string password = "abc123", passwordFromUser;
	do
	{
		std::cout << "podaj haslo \n";
		std::cin >> passwordFromUser;
	} while (password != passwordFromUser);
}

//*Napisz program, który pobiera od u¿ytkownika ci¹g znaków i wyœwietla liczbê samog³osek i spó³g³osek w tym ci¹gu.

void task2()
{
	int vovelCount = 0, consonantCount = 0;
	std::string textFromUser;
	std::cout << "podaj text";
	std::cin >> textFromUser;

	for (char partOfEquationRegular : textFromUser)
	{
		if (isalpha(partOfEquationRegular))
		{
			if (partOfEquationRegular == 'a' || partOfEquationRegular == 'A' || partOfEquationRegular == 'e' || partOfEquationRegular == 'E'
				|| partOfEquationRegular == 'i' || partOfEquationRegular == 'I' || partOfEquationRegular == 'u'
				|| partOfEquationRegular == 'U' || partOfEquationRegular == 'y' || partOfEquationRegular == 'Y')
				vovelCount++;
			else
				consonantCount++;
		}
	}
	std::cout << "samogloski: " << vovelCount << "\nspolgloski: " << consonantCount;
}

//*Poproœ u¿ytkownika o wprowadzenie liczby ca³kowitej w systemie dziesiêtnym.
// Nastêpnie skonwertuj tê liczbê na system dwójkowy(binarny) i wyœwietl wynik.
void task3()
{
	int number;
	std::string binaryNumber = "";
	std::cout << "podaj liczbe: \n";
	std::cin >> number;
	do
	{
		binaryNumber = std::to_string(number % 2) + binaryNumber;
		number /= 2;
	} while (number != 0);
	std::cout << binaryNumber;
}

//*Program sprawdzaj¹cy czy podany ci¹g znaków jest palindromem
// (czyli takim, który czytany od ty³u jest taki sam, jak czytany od przodu, np. "kajak")
void task4()
{
	std::string textFromUser, textPalindrome = "";
	std::cout << "podaj text: ";
	std::cin >> textFromUser;
	for (int i = textFromUser.length() - 1; i >= 0; i--)
	{
		textPalindrome += textFromUser[i];
	}
	if (textFromUser == textPalindrome)
		std::cout << textFromUser << " to jest palindrom";
	else
		std::cout << textFromUser << " to NIE jest palindrom";
}

//*Program sprawdzaj¹cy czy podane dwa s³owa s¹ anagramami
//(czyli takimi, które zawieraj¹ te same litery, ale w innym uk³adzie, np. "klasa" i "salka")


//*Program wyci¹gaj¹cy informacje z numeru PESEL
void task6()
{
	std::string pesel;
	std::cout << "podaj pesel \n";
	std::cin >> pesel;


}
//*Program implementuj¹cy algorytm szyfrowania Cezara
// (proste szyfrowanie, w którym ka¿dy znak w tekœcie jest zastêpowany innym znakiem, przesuniêtym o sta³¹ liczbê pozycji w alfabecie).
void task7()
{
	std::string textFromUser;
	int letterIncrise;

	std::cout << "podaj text\n";
	std::cin >> textFromUser;
	std::cout << "podaj o ile ma siê zwiêkrzaæ text \n";
	std::cin >> letterIncrise;

	if (letterIncrise > 'z')
		letterIncrise %= 26;

	for (char partOfEquationRegular : textFromUser)
	{
		if (isalpha(partOfEquationRegular))
		{
			for (int i = 0; i < letterIncrise; i++)
			{
				partOfEquationRegular++;
				if (partOfEquationRegular == '[')
					partOfEquationRegular = 'A';
				else if (partOfEquationRegular == '{')
					partOfEquationRegular = 'a';
			}
		}
		std::cout << partOfEquationRegular;
	}
}

bool isOperator(std::string partOfEquationRegular)
{
	if (partOfEquationRegular == "+" || partOfEquationRegular == "-" || partOfEquationRegular == "/" || partOfEquationRegular == "*" || partOfEquationRegular == "%" || partOfEquationRegular == "^")
		return 1;
	else
		return 0;
}

//*Program który na wejœciu przyjmie równanie a na 
// wyjœciu da równanie w odwrotnej notacji polskiej ONP.Np.na wejœciu 2 + 3 * 4 na wyjœcu da 234 * +
void task8()
{
	std::string equationRegular;
	std::stack<std::string> reversedEquationONP;
	std::stack<Operator> stack;
	std::cout << "Podaj rownanie: \n";
	std::getline(std::cin, equationRegular);

	std::istringstream iss(equationRegular);

	std::string partOfEquationRegular;

	while (iss >> partOfEquationRegular)
	{
		if (isOperator(partOfEquationRegular))
		{
			Operator op;
			op.AutoSet(partOfEquationRegular);
			while (!stack.empty() && op.GetPriority() <= stack.top().GetPriority())
			{
				reversedEquationONP.push(stack.top().GetSymbol());
				stack.pop();
				// DODAJ NAWIASY BO NAWIASY POTRZEBNE
			}
			stack.push(op);
		}
		else
			reversedEquationONP.push(partOfEquationRegular);
	}
	while (!stack.empty())
	{
		reversedEquationONP.push(stack.top().GetSymbol());
		stack.pop();
	}

	std::stack<std::string>regularEquationONP;


	//XDDDDDDDDDDDDDDDDD
	while (!reversedEquationONP.empty())
	{
		regularEquationONP.push(reversedEquationONP.top());
		reversedEquationONP.pop();
	}


	while (!regularEquationONP.empty())
	{
		std::cout << regularEquationONP.top() << " ";
		regularEquationONP.pop();
	}
}

int main()
{

	task8();

}