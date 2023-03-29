#include<iostream>
#include<cstdarg>

using namespace std;

// 1. Вычислить максимально возможный адресуемый объем памяти если разрядность адреса составляет 8 Байт;
//    Ответ : N = a^n = 2^64 = 2^60 * 2^4 = 1Экзобайт * 16 байт = 16 Экзобайт

#define tab "\t"

//#define POINTERS_BASICS



//int SumElement(int num, ...);

template<typename T>
T SumElement(int num, T value, ...);

void main()
{
	setlocale(LC_ALL, "");
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

	cout << "\nСумма элементов = " << SumElement(6, 18, 71, 22, 9, 36, 57);
}

//int SumElement(int num, ...)// - С помощью цикла while, не работает в х64
//{
//	int* ptr = &num;
//	int result = 0;
//	while (*ptr)
//	{
//		cout << *ptr << ", ";
//		result += *(ptr++);
//	}
//	return result;
//}

// * * * *

//int SumElement(int num, ...)// - С помощью цикла for, не работает в х64
//{
//	int result = 0;
//	for (int* ptr = &num; *ptr; result += *(ptr++));
//	return result;
//}

// * * * *

template<typename T>
T SumElement(int num, T value, ...)// С помощью подключенной библиотеки 'stdard' или 'cstdarg.h' работает в х86 и х64
{
	T result = 0;
	va_list list;
	va_start(list, num);
	for (int i = 0; i < num; i++)
	{
		value = va_arg(list, T);
		cout << value << "| ";
		result += value;
	}
	cout << endl;
	va_end(list);
	return result;
}