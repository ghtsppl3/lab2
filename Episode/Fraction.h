#pragma once

#include <string>

class Fraction
{
public:
	//Статика====================
	static unsigned int createdFractionCount; //Количество созданных объектов. Инкрементируется в конструкторах, декрементируется в деструкторе
	static int gcd(int n1, int n2); //Нахождение общего делителя
	static void PrintAsFraction(double dec_fraction); //Десятичная => Обыкновенная
	static void PrintAsFraction(char* dec_fraction); //Десятичная(строка) => Обыкновенная
	//Статика====================
	Fraction(int Numerator, int Denominator); //Принимает дробь в готовом к употреблению виде
	explicit Fraction(double Number); //Принимает вещественное. Будет работать после реализации Convert
	static std::string formatAsText(int numerator, int denominator, bool print); //print == true - выводит на консоль и возвращает, print == false - только возвращает
	std::string formatAsText(bool print); //То же, что и выше, но использует переменные из самого объекта, а не из параметров
	Fraction operator+(Fraction& f);
	Fraction operator-(Fraction& f);
	Fraction operator*(Fraction& f);
	Fraction operator/(Fraction& f);
	void Reduce(); //Сокращение дроби
	int getNumerator();
	int getDenominator();
	~Fraction(void);
private:
	int Numerator;	//Числитель
	int Denominator;	//Знаменатель
	static void Convert(double fract, int &nom, int &denom); //Конвертор дробей
};

