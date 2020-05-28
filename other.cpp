#include "other.h"
#include <iostream>
#include <cstdarg>
#include <cmath>



// задание 1.


void printArray(int ar[][col], int Row)
{
	
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << ar[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void printArray(int** ar, int Row, int Col)
{

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			std::cout << ar[i][j] << ' ';
		}
		std::cout << '\n';
	}
}


//задание 2
bool isLeepYear(int yy)
{
	if (yy % 4 != 0) return false;
	else
		if (yy % 100 == 0 && yy % 400 != 0) return false;
		else return true;
}

int DayOfYear(int dd, int mm, int yy, int (*nDayTab)[12])
{
	int result = 0;
	for (int i = 0; i < mm-1; i++)
	{
		result += nDayTab[isLeepYear(yy)][i];
	}
	result += dd;

	return result;
}

void DayOfMonth(int yy, int day, int (*nDayTab)[12], int &returnDay, int &returnMonth)
{
	int y=isLeepYear(yy);
	int i = 0;
	while (day>28)
	{
		day -= nDayTab[y][i];
		i++;
	}
	returnDay = day;
	returnMonth=i + 1;
}

// задание 3а

void VarArgs(int first, ...)
{
	int* ptr=&first;

	while (*ptr)
	{
		std::cout << *(ptr++)<<' ';
	}
	std::cout << std::endl;
}

void VarArgs2(int first, ...)
{

	va_list argptr;
	int num=first;
	va_start(argptr, first);
	std::cout << num<<' ';

	while (num = va_arg(argptr, int))
	{
		std::cout <<num<<' ';
	}
	std::cout << std::endl;
	va_end(argptr);
}


//задание 4

double Sum(double a, double b)
{
	return a + b;
}

double Sub(double a, double b)
{
	return a - b;
}

double Mul(double a, double b)
{
	return a*b;
}

double Div(double a, double b)
{
	return a/b;
}
///////////////////////////////////////////////////

//Подсказка-заготовка для задания 5а
//Без использования макросов
/*
void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов




	//Печать числа элементов

}
*/
//#include "other.h"

///////////////////////////////////////////////////



void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется
												//переставить
				(*Swap)(pPrevious, pCurrent);
		}
}

void SwapInt(void* p1, void* p2)
{
	int tmp;
	
	tmp = *(static_cast<int*>(p1));

	*(static_cast<int*>(p1))= *(static_cast<int*>(p2));
	*(static_cast<int*>(p2))= tmp;
	
}

int CmpInt(void* p1, void* p2)
{
	int nResult= *(static_cast<int*>(p1)) - *(static_cast<int*>(p2));

	return nResult;
}

void SwapDouble(void* p1, void* p2)
{
	double tmp;

	tmp = *(static_cast<double*>(p1));

	*(static_cast<double*>(p1)) = *(static_cast<double*>(p2));
	*(static_cast<double*>(p2)) = tmp;

}

int CmpDouble(void* p1, void* p2)
{
	double nResult = *(static_cast<double*>(p1)) - *(static_cast<double*>(p2));
	
	return static_cast<int>(nResult);
}

void SwapStr(void* p1, void* p2)
{
	
	char* tmp;
	tmp = *reinterpret_cast<char**>(p1);
	
	*static_cast<char**>(p1)= *static_cast<char**>(p2);
	*static_cast<char**>(p2)=tmp;
	
	
}

int CmpStr(void* p1, void* p2)
{
	
	return strcmp(*(static_cast<char**>(p1)), *(static_cast<char**>(p2)));
}

//задание 6

const char* getString1()
{
	return "String 1";
}

const char* getString2()
{
	return "String 2";
}

const char* getString3()
{
	return "String 3";
}


//задание 7 

void ArAdd(int*& Ar, int& size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (num == Ar[i])
			return;
	}

	size++;
	int* NewAr = new int[size];
	for (int i = 0; i < size - 1; i++)
	{
		NewAr[i] = Ar[i];
	}

	NewAr[size - 1] = num;
	delete[]Ar;
	Ar = NewAr;
}

void PrintAr(const int* Ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << Ar[i] << ' ';
	}
	std::cout << std::endl;
}

//задание 8


int sum(int N)
{
	if (N == 1) return 1;

	else return N + sum(N - 1);
}

int count(int Num)
{
	if (Num < 10) return 1;

	else return 1 + count(Num / 10);
}

void recPrint(const char* ch)
{

	if (*ch == '\0') std::cout << std::endl;
	else
	{
		std::cout << *ch;
		recPrint(ch + 1);//recPrint(ch+ 1)
	}
}

void recPrintRevers(const char* ch)
{
	
	if (*ch) {
		recPrintRevers(ch+1);  //recPrint(ch+ 1)
		std::cout << *ch;
	}

}
