// Episode.cpp: ���������� ����� ����� ��� ����������� ����������.
/*
������������ ������ �2. ������ �����, ��-6, ���=7
������� � 7
��������� �������� �������������� ������� ���������
� ������������ � ��������������� ������ � �����������/�����������.
������� 1: �������� ������ Vector � Matrix ��� �������� � ���������
			���������� � ��������� ��������, ��������������. �����������
			������� 2 ������������ ������ �1 � ������� ��������� �������. ���
			������� �������� � ���� ������� �������.
		����������� ��������� ���������� � ���������� (��� �����������,
			��� � ������������). ����� ���������� / ���������� ����� �������
			����������� � ���������� / ���������� ������� �������� �������.
������� 2: �������� ����� Fraction ��� ������������� ������������ ������ (���
			��������� ���� ����� ����� x/y). ����������� ��������� +, -, *, / ���
			������.
		���������� �������� ��������, ���������,
			��������� � ������� ������. ������� �� ����� ����������. ��������
			����� ���������� ������ ����������� ������� ������.
������� 3: �������� ����������� �����, � ������������ � ���������.
			������������������ � ���� ������������ ������, ����������
			������������� ��� ���������� � � ����������� ��� �������������
			������. 
*/


#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <iomanip>
#include <string>
#include "Vector.h"
#include "Matrixx.h"
#include "Fraction.h"
#include "Stadium.h"

