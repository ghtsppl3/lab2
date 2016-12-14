#pragma once

/*В классе
Matrix добавить методы T at(int i, int j) const и setAt(int i, int j, T val),
которые позволяют получить и установить значение элемента
массива с индексом [i][j], T – это тип элементов массива по
варианту (int или double).*/

class Matrixx
{
public:
	Matrixx(unsigned int size_i, unsigned int size_j); //Конструктор принимает размеры двумерного массива
	Matrixx(const Matrixx& m); //Копирующий
	Matrixx & operator++();
	Matrixx operator++(int);
	double At(unsigned int i, unsigned int j) const;
	void setAt(unsigned int i, unsigned int j, double Value);
	unsigned int GetISize();
	unsigned int GetJSize();
	void InitializeArr(); //Для выполнение второго задания ЛР№1
	~Matrixx();
private:
	double** marray;
	unsigned int s_i;
	unsigned int s_j;
	double factorial(double number); //Не стоит, наверное, из-за одной функции подключать целый cmath подключать
};

