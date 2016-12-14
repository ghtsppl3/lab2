#pragma once

#include "Matrixx.h"

/*
��������� � ������������ ������������ ������ ����������� �
������������� � ������������ �������, ��������������.
� ������ Vector ����������� �������� ���������� []
����������� ��������� ���������� � ���������� (��� �����������,
��� � ������������). ����� ���������� / ���������� ����� �������
����������� � ���������� / ���������� ������� �������� �������
*/

class Vector
{
public:
explicit Vector(unsigned int VectorLength); //����������� ��������� ����� ������� � �������� ���������
	Vector(const Vector& v); //����������
	double & operator[](unsigned int index); //���������� ��������� []. ��������� ��� ������, ��� � ������ ��������.
	Vector & operator++();
	Vector operator++(int);
	unsigned int GetSize();
	void ConvertArray(Matrixx m);
	~Vector();
private:
	double* varray;
	unsigned int VL; //���� ����� ����������� ����� ������� ��� ���������� ������
};

