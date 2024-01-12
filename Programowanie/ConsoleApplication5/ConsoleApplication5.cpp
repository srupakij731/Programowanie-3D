#include <iostream>
void task1()
{
	float numbers[5];
	for (int i = 0; i < 5; i++)
	{
		std::cout << "podaj " << i + 1 << " liczbe \n ";
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

void task3()
{
	const int UPPER_RANGE = 10;
	const int LOWER_RANGE = 1;

	const int SIZE_OF_ARRAY = 2;
	int numbers[SIZE_OF_ARRAY];

	srand(time(NULL));

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		std::cout << numbers[i] << ", ";

	std::cout << "\n";

	double sum = 0;

	for (int num : numbers)
		sum += num;

	std::cout << "œrednia to " << sum * 1.0 / SIZE_OF_ARRAY;
}

void task5()
{
	const int UPPER_RANGE = 3;
	const int LOWER_RANGE = 1;

	const int SIZE_OF_ARRAY = 10;
	int numbers[SIZE_OF_ARRAY];

	srand(time(NULL));

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		std::cout << numbers[i] << ", ";

	std::cout << "\n";

	for (int numberFromRange = LOWER_RANGE; numberFromRange <= UPPER_RANGE; numberFromRange++)
	{
		int count = 0;

		for (int num : numbers)
		{
			if (num == numberFromRange)
				count++;
		}
		std::cout << numberFromRange << " = " << count << "\n";
	}
	//wersja 2
	int number0fOccurences[UPPER_RANGE - LOWER_RANGE + 1];

	for (int i = 0; i < UPPER_RANGE - LOWER_RANGE + 1; i++)
	{
		number0fOccurences[i] = 0;
	}

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		number0fOccurences[numbers[i] - LOWER_RANGE + 1];
	}

	for (int i = 0; UPPER_RANGE - LOWER_RANGE + 1; i++)
	{
		std::cout << i + LOWER_RANGE << " = " << number0fOccurences[i];
	}
}

void task6()
{
	const int UPPER_RANGE = 50;

	//1

	//for (int i = 2; i <= UPPER_RANGE; i++)
	//{
	//	bool isPrime = true;
	//	for (int j = 2; j < sqrt(i); j++)
	//	{
	//		if (i % j == 0)
	//		{

	//			isPrime = false;
	//			break;
	//		}
	//	}
	//	if (isPrime)
	//		std::cout << i << "\n";
	//}

	//std::cout <<"\n";


	//2
	bool primeNumbers[UPPER_RANGE + 1];

	for (int i = 2; i < UPPER_RANGE + 1; i++)
	{
		primeNumbers[i] = true;
	}

	for (int i = 2; i < UPPER_RANGE + 1; i++)
	{
		if (primeNumbers[i])
		{
			for (int j = i + i; j < UPPER_RANGE + 1; j += i)
			{
				primeNumbers[i] = false;
			}
		}
	}

	for (int i = 2; i < UPPER_RANGE + 1; i++)
	{
		if (primeNumbers[i])
		{
			std::cout << i << "\n";
		}
	}
}

int main()
{
	task6();
}