// InheritanceAbstractClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//
// Any class with pure virtual method is abstract class
// such class can not be instanced
//
class Figura
{
public:

	Figura()
	{
	}

	virtual double Area() = 0;

	virtual ~Figura()
	{
	}

};

//
//
//
class Figura2D : public Figura
{
protected:
	int m_x;
	int m_y;

public:
	Figura2D() : Figura()
	{
	}

	virtual void SetX(int x)
	{
		m_x = x;
	}

	virtual void SetY(int y)
	{
		m_y = y;
	}
};

//
//
//
//
class Circle : public Figura2D
{

public:

	Circle() : Figura2D()
	{
	}


	// implement this if we have pointers, file handles...
	// if DEEP-COPY is needed
	Circle(const Circle &lpFrom)
	{
		this->m_x = lpFrom.m_x;
		this->m_y = lpFrom.m_y;
	}

	// copy-swap idiom
	Circle& operator=(const Circle &from)
	{
		Circle newCopy(from);

		Swap(this, &newCopy);

		return *this;
	}

	void Swap(Circle *lpInto, Circle* lpFrom)
	{
		//int t;

	/*	t = lpInto->m_x;
		lpInto->m_x = lpFrom->m_x;
		lpFrom->m_x = t;

		t = lpInto->m_y;
		lpInto->m_y = lpFrom->m_y;
		lpFrom->m_y = t;*/

		Swap<int>(lpInto->m_x, lpFrom->m_x);
		Swap<int>(lpInto->m_y, lpFrom->m_y);
	}
	

	template<typename T>
	void Swap(T &Into, T &From)
	{
		T tmp;

		tmp = Into;

		Into = From;
		From = tmp;
	}

	virtual double Area()
	{
		return m_x * m_y;
	}
};

void Test()
{
	Circle c;
	Circle c2;

	c.SetX(11);
	c.SetY(10);

	c2 = c;
	
	Figura2D *fC = new Circle();

	fC->SetX(10);
	fC->SetY(15);

	//
	Figura *f = &c;

	std::cout << f->Area() << std::endl;
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