void screenOutput(char* str)
{
	std::cout << std::endl << str << std::endl << std::endl; //���� (������� ��� ����)//
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	
	//Vector
	screenOutput("������������ �������� ������� Vector:");
	
	Vector vk1(10);
	
	for(unsigned int i = 0; i < 10; i++)
	{
		vk1[i] = i+1;
		std::cout << std::setw(4) << vk1[i];
	}
	screenOutput("\n\n ������������ �������� ������� Matrix:");

	Matrixx m1(5, 5);

	for(unsigned int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		for(unsigned int j = 0; j < 5; j++)
		{
			m1.setAt(i, j, i+j);
			std::cout << std::setw(4) << m1.At(i, j);
		}
	}

	screenOutput("\n\n ��������� ������������ ���������� �� ������� Vector:");

	Vector vk2 = vk1++;

	for(unsigned int i = 0; i < 10; i++)
	{
		std::cout << std::setw(4) << vk2[i];
	}

	screenOutput("\n\n ��������� ����������� ���������� �� ������� Vector:");

	Vector vk3 = ++vk1;

	for(unsigned int i = 0; i < 10; i++)
	{
		std::cout << std::setw(4) << vk3[i];
	}

	screenOutput("\n\n ��������� ������������ ���������� �� ������� Matrix:");

	Matrixx m2 = m1++;

	for(unsigned int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		for(unsigned int j = 0; j < 5; j++)
		{
			std::cout << std::setw(4) << m2.At(i, j);
		}
	}

	screenOutput("\n\n ��������� ����������� ���������� �� ������� Matrix:");

	Matrixx m3 = ++m1;

	for(unsigned int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		for(unsigned int j = 0; j < 5; j++)
		{
			std::cout << std::setw(4) << m3.At(i, j);
		}
	}

	screenOutput("\n\n ���������� ������� ������� �� �1 �� �������� 7:");

	m1.InitializeArr();
	
	Vector resArr(m1.GetISize() + m1.GetJSize());
	
	screenOutput("\n\n �������� �������:");
	
	for (unsigned int i = 0; i < m1.GetISize(); i++)
	{
		std::cout << std::endl;
		for (unsigned int j = 0; j < m1.GetJSize(); j++)
			std::cout << std::setw(8) <<m1.At(i, j);
	}

	resArr.ConvertArray(m1);
	screenOutput("\n\n ������� 1D-������:");

	for (unsigned int i = 0; i < resArr.GetSize(); i++)
		std::cout << std::setw(3) << resArr[i];
	
	screenOutput("\n\n �����:");

	Fraction fract1(2, 4);
	Fraction fract2(2.4);


	screenOutput("\n\n �����, ��������� �� �������� ���������/�����������:");
	fract1.formatAsText(true);
	screenOutput("\n\n �����, ��������� �� ������������� �����:");
	fract2.formatAsText(true);

	screenOutput("\n\n �������� ������:");
	std::cout << (fract1 + fract2).formatAsText(false) << std::endl;
	screenOutput("\n\n ��������� ������:");
	std::cout << (fract1 - fract2).formatAsText(false) << std::endl;
	screenOutput("\n\n ��������� ������:");
	std::cout << (fract1 * fract2).formatAsText(false) << std::endl;
	screenOutput("\n\n ������� ������:");
	std::cout << (fract1 / fract2).formatAsText(false) << std::endl;
	
	screenOutput("\n\n ���������� ����� 10/70:");
	Fraction tempfrac(10, 70);
	tempfrac.Reduce();
	tempfrac.formatAsText(true);
	
	screenOutput("\n\n ���������� ����� �������� 100, 500:");
	std::cout << Fraction::gcd(100, 500) << std::endl;

	screenOutput("\n\n ����� ����� 0.43, ��� �����:");

	Fraction::PrintAsFraction(0.43);

	screenOutput("\n\n ����� ����� '0.43', ��� �����:");

	Fraction::PrintAsFraction("0.43"); //Fuck this

	std::cout << "�� ������ ������ �������� " << Fraction::createdFractionCount << " �������� ������ Fraction" << std::endl;

	screenOutput("������������ ������ '�������'");

	//�������� ���������
	Stadium* st1 = new Stadium();
	Stadium* st2 = new Stadium();
	Stadium st3("��. �������������, 128, 256", "������", 10, 20000, 1000);
	//�������� ���������

	//�������
	st1->setAddress("��. �����������, 15");
	st1->setClubName("�������");
	st1->setSectorCount(100);
	st1->setCapacity(100000);
	st1->setAttendance(599999);
	//---
	st2->setAddress("��. ������ ����������, -1, -1");
	st2->setClubName("BeerBand");
	st2->setSectorCount(12);
	st2->setCapacity(1000);
	st2->setAttendance(300);
	//�������

	screenOutput("\n\n ������� ������ � ��������:");

	std::cout << "������: " << st1->getAddress() << std::endl << "����: " << st1->getClubName() << std::endl << "���������� ��������: " << st1->getSectorCount() << std::endl << "�����������: " << st1->getCapacity() << std::endl << "������������: " << st1->getAttendance() <<std::endl << std::endl;
	std::cout << "������: " << st2->getAddress() << std::endl << "����: " << st2->getClubName() << std::endl << "���������� ��������: " << st2->getSectorCount() << std::endl << "�����������: " << st2->getCapacity() << std::endl << "������������: " << st2->getAttendance() <<std::endl << std::endl;
	std::cout << "������: " << st3.getAddress() << std::endl << "����: " << st3.getClubName() << std::endl << "���������� ��������: " << st3.getSectorCount() << std::endl << "�����������: " << st3.getCapacity() << std::endl << "������������: " << st3.getAttendance() <<std::endl << std::endl;


	//�����
	screenOutput("\n\n �����:");

	int percent[3][4];

	for(unsigned int i = 0; i < 4; i++)
	{
		std::cout << i+1 <<"-� ����" << std::endl << std::endl;
		st1->setAttendance(rand() % 599999 + 1);
		percent[0][i] = st1->getAttendance()*100/st1->getCapacity();

		std::cout << "������: " << st1->getAddress() << std::endl << "����: " << st1->getClubName() << std::endl << "���������� ��������: " << st1->getSectorCount() << std::endl << "�����������: " << st1->getCapacity() << std::endl << "������������: " << st1->getAttendance() <<std::endl << std::endl;

		st2->setAttendance(rand() % 100000 + 1);
		percent[1][i] = st2->getAttendance()*100/st2->getCapacity();

		std::cout << "������: " << st2->getAddress() << std::endl << "����: " << st2->getClubName() << std::endl << "���������� ��������: " << st2->getSectorCount() << std::endl << "�����������: " << st2->getCapacity() << std::endl << "������������: " << st2->getAttendance() <<std::endl << std::endl;

		st3.setAttendance(rand() % 1000 + 1);
		percent[2][i] = st3.getAttendance()*100/st3.getCapacity();

		std::cout << "������: " << st3.getAddress() << std::endl << "����: " << st3.getClubName() << std::endl << "���������� ��������: " << st3.getSectorCount() << std::endl << "�����������: " << st3.getCapacity() << std::endl << "������������: " << st3.getAttendance() <<std::endl << std::endl;

		std::cout << "====================================================" << std::endl;
	}

	int averagepercent[4];
	int tempaver;

	for(unsigned int i = 0; i < 3; i++)
	{
		tempaver = 0;
		for(unsigned int j = 0; j < 4; j++)
		{
			tempaver+=percent[i][j];
		}
		tempaver /= 4;
		averagepercent[i] = tempaver;
	}
	
	 unsigned int n=1;
	 unsigned int a;
    while(n)
    {
            n=0;
            for(unsigned int i=0; i < 4; i++)
            { 
              if (averagepercent[i] < averagepercent[i+1])
              { 
                 n = 1;
                 a = averagepercent[i+1]; averagepercent[i+1]=averagepercent[i];
                 averagepercent[i]=a;
              }
            }
    }

	for(unsigned int i = 0; i < 4; i++)
		std::cout << "������� ���������� " << i+1 << "_�� �������� �� ������ �����: " << averagepercent[i] <<std::endl;

	delete st1;
	delete st2;
	system("pause");
	return 0;
}

