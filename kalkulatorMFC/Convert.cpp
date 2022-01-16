#include "Convert.h"


//**** Funkcje przekszta³cania typów danych ******//

// **BINARY**

long long Converting::bintodec(long long a) {
	long long licz = 0, i = 0, temp{};

	while (a != 0) {
		temp = a % 10;
		a /= 10;
		licz += temp * pow(2, i);
		++i;
	}

	return licz;
}
long long Converting::dectobin(long long b) {
	long long conv = 0;
	long long temp, i = 1;

	while (b != 0) {
		temp = b % 2;
		b /= 2;
		conv += temp * i;
		i *= 10;
	}

	return conv;
}


// **OCTAL**

long long Converting::octtodec(long long c)
{
	long long decimal = 0, i = 0, temp{};
	while (c != 0)
	{
		temp = c % 10;
		c /= 10;
		decimal += temp * pow(8, i);
		++i;
	}
	return decimal;
}

long long Converting::dectooct(long long d)
{
	long long temp, i = 1, octal = 0;
	while (d != 0)
	{
		temp = d % 8;
		d /= 8;
		octal += temp * i;
		i *= 10;
	}
	return octal;
}


// **HEXADECIMAL**

long long Converting::hextodec(std::string hex)
{
	long long x{};
	x = stoul(hex, nullptr, 16);
	return x;
}


CString Converting::dectohex(long long numero) {
	std::stringstream stream;
	stream << std::hex << numero;
	std::string result(stream.str());
	CString result2(result.c_str());
	return result2;
}


// *** CString to string ****

std::string Converting::C_to_S(CString CStemp) {
	CT2CA posrednia(CStemp);
	std::string rom(posrednia);
	return rom;
}