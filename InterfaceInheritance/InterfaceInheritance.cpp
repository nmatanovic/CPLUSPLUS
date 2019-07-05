// InterfaceInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//
// Interface is kind of contract, if some class implements interface
// we know that object of that class are able to perform actions defined by that interface
//
// Implement empty virtual destructor, so destructor in derived class can be called
//                                                       |
//                                        IFigura *p = new Figura(); delete p;
//
class IFigura
{
public:
	virtual void Kretanje() = 0;

	virtual ~IFigura()
	{
	}
};

class Figura : public IFigura
{
public:

	Figura()
	{
	}

	virtual void Kretanje()
	{
		std::cout << "Kreatanje" << std::endl;
	}
};


void Test()
{
	IFigura *p = new Figura();

	p->Kretanje();


	delete p;
}


void PressKey()
{
	int a;
	std::cin >> a;
}

int main()
{

	Test();
	PressKey();

    return 0;
}

