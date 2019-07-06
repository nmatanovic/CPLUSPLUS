#ifndef _H_FIGURA
#define _H_FIGURA

class IFigura
{
public:

	IFigura();
	virtual double Area() = 0;
	virtual ~IFigura();

};

#endif