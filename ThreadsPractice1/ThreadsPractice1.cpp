// ThreadsPractice1.cpp : Defines the entry point for the console application.
//

//
// Threads using std::thrad C++ 14
//




#include "stdafx.h"


void calculator(const std::vector<int> &vec, int &acm)
{
	int s = 0;

	for (size_t i = 0; i < vec.size(); i++)
	{
		s += vec[i];
	}

	acm = s;
}

int main()
{
	int r1, r2;

	std::vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	std::thread first(calculator, std::ref(numbers), std::ref(r1));
	std::thread second(calculator, std::ref(numbers), std::ref(r2));

	// sinchronize
	first.join();					// wait till thread finsh
	second.join();					// wait till thread finsh

	std::cout << r1;

	return 0;
}

