#include <iostream>
void task1()
{
	float numbers[5];
	for (int i = 0; i < 5; i++)
	{
		std::cout << "podaj " << i+1 << " liczbe \n ";
		std::cin >> numbers[i];
	}

	for (float number : numbers)
	{
		std::cout << number << "\n";
	}

}

int main()
{
	task1();
}