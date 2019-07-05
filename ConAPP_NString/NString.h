#ifndef _H_NString
#define _H_NString

#include <iostream>


class NString
{
	private:
		char *m_Buffer;
		size_t m_Size;
	
	public:
		NString();  // definicja konstruktora
		NString(char *lpStr);

		~NString(); // definicija destruktora



		virtual void Print();
		virtual void SetBuffer(char *lpStr);


};


#endif