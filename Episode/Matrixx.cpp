#include "StdAfx.h"
#include "Matrixx.h"


Matrixx::Matrixx(unsigned int size_i, unsigned int size_j)
{
	Matrixx::marray = new double*[size_i];
	for (unsigned int i = 0; i < size_i; i++)
		Matrixx::marray[i] = new double[size_j];
	for (unsigned int i = 0; i < size_i; i++)
	{
		for (unsigned int j = 0; j < size_j; j++)
		{
			Matrixx::marray[i][j] = 0; //Занулить массив во имя Страуструпа
		}
	}
	Matrixx::s_i = size_i; //Сохранение размеров массива
	Matrixx::s_j = size_j;
}

Matrixx::Matrixx(const Matrixx & m)
{
	marray = new double*[m.s_i];
	for (unsigned int i = 0; i < m.s_i; i++)
		marray[i] = new double[m.s_j];
	for (unsigned int i = 0; i < m.s_i; i++)
	{
		for (unsigned int j = 0; j < m.s_j; j++)
		{
			marray[i][j] = m.marray[i][j]; //Знаю, тупо, говнокод, но порождение иных костылей приводит к вылетам программы и разрыву дипотношений с деструктором
		}
	}
	s_i = m.s_i; s_j = m.s_j;
}

Matrixx & Matrixx::operator++() //Перегруз префиксного инкремента
{
	for (unsigned int i = 0; i < Matrixx::s_i; i++)
	{
		for (unsigned int j = 0; j < Matrixx::s_j; j++)
		{
			++Matrixx::marray[i][j];
		}
	}
	return *this;
}

Matrixx Matrixx::operator++(int) //Перегруз постфиксного инкремента
{
	Matrixx temp(*this);
	for (unsigned int i = 0; i < Matrixx::s_i; i++)
	{
		for (unsigned int j = 0; j < Matrixx::s_j; j++)
		{
			Matrixx::marray[i][j]++;
		}
	}
	return temp;
}

double Matrixx::At(unsigned int i, unsigned int j) const //Если индекс больше размеров массива, либо отрицательный, возвращает -1. Эксепшн? Какой эксепшн?
{
	if ((i > Matrixx::s_i) || (j > Matrixx::s_j) || (i < 0) || (j < 0))
		return -1;
	return Matrixx::marray[i][j];
}

void Matrixx::setAt(unsigned int i, unsigned int j, double Value) //Если индекс больше размеров массива, либо отрицательный, просто не сработает. Happy debug
{
	if ((i > Matrixx::s_i) || (j > Matrixx::s_j) || (i < 0) || (j < 0))
		return;
	Matrixx::marray[i][j] = Value;
}

unsigned int Matrixx::GetISize()
{
	return Matrixx::s_i;
}

unsigned int Matrixx::GetJSize()
{
	return Matrixx::s_j;
}

void Matrixx::InitializeArr()
{
	for (unsigned int i = 0; i < Matrixx::s_i; i++)
	{
		for (unsigned int j = 0; j < Matrixx::s_j; j++)
		{
			Matrixx::marray[i][j] = factorial(i) + factorial(j); //x! + y!
		}
	}
}

Matrixx::~Matrixx()
{
	for (unsigned int i = 0; i < Matrixx::s_i; i++)
		delete[]Matrixx::marray[i];
	delete[]Matrixx::marray;
}

double Matrixx::factorial(double number)
{
	int result = 1; // Как будто Delphi в душу заглянул
	if (number == 1) { return result; }
	else
	{
		for (unsigned int i = 1; i <= number; i++)
			result *= i;
	}
	return result;
}
