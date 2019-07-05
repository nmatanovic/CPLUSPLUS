#include "stdafx.h"
#include "NString.h"


NString::NString()
{
	m_Size = 10;
	m_Buffer = new char[m_Size];
}

NString::~NString()
{

}


void NString::Print()
{
	std::cout << m_Buffer;
}

void NString::SetBuffer(char *lpStr)
{
	size_t s = 0;
	size_t _do = 0;

	char *tmp = (lpStr + s);

	while (tmp != '\0')
	{
		//lpStr++;
		tmp = (lpStr + s);
		s++;
	}

	// uzmi veci od ova dva
	_do = m_Size;

	if (_do < s)
		_do = s;


	for (int i = 0; i < _do; i++)
	{
		m_Buffer[i] = lpStr[i];
	}

}

