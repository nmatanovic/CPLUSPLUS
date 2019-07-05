// LinePoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class Point
{
	private:
		int m_x;
		int m_y;

	public:
		//
		// Konstruktor
		// Sluzi za inicijalizaciju member varijabli i da bi pozvao bazni kostruktor ako nasledjuje, 
		// POZIVA se kada se kaze new i kada objekat ide na stack (ako nema parametre poziva se bez zagrada)
		//
		Point()
		{
			m_x = 0;
			m_y = 0;
		}

		// overloaded constructor, constructor/function/method with same name with different number of parameters
		Point(int x, int y)
		{
			m_x = x;
			m_y = y;
		}
		
		//
		// copy-constructor, compiler defines default one (default one performs shallow-copy)
		// copy-constructor is needed when object has pointers or file handle or network connection or when deep-copy is needed
		// 
		// Point p1 = p2 < - copy-constructor is called when object is created from an existing object
		//
		// if class has user defined copy-constructor class should implement assigment operator
		Point(const Point &otherPoint /* pass by REFERENCE, not whole obejct on the stack */)
		{
			m_x = otherPoint.m_x;
			m_y = otherPoint.m_y;


			// pass by reference, if changed here (this method is callee) changes reflets in caller
			// but parameter is marked as const because of that otherPoint.m_x = 3 does not get compiled
		}


		//
		// Destructor
		// virtual destructor makes sure that destructor in derived class is called
		// destructor is called when object goes out of scope or when pointer that points to an object get deleted
		//
		virtual ~Point()
		{
			std::cout << "Destructing point" << std::endl;
		}



		//
		// Assigment operator
		// Assigment operators are used for Value Types, Virtual functions are for polimorphic hierarchies
		//
		// Parameter otherPoint is passed by REFERENCE
		//           otherPoint.m_x = 5 will reflect with change in caller (this method ex. assigment operator is callee)
		//           we dont want to make mistake hereof const                                                                             
		//
		//
		Point& operator = (const Point &otherPoint)
		{
			Point newPoint(otherPoint);                                         
			swap(this, &newPoint);
			std::cout << "Operator = called" << std::endl;

										                  // destructor for newPoint will be executed :-)
			return *this;
		}


		void swap(Point* lpInto, Point *lpFrom)
		{
			int tmp;
			
			tmp = lpInto->m_x;
			lpInto->m_x = lpFrom->m_x;
			lpFrom->m_x = tmp;


			tmp = lpInto->m_y;
			lpInto->m_y = lpFrom->m_y;
			lpFrom->m_y = tmp;
		}


	public:
		virtual std::string ToString()
		{
			std::stringstream sRez;
			std::string strRet;

			sRez << "X Cordinate: " << m_x << ", Y Cordinate:" << m_y;
			
			//sRez >> strRet;
			getline(sRez, strRet);
			return strRet;
		}
};

class Line
{

private:
	Point *lpArrayOfPoints; // pointer
	const int m_Size = 10;  // Initial Size

public:
	Line()
	{
		lpArrayOfPoints = new Point[m_Size];
	}
	
	// copy-constructor
	// DEEP-COPY
	Line(const Line &otherLine)
	{
		// initialize pointer
		this->lpArrayOfPoints = new Point[otherLine.m_Size];

		// copy actual data not only pointer
		for (auto i = 0; i < otherLine.m_Size; i++)
		{
			this->lpArrayOfPoints[i] = otherLine.lpArrayOfPoints[i];
		}
		

	}
		
	// Assignment operator implements copy-swap idiom
	Line& operator = (const Line& otherLine)
	{
		Line newLine(otherLine);
		
		//swap new line with old line
		Swap(this, &newLine);

		return *this;
	}

	void Swap(Line *lpLeft, Line *lpRight)
	{
		Point *tmp;
		
		tmp = lpLeft->lpArrayOfPoints;

		lpLeft->lpArrayOfPoints = lpRight->lpArrayOfPoints;
		
		lpRight->lpArrayOfPoints = tmp;
		
		//lpLeft->m_Size = lpRight->m_Size;
	}

	virtual ~Line()
	{
		if (nullptr != lpArrayOfPoints)
		{
			delete[] lpArrayOfPoints;
		}

		std::cout << "Line destructor" << std::endl;
	}
};


void PressKey()
{
	int a;

	std::cin >> a;
}


void Test()
{
	Line l1;
	Line l2;
	
	
	Point p1;
	Point p2;

	p1 = p2;

	l1 = l2;


	std::cout << p1.ToString() << std::endl;
	std::cout << p2.ToString() << std::endl;
}

int main()
{
	Test();

	PressKey();

    return 0;
}

