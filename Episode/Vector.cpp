#include "StdAfx.h"
#include "Vector.h"
#include "Matrixx.h"


Vector::Vector(unsigned int VectorLength)
{
	Vector::varray = new double[VectorLength]; //�������� � ���� ����������� ������� � ������� VectorLength
	for (unsigned int i = 0; i < VectorLength; i++)
		Vector::varray[i] = 0; //�������� ������ �������
	Vector::VL = VectorLength; //���������� ����� ������� �� �������
}

Vector::Vector(const Vector & v)
{
	varray = new double[v.VL];
	memcpy(varray, v.varray, v.VL*sizeof(double)); //�� ���� ����� ������ ���� ���� �������
	VL = v.VL; //���������� ����� ������� �� �������
}

double & Vector::operator[](unsigned int index)
{
	return Vector::varray[index];
}

Vector & Vector::operator++() //�������� ����������� ����������
{
	for (unsigned int i = 0; i < Vector::VL; i++)
		++Vector::varray[i];
	return *this;
}

Vector Vector::operator++(int) //�������� ������������ ����������
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

void Vector::ConvertArray(Matrixx m) //����������� 2D -> 1D �������� ������� ������������ ������ �1
{
	unsigned int uindex = 0; //��� ������ � ���������������� ��������
	for (int i = 0; i < m.GetISize(); i++)
	{
		for (int j = 0; j < m.GetJSize(); j++)
		{
			if ((i % 2) == 0) { continue; }
			Vector::varray[uindex] = m.At(i, j); //������ ������ �������
			uindex++;
		}
	}
}

Vector::~Vector()
{
	delete []Vector::varray;
}