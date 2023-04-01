
#include<iostream>
using namespace std;

void Fill_Rand(int* ARR, const int SIZE);
void Print_Arr(int* ARR, const int SIZE);
void Push_Back(int*& ARR, int& SIZE, int VALUE);


void main()
{
	setlocale(LC_ALL, "");

	int size;
	cout << "Введите размер массива: "; cin >> size;
	int* arr = new int[size];

	Fill_Rand(arr, size);
	Print_Arr(arr, size);
	cout << endl;
	int value;
	cout << "Введите число для добавления: "; cin >> value;
	Push_Back(arr, size, value);
	Print_Arr(arr, size);

	delete[] arr;
}


void Fill_Rand(int* ARR, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		*(ARR + i) = rand() % 50;
}

void Print_Arr(int* ARR, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		cout << *(ARR + i) << '\t';
}


void Push_Back(int*& ARR, int& SIZE, int VALUE)
{
	int* NewArr = new int[SIZE + 1];//объявляем новый массив на размер больше
	for (int i = 0; i < SIZE; i++)
		NewArr[i] = ARR[i];         // копируем значения в новый массив
	delete[] ARR;                   // удаляем старый массив
	ARR = NewArr;                   // присваиваем указателю новый массив
	NewArr[SIZE++] = VALUE;         // добавляем значение и меняем значение размера
}