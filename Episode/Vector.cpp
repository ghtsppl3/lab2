#include "StdAfx.h"
#include "Vector.h"
#include "Matrixx.h"


Vector::Vector(unsigned int VectorLength)
{
	Vector::varray = new double[VectorLength]; //Создание в хипе одномерного массива с длинною VectorLength
	for (unsigned int i = 0; i < VectorLength; i++)
		Vector::varray[i] = 0; //Зачистка памяти массива
	Vector::VL = VectorLength; //Сохранение длины массива на будещее
}

Vector::Vector(const Vector & v)
{
	varray = new double[v.VL];
	memcpy(varray, v.varray, v.VL*sizeof(double)); //На этом месте должны были быть костыли
	VL = v.VL; //Сохранение длины массива на будещее
}

double & Vector::operator[](unsigned int index)
{
	return Vector::varray[index];
}

Vector & Vector::operator++() //Перегруз префиксного инкремента
{
	for (unsigned int i = 0; i < Vector::VL; i++)
		++Vector::varray[i];
	return *this;
}

Vector Vector::operator++(int) //Перегруз постфиксного инкремента
{
	Vector temp(*this);
	for (unsigned int i = 0; i < Vector::VL; i++)
		Vector::varray[i]++;
	return temp;
}

unsigned int Vector::GetSize()
{
	return Vector::VL;
}

void Vector::ConvertArray(Matrixx m) //Конвертация 2D -> 1D согласно условию лабораторной работы №1
{
	unsigned int uindex = 0; //Для работы с результатирующим массивом
	for (int i = 0; i < m.GetISize(); i++)
	{
		for (int j = 0; j < m.GetJSize(); j++)
		{
			if ((i % 2) == 0) { continue; }
			Vector::varray[uindex] = m.At(i, j); //Только чётные столбцы
			uindex++;
		}
	}
}

Vector::~Vector()
{
	delete []Vector::varray;
}