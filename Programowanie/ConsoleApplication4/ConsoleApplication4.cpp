#include <iostream>
#include <vector>
#include "Operator.h"
#include <string>

/*
*
* Program wyci¹gaj¹cy informacje z numeru PESEL
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

	for (char c : textFromUser)
	{
		if (isalpha(c))
		{
			if (c == 'a' || c == 'A' || c == 'e' || c == 'E'
				|| c == 'i' || c == 'I' || c == 'u'
				|| c == 'U' || c == 'y' || c == 'Y')
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
void task5()
{
	int text1CharSum = 0, text2CharSum = 0;
	std::string textFromUser1, textFromUser2;
	std::cout << "podaj text 1: ";
	std::cin >> textFromUser1;
	std::cout << "podaj text 2: ";
	std::cin >> textFromUser2;

	for (char c : textFromUser1)
		text1CharSum += c;
	for (char c : textFromUser2)
		text2CharSum += c;
	if (text1CharSum == text2CharSum)
		std::cout << "to sa anagramy";
	else
		std::cout << "to NIE sa anagramy";

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

	for (char c : textFromUser)
	{
		if (isalpha(c))
		{
			for (int i = 0; i < letterIncrise; i++)
			{
				c++;
				if (c == '[')
					c = 'A';
				else if (c == '{')
					c = 'a';
			}
		}
		std::cout << c;
	}
}

bool isConstOrVariable(char c)
{
	if (c > 'a' && c < 'z' || c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '^' || c == '(' || c == ')')
		return 1;
	else
		return 0;
}

//*Program który na wejœciu przyjmie równanie a na 
// wyjœciu da równanie w odwrotnej notacji polskiej ONP.Np.na wejœciu 2 + 3 * 4 na wyjœcu da 234 * +
void task8()
{
	std::string equationRegular;
	std::vector<char> equationONP;
	std::vector<Operator> stack;
	std::cout << "Podaj rownanie: \n";
	std::cin >> equationRegular;

	for (int i = 0; i < equationRegular.length(); i++)
	{
		if (isConstOrVariable(equationRegular[i]))
			equationONP.push_back(equationRegular[i]);
		else if (isOperator(equationRegular[i]))
		{
			Operator op;
			op.AutoSet(equationRegular[i]);
			while (!stack.empty() && op.GetPriority() <= stack.back().GetPriority())
			{
				equationONP.push_back(stack.back().GetSymbol());
				stack.pop_back();
			}

			// DODAJ NAWIASY BO NAWIASY POTRZEBNE
			stack.push_back(op);
		}
		else
			std::cerr << "bruh";
	}
	if (!stack.empty())
	{
		for (int i = 0; i < stack.size(); i++)
		{
			equationONP.push_back(stack.at(i).GetSymbol());
		}
	}

	for (char c : equationONP)
	{
		std::cout << c;
	}

}

int main()
{

	task8();

}