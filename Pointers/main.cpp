#include<iostream>
#include<stdlib.h>
#include<stdarg.h>
using namespace std;


#define tab "\t"

//#define POINTERS_BASICS



int SumElement(int num, ...)
{
	int* ptr = &num + 1;
	int result = 0;
	for (; num > 0; num--)
	{
		cout << *ptr << '\t';
		result += *(ptr++);
	}
	return result;
}

void main()
{
	system("chcp 1251");
#ifdef POINTERS_BASICS

	int a = 2;
	int* pa = &a;//объявление указателя 'pa', и иницализация его адресом переменной 'a'
	cout << a << endl;//вывод значения переменной 'a'
	cout << &a << endl;//взятие адреса переменной 'a' прямо при выводе
	cout << pa << endl;//вывод адреса переменной 'a', хранящегося в указателе
	cout << *pa << endl;//разыменование указателя 'pa' 



	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr + i << " (" << arr[i] << ")" << tab;
	}
#endif // POINTER_BASICS

	cout << "\nСумма элементов = " << SumElement(4, 10, 50, 20, 20);
}