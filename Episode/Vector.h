#pragma once

#include "Matrixx.h"

/*
¬ыделение и освобождение динамической пам€ти производить в
конструкторах и деструкторах классов, соответственно.
¬ классе Vector перегрузить оператор индексации []
ѕерегрузить операторы инкремента и декремента (как префиксного,
так и постфиксного). —мысл инкремента / декремента всего массива
заключаетс€ в инкременте / декременте каждого элемента массива
*/

class Vector
{
public:
explicit Vector(unsigned int VectorLength); // онструктор принимает длину массива в качестве параметра
	Vector(const Vector& v); // опирующий
	double & operator[](unsigned int index); //ѕерегрузка оператора []. ѕозвол€ет как гетить, так и сетить значение.
	Vector & operator++();
	Vector operator++(int);
	unsigned int GetSize();
	void ConvertArray(Matrixx m);
	~Vector();
private:
	double* varray;
	unsigned int VL; //—юда будет скопирована длина массива дл€ дальнейшей работы
};

