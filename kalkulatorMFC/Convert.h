#pragma once
#include<string>
#include <string.h>
#include <sstream>
#include "pch.h"

class Converting {
public:
	long long bintodec(long long n);
	long long dectobin(long long n);
	long long octtodec(long long octalNumber);
	long long dectooct(long long decimalNumber);
	long long hextodec(std::string hex);
	CString dectohex(long long numero);
	std::string C_to_S(CString CStemp);
};
