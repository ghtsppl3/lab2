#include "StdAfx.h"
#include "Fraction.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

Fraction::Fraction(int Numerator, int Denominator)
{
	Fraction::Numerator = Numerator;
	Fraction::Denominator = Denominator;
	Fraction::createdFractionCount++;
}

Fraction::Fraction(double Number)
{
	int numerator;
	int denominator;
	Fraction::Convert(Number, numerator, denominator);
	Fraction::Numerator = numerator;
	Fraction::Denominator = denominator;
	Fraction::createdFractionCount++;
}

Fraction Fraction::operator+(Fraction& f)
{
	if (this->Denominator != f.Denominator)
		return Fraction::Fraction(this->Numerator*f.Denominator+f.Numerator*this->Denominator, this->Denominator*f.Denominator);
	else
		return Fraction::Fraction(this->Numerator+f.Numerator, this->Denominator);
}

Fraction Fraction::operator-(Fraction& f)
{
	if (this->Denominator != f.Denominator)
		return Fraction::Fraction(this->Numerator*f.Denominator-f.Numerator*this->Denominator, this->Denominator*f.Denominator);
	else
		return Fraction::Fraction(this->Numerator-f.Numerator, this->Denominator);
}

Fraction Fraction::operator*(Fraction& f)
{
	return Fraction::Fraction(this->Numerator*f.Numerator, this->Denominator*f.Denominator);
}

Fraction Fraction::operator/(Fraction& f)
{
	return Fraction::Fraction(this->Numerator*f.Denominator, this->Denominator*f.Numerator);
}

void Fraction::Reduce()
{
	int NOD = Fraction::gcd(Fraction::Numerator, Fraction::Denominator);
	Fraction::Numerator /= NOD; Fraction::Denominator /= NOD;
}

int Fraction::gcd(int n1, int n2)
{
	while(n2)
	{
		int temporaryint = n2;
		n2 = n1 % n2;
		n1 = temporaryint;
	}
	return n1;
}

void Fraction::PrintAsFraction(double dec_fraction)
{
	int numerator;
	int denominator;
	Fraction::Convert(dec_fraction, numerator, denominator);
	Fraction::formatAsText(numerator, denominator, true);
}

void Fraction::PrintAsFraction(char* dec_fraction)
{
	Fraction::PrintAsFraction(std::stod(dec_fraction));
}

std::string Fraction::formatAsText(int numerator, int denominator, bool print) //Функция выводит дробь в красивом виде
{
	unsigned int linelength;
	std::string sNumerator = std::to_string((_Longlong)numerator); //ЭТО ЖЕ П..П...Превосходно
	std::string sDenomimator = std::to_string((_Longlong)denominator);
	std::string line;
	std::string res;
	if(sNumerator.length() > sDenomimator.length())
		linelength = sNumerator.length();
	else
		linelength = sDenomimator.length();
	for(unsigned int i=0; i < linelength; i++)
		line += "-";
	res = sNumerator + "\n" + line + "\n" + sDenomimator;
	if(print)
		std::cout << res << std::endl;
	return res;
}

std::string Fraction::formatAsText(bool print)
{
	return Fraction::formatAsText(Fraction::Numerator, Fraction::Denominator, print); //Так лучше ИМХО
}

int Fraction::getNumerator()
{
	return Fraction::Numerator;
}

int Fraction::getDenominator()
{
	return Fraction::Denominator;
}

void Fraction::Convert(double fract, int &nom, int &denom)
{
	/*const*/ unsigned int Dividor = 10;
	const unsigned int div_const = Dividor;

	while((int)fract != fract)
	{
		Dividor *= div_const; fract *= Dividor; //Вроде как то так
	}
	int NOD = Fraction::gcd(fract, Dividor);
	fract /= NOD; Dividor /= NOD;
	nom = fract; denom = Dividor;
}

Fraction::~Fraction(void)
{
	Fraction::createdFractionCount--;
}

unsigned int Fraction::createdFractionCount = 0;