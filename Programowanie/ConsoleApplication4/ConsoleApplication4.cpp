#include <iostream>

void task1()
{
	char charFromUser;
	std::cout << "Podaj znak \n";
	std::cin >> charFromUser;
	std::cout << "Twój znak to: " << charFromUser;
	if (charFromUser >= 'a' && charFromUser <= 'z')
		std::cout << "ma³a litera";
	else
		std::cout << "NIE ma³a litera";
	charFromUser += 2;
	std::cout << charFromUser;
	
	charFromUser = 'a' + 2;
	std::cout << charFromUser;

}

void task2()
{
	std::string nameFromUser;
	std::cout << "jak masz na imie?\n";
	std::cin >> nameFromUser;
	std::cout << "Witaj" << nameFromUser;
}
int main()
{

	task2();

}