#pragma once
#include <string> //Никто же не запрещал

/*
Вариант 7
Класс СТАДИОН.
Данные: адрес, футбольный клуб, количество секторов, вместимость,
посещаемость.
Создать 2 стадиона в куче и один в стеке. Установить данные первых двух с
помощью сеттеров, данные третьего установить в конструкторе с
параметрами. В главной функции проимитировать четыре матча – случайным
образом сформировать количество пришедших посетителей и просчитать
процент заполнения каждого стадиона. Вывести информацию о стадионах,
отсортировав их в порядке убывания среднего процента заполнения за четыре
матча
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
	//Геттеры================================
	std::string getAddress();
	std::string getClubName();
	unsigned int getSectorCount();
	unsigned int getCapacity();
	unsigned int getAttendance();
	//Геттеры================================

	//Сеттеры================================
	void setAddress(std::string Address);
	void setClubName(std::string clubName);
	void setSectorCount(unsigned int count);
	void setCapacity(unsigned int Capacity);
	void setAttendance(unsigned int Attendance);
	//Сеттеры================================

	~Stadium(void);
private:
	std::string address; //Адрес (стадиона, наверно)
	std::string f_club; //Футбольный клуб (название, наверно)
	unsigned int sectors_count; //Количество секторов (ну тут всё понятно)
	unsigned int capacity; //В человеках, как я понял)
	unsigned int attendance; //Посещаемость. В тех же единицах, что и на строку выше. Translated by Google Translate
};

