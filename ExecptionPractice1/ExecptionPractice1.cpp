// ExecptionPractice1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class MyException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
} myex;


void TestCustomException()
{

	try
	{
		throw MyException();
	}
	catch (MyException& ex)
	{
		std::cout << "MyException ";
	}

}



void Test()
{
	try
	{
		throw 1;
	}
	catch (...)
	{
		std::cout << "Exception" << std::endl;
	}
}


void TestIntException()
{
	try
	{
		throw 20;
	}
	catch (int e)
	{
		std::cout << "Exception: " << e << std::endl;
	}
}

int main()
{
	TestCustomException();
	Test();
	TestIntException();


    return 0;
}

