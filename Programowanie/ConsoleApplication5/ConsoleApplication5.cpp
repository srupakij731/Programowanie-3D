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

void task2()
{
	const int UPPER_RANGE = 100;
	const int LOWER_RANGE = 5;

	const int SIZE_OF_ARRAY = 5;
	int numbers[SIZE_OF_ARRAY];

	srand(time(NULL));

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
	}

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		std::cout << numbers[i] << ", ";
	std::cout << "\n";

	int max = numbers[0], min = numbers[0];
	for (int i = 1; i < SIZE_OF_ARRAY; i++)
		if (numbers[i] > max)
			max = numbers[i];

	for (int i = 1; i < SIZE_OF_ARRAY; i++)
		if (numbers[i] > min)
			min = numbers[i];
}

int main()
{
	task2();
}