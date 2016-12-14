// Episode.cpp: определяет точку входа для консольного приложения.
/*
Лабораторная работа №2. Плыско Игорь, КН-6, ИВТ=7
Вариант № 7
Подробные описания индивидуальных заданий приведены
в комментариях в соответствующих файлах с заголовками/реализацией.
Задание 1: Написать классы Vector и Matrix для хранения и обработки
			одномерных и двумерных массивов, соответственно. Реализовать
			задание 2 лабораторной работы №1 с помощью созданных классов. Все
			функции оформить в виде методов классов.
		Перегрузить операторы инкремента и декремента (как префиксного,
			так и постфиксного). Смысл инкремента / декремента всего массива
			заключается в инкременте / декременте каждого элемента массива.
Задание 2: Написать класс Fraction для представления обыкновенных дробей (как
			отношения двух целых чисел x/y). Перегрузить операторы +, -, *, / для
			дробей.
		Произвести операции сложения, вычитания,
			умножения и деления дробей. Вывести на экран результаты. Показать
			также результаты работы статических методов класса.
Задание 3: Написать собственный класс, в соответствии с вариантом.
			Продемонстрировать в коде инкапсуляцию данных, применение
			конструкторов без параметров и с параметрами для инициализации
			данных. 
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
	std::cout << std::endl << str << std::endl << std::endl; //Лажа (коммент для гита)//
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	
	//Vector
	screenOutput("Демонстрация создания объекта Vector:");
	
	Vector vk1(10);
	
	for(unsigned int i = 0; i < 10; i++)
	{
		vk1[i] = i+1;
		std::cout << std::setw(4) << vk1[i];
	}
	screenOutput("\n\n Демонстрация создания объекта Matrix:");

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

	screenOutput("\n\n Результат постфиксного инкремента на примере Vector:");

	Vector vk2 = vk1++;

	for(unsigned int i = 0; i < 10; i++)
	{
		std::cout << std::setw(4) << vk2[i];
	}

	screenOutput("\n\n Результат префиксного инкремента на примере Vector:");

	Vector vk3 = ++vk1;

	for(unsigned int i = 0; i < 10; i++)
	{
		std::cout << std::setw(4) << vk3[i];
	}

	screenOutput("\n\n Результат постфиксного инкремента на примере Matrix:");

	Matrixx m2 = m1++;

	for(unsigned int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		for(unsigned int j = 0; j < 5; j++)
		{
			std::cout << std::setw(4) << m2.At(i, j);
		}
	}

	screenOutput("\n\n Результат префиксного инкремента на примере Matrix:");

	Matrixx m3 = ++m1;

	for(unsigned int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		for(unsigned int j = 0; j < 5; j++)
		{
			std::cout << std::setw(4) << m3.At(i, j);
		}
	}

	screenOutput("\n\n Реализация второго задания ЛР №1 по варианту 7:");

	m1.InitializeArr();
	
	Vector resArr(m1.GetISize() + m1.GetJSize());
	
	screenOutput("\n\n Исходная матрица:");
	
	for (unsigned int i = 0; i < m1.GetISize(); i++)
	{
		std::cout << std::endl;
		for (unsigned int j = 0; j < m1.GetJSize(); j++)
			std::cout << std::setw(8) <<m1.At(i, j);
	}

	resArr.ConvertArray(m1);
	screenOutput("\n\n Готовый 1D-массив:");

	for (unsigned int i = 0; i < resArr.GetSize(); i++)
		std::cout << std::setw(3) << resArr[i];
	
	screenOutput("\n\n Дроби:");

	Fraction fract1(2, 4);
	Fraction fract2(2.4);


	screenOutput("\n\n Дробь, созданная из готового числителя/знаменателя:");
	fract1.formatAsText(true);
	screenOutput("\n\n Дробь, созданная из вещественного числа:");
	fract2.formatAsText(true);

	screenOutput("\n\n Сложение дробей:");
	std::cout << (fract1 + fract2).formatAsText(false) << std::endl;
	screenOutput("\n\n Вычитание дробей:");
	std::cout << (fract1 - fract2).formatAsText(false) << std::endl;
	screenOutput("\n\n Умножение дробей:");
	std::cout << (fract1 * fract2).formatAsText(false) << std::endl;
	screenOutput("\n\n Деление дробей:");
	std::cout << (fract1 / fract2).formatAsText(false) << std::endl;
	
	screenOutput("\n\n Сокращение дроби 10/70:");
	Fraction tempfrac(10, 70);
	tempfrac.Reduce();
	tempfrac.formatAsText(true);
	
	screenOutput("\n\n Наибольший общий делитель 100, 500:");
	std::cout << Fraction::gcd(100, 500) << std::endl;

	screenOutput("\n\n Вывод числа 0.43, как дроби:");

	Fraction::PrintAsFraction(0.43);

	screenOutput("\n\n Вывод числа '0.43', как дроби:");

	Fraction::PrintAsFraction("0.43"); //Fuck this

	std::cout << "На данный момент созданно " << Fraction::createdFractionCount << " объектов класса Fraction" << std::endl;

	screenOutput("Демонстрация класса 'Стадион'");

	//Создание стадионов
	Stadium* st1 = new Stadium();
	Stadium* st2 = new Stadium();
	Stadium st3("ул. Переплюевская, 128, 256", "Газмяс", 10, 20000, 1000);
	//Создание стадионов

	//Сеттеры
	st1->setAddress("ул. Костыльская, 15");
	st1->setClubName("Ноголом");
	st1->setSectorCount(100);
	st1->setCapacity(100000);
	st1->setAttendance(599999);
	//---
	st2->setAddress("ул. именни Велосипеда, -1, -1");
	st2->setClubName("BeerBand");
	st2->setSectorCount(12);
	st2->setCapacity(1000);
	st2->setAttendance(300);
	//Сеттеры

	screenOutput("\n\n Текущие данные в объектах:");

	std::cout << "Адресс: " << st1->getAddress() << std::endl << "Клуб: " << st1->getClubName() << std::endl << "Количество секторов: " << st1->getSectorCount() << std::endl << "Вместимость: " << st1->getCapacity() << std::endl << "Посещаемость: " << st1->getAttendance() <<std::endl << std::endl;
	std::cout << "Адресс: " << st2->getAddress() << std::endl << "Клуб: " << st2->getClubName() << std::endl << "Количество секторов: " << st2->getSectorCount() << std::endl << "Вместимость: " << st2->getCapacity() << std::endl << "Посещаемость: " << st2->getAttendance() <<std::endl << std::endl;
	std::cout << "Адресс: " << st3.getAddress() << std::endl << "Клуб: " << st3.getClubName() << std::endl << "Количество секторов: " << st3.getSectorCount() << std::endl << "Вместимость: " << st3.getCapacity() << std::endl << "Посещаемость: " << st3.getAttendance() <<std::endl << std::endl;


	//Матчи
	screenOutput("\n\n Матчи:");

	int percent[3][4];

	for(unsigned int i = 0; i < 4; i++)
	{
		std::cout << i+1 <<"-й матч" << std::endl << std::endl;
		st1->setAttendance(rand() % 599999 + 1);
		percent[0][i] = st1->getAttendance()*100/st1->getCapacity();

		std::cout << "Адресс: " << st1->getAddress() << std::endl << "Клуб: " << st1->getClubName() << std::endl << "Количество секторов: " << st1->getSectorCount() << std::endl << "Вместимость: " << st1->getCapacity() << std::endl << "Посещаемость: " << st1->getAttendance() <<std::endl << std::endl;

		st2->setAttendance(rand() % 100000 + 1);
		percent[1][i] = st2->getAttendance()*100/st2->getCapacity();

		std::cout << "Адресс: " << st2->getAddress() << std::endl << "Клуб: " << st2->getClubName() << std::endl << "Количество секторов: " << st2->getSectorCount() << std::endl << "Вместимость: " << st2->getCapacity() << std::endl << "Посещаемость: " << st2->getAttendance() <<std::endl << std::endl;

		st3.setAttendance(rand() % 1000 + 1);
		percent[2][i] = st3.getAttendance()*100/st3.getCapacity();

		std::cout << "Адресс: " << st3.getAddress() << std::endl << "Клуб: " << st3.getClubName() << std::endl << "Количество секторов: " << st3.getSectorCount() << std::endl << "Вместимость: " << st3.getCapacity() << std::endl << "Посещаемость: " << st3.getAttendance() <<std::endl << std::endl;

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
		std::cout << "Среднее заполнение " << i+1 << "_го стадиона за четыре матча: " << averagepercent[i] <<std::endl;

	delete st1;
	delete st2;
	system("pause");
	return 0;
}

