#include<iostream>
using namespace std;

void FillRand(int* ARR, const int SIZE);
void PrintArr(int* ARR, const int SIZE);
void AddElement(int*& ARR, int& SIZE, int VALUE);


void main()
{
	setlocale(LC_ALL, "");

	int size;
	cout << "Введите размер массива: "; cin >> size;
	int* arr = new int[size];

	FillRand(arr, size);
	PrintArr(arr, size);
	cout << endl;
	int value;
	cout << "Введите число для добавления: "; cin >> value;
	AddElement(arr, size, value);
	PrintArr(arr, size);

	delete[] arr;
}


void FillRand(int* ARR, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		*(ARR + i) = rand() % 50;
}

void PrintArr(int* ARR, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		cout << *(ARR + i) << '\t';
}


void AddElement(int*& ARR, int& SIZE, int VALUE)
{
	int* NewArr = new int[SIZE + 1];//объявляем новый массив на размер больше
	for (int i = 0; i < SIZE; i++)
		NewArr[i] = ARR[i];         // копируем все значения в новый массив
	NewArr[SIZE++] = VALUE;         // дописываем добавленное значение и меняем значение размера
	delete[] ARR;                   // удаляем старый массив
	ARR = NewArr;                   // присваиваем указателю новый массив
}