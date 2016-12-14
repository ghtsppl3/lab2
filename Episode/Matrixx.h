#pragma once

/*� ������
Matrix �������� ������ T at(int i, int j) const � setAt(int i, int j, T val),
������� ��������� �������� � ���������� �������� ��������
������� � �������� [i][j], T � ��� ��� ��������� ������� ��
�������� (int ��� double).*/

class Matrixx
{
public:
	Matrixx(unsigned int size_i, unsigned int size_j); //����������� ��������� ������� ���������� �������
	Matrixx(const Matrixx& m); //����������
	Matrixx & operator++();
	Matrixx operator++(int);
	double At(unsigned int i, unsigned int j) const;
	void setAt(unsigned int i, unsigned int j, double Value);
	unsigned int GetISize();
	unsigned int GetJSize();
	void InitializeArr(); //��� ���������� ������� ������� �й1
	~Matrixx();
private:
	double** marray;
	unsigned int s_i;
	unsigned int s_j;
	double factorial(double number); //�� �����, ��������, ��-�� ����� ������� ���������� ����� cmath ����������
};

