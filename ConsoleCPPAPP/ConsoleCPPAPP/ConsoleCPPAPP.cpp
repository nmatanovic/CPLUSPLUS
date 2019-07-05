// ConsoleCPPAPP.cpp : Defines the entry point for the console application.
//
//
//

#include "stdafx.h"


void PressKey();
void DuzineTipova();
void StorageClass();

int main()
{
	DuzineTipova();
	PressKey();

    return 0;
}


//
//
//
void DuzineTipova()
{
	std::cout << "Stampam text" << std::endl;

	std::cout << sizeof(int) << " - Duzna int" << std::endl;
	std::cout << sizeof(unsigned int) << " - Duzina unsigned int" << std::endl;

	std::cout << sizeof(char) << " - Duzina char" << std::endl;
	std::cout << sizeof(wchar_t) << " - Duzina wchar_t" << std::endl;
}

//
// auto, register, static
// extern - globalna variabla ili funkcija u drugom fajlu
// static - lokalna varibla ciji life-time je kroz ceo program (ovo je podrzano globalnom variablom)
//          ako je na data memberu u klasi onda je postoji jedna kopija takvog data member za sve instance
void StorageClass()
{
	int broj = 5; // auto int broj = 5 (auto) za lokalne variable je default
	register int delilac = 3; // ovo ide u registar

}
void PressKey()
{
	int a;
	std::cin >> a;
}

