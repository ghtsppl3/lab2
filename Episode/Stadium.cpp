#include "StdAfx.h"
#include "Stadium.h"
#include <string>
#include <fstream>
#include <sstream>


Stadium::Stadium(void)
{
	/*Stadium::address = "";
	Stadium::f_club = "";
	Stadium::sectors_count = 0;
	Stadium::capacity = 0;
	Stadium::attendance = 0;*/
	Stadium::Stadium("", "", 0, 0, 0); //А норм ли так?
}

Stadium::Stadium(std::string Address, std::string clubName, unsigned int sectorsCount, unsigned int Capacity, unsigned int Attendance)
{
	Stadium::address = Address;
	Stadium::f_club = clubName;
	Stadium::sectors_count = sectorsCount;
	Stadium::capacity = Capacity;
	Stadium::attendance = Attendance;
}

void Stadium::serialize()
{
	Stadium::serialize("Stadium.txt");
}

void Stadium::serialize(std::string filename)
{
	std::ofstream SerializeFile(filename);
	SerializeFile << Stadium::address << std::endl << Stadium::f_club << std::endl << Stadium::sectors_count << std::endl << Stadium::capacity <<std::endl << Stadium::attendance;
	SerializeFile.close();
}

void Stadium::deserialize()
{
	Stadium::deserialize("Stadium.txt");
}

void Stadium::deserialize(std::string filename)
{
	std::ifstream dSerFile(filename);
	const unsigned int ch_length = 255;
	
	//Временные буферы============
	char ch_address[ch_length];
	char ch_clubname[ch_length];
	char ch_secCount[ch_length];
	char ch_capacity[ch_length];
	char ch_attendance[ch_length];
	//Временные буферы============

	//Чтение====================================
	dSerFile.getline(ch_address, ch_length);
	dSerFile.getline(ch_clubname, ch_length);
	dSerFile.getline(ch_secCount, ch_length);
	dSerFile.getline(ch_capacity, ch_length);
	dSerFile.getline(ch_attendance, ch_length);
	//Чтение====================================

	Stadium::address = ch_address;
	Stadium::f_club = ch_clubname;
	Stadium::sectors_count = std::stoi(ch_secCount);
	Stadium::capacity = std::stoi(ch_capacity);
	Stadium::attendance = std::stoi(ch_attendance);

	dSerFile.close();
}

std::string Stadium::getAddress()
{
	return Stadium::address;
}

std::string Stadium::getClubName()
{
	return Stadium::f_club;
}

unsigned int Stadium::getSectorCount()
{
	return Stadium::sectors_count;
}

unsigned int Stadium::getCapacity()
{
	return Stadium::capacity;
}

unsigned int Stadium::getAttendance()
{
	return Stadium::attendance;
}
//Геттеры кончились

//Сеттеры
void Stadium::setAddress(std::string Address)
{
	Stadium::address = Address;
}

void Stadium::setClubName(std::string clubName)
{
	Stadium::f_club = clubName;
}

void Stadium::setSectorCount(unsigned int count)
{
	Stadium::sectors_count = count;
}

void Stadium::setCapacity(unsigned int Capacity)
{
	Stadium::capacity = Capacity;
}

void Stadium::setAttendance(unsigned int Attendance)
{
	Stadium::attendance = Attendance;
}
//Сеттеры кончились

Stadium::~Stadium(void)
{

}

