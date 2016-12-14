#pragma once

#include <string>

class Fraction
{
public:
	//�������====================
	static unsigned int createdFractionCount; //���������� ��������� ��������. ���������������� � �������������, ���������������� � �����������
	static int gcd(int n1, int n2); //���������� ������ ��������
	static void PrintAsFraction(double dec_fraction); //���������� => ������������
	static void PrintAsFraction(char* dec_fraction); //����������(������) => ������������
	//�������====================
	Fraction(int Numerator, int Denominator); //��������� ����� � ������� � ������������ ����
	explicit Fraction(double Number); //��������� ������������. ����� �������� ����� ���������� Convert
	static std::string formatAsText(int numerator, int denominator, bool print); //print == true - ������� �� ������� � ����������, print == false - ������ ����������
	std::string formatAsText(bool print); //�� ��, ��� � ����, �� ���������� ���������� �� ������ �������, � �� �� ����������
	Fraction operator+(Fraction& f);
	Fraction operator-(Fraction& f);
	Fraction operator*(Fraction& f);
	Fraction operator/(Fraction& f);
	void Reduce(); //���������� �����
	int getNumerator();
	int getDenominator();
	~Fraction(void);
private:
	int Numerator;	//���������
	int Denominator;	//�����������
	static void Convert(double fract, int &nom, int &denom); //��������� ������
};

