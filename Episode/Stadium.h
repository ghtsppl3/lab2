#pragma once
#include <string> //����� �� �� ��������

/*
������� 7
����� �������.
������: �����, ���������� ����, ���������� ��������, �����������,
������������.
������� 2 �������� � ���� � ���� � �����. ���������� ������ ������ ���� �
������� ��������, ������ �������� ���������� � ������������ �
�����������. � ������� ������� �������������� ������ ����� � ���������
������� ������������ ���������� ��������� ����������� � ����������
������� ���������� ������� ��������. ������� ���������� � ���������,
������������ �� � ������� �������� �������� �������� ���������� �� ������
�����
*/

class Stadium
{
public:
	Stadium(void);
	Stadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance);
	void serialize();
	void serialize(std::string filename);
	void deserialize();
	void deserialize(std::string filename);
	//�������================================
	std::string getAddress();
	std::string getClubName();
	unsigned int getSectorCount();
	unsigned int getCapacity();
	unsigned int getAttendance();
	//�������================================

	//�������================================
	void setAddress(std::string Address);
	void setClubName(std::string clubName);
	void setSectorCount(unsigned int count);
	void setCapacity(unsigned int Capacity);
	void setAttendance(unsigned int Attendance);
	//�������================================

	~Stadium(void);
private:
	std::string address; //����� (��������, �������)
	std::string f_club; //���������� ���� (��������, �������)
	unsigned int sectors_count; //���������� �������� (�� ��� �� �������)
	unsigned int capacity; //� ���������, ��� � �����)
	unsigned int attendance; //������������. � ��� �� ��������, ��� � �� ������ ����. Translated by Google Translate
};

