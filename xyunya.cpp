#include <iostream>
#include <cstdlib> 
#include <set>
#include <ctime>  
#include "windows.h"
using namespace std;

int length;

int* WritePointer(int* point,int value)
{
	*point = value;
	return point;
}

void initialization(int* arr)
{
	int start = 11;
	int end = 200;
	for(int i = 0; i < length; i++)
	{
		if((rand() % 2) > 0) {
			WritePointer((arr + i), rand() % (end - start + 1));
		}
		else { WritePointer((arr + i), (rand() % end - start + 1) * -1); }
	}
}

void ReadPointer(int* point) { cout << *point << " "; }

int* NewPointer (int n)
{
	int* arr = new int[n];
	return arr;
}

void printArray(int* arr)
{
	for (int i = 0; i < length; i++)
	{
		ReadPointer(arr + i);
	}
	cout << endl;
}

void task(int* arr)
{
	int count = 0;
	int razn = 0;
	for (int i = 0; i < length; i++)
	{
		int el = *(arr + i);
		if(el % 11 == 0 && el > 0)
		{
			count++;
			razn -= el;
		}
	}
	cout << "Разность положительных чисел кратных 11 " << razn << endl;
	cout << "Количество положительных чисел кратных 11 " << count << endl;
}

void FreePointer(int*& arr)
{
	if(arr == nullptr){ cout << "Ошибка достпупа. Функция уже была вызвана"<<endl; }
	else {
		delete[] arr;
		arr = nullptr;
	}
}

void check(int* arr)
{
	if (arr != nullptr) { 
		cout << "Происходит повторное выделение памяти: старые данные не сохраняются" << endl;
		FreePointer(arr);
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));

	while (true) {
		cout << "Введите количество элементов массива: ";
		cin >> length;
		if (cin.fail() || length <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Ошибка: Введите целое число \n";
		}
		else {
			break;
		}
	}

	int* A = nullptr;
	check(A);

	A = NewPointer(length);
	check(A);

	A = NewPointer(length);
	initialization(A);
	printArray(A);
	task(A);
	FreePointer(A);
}