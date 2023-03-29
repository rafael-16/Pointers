#include<iostream>
using namespace std;

void FillRand(int* ARR, const int SIZE);
void PrintArr(int* ARR, const int SIZE);
void AddElement(int*& ARR, int& SIZE, int VALUE);


void main()
{
	setlocale(LC_ALL, "");

	int size;
	cout << "������� ������ �������: "; cin >> size;
	int* arr = new int[size];

	FillRand(arr, size);
	PrintArr(arr, size);
	cout << endl;
	int value;
	cout << "������� ����� ��� ����������: "; cin >> value;
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
	int* NewArr = new int[SIZE + 1];//��������� ����� ������ �� ������ ������
	for (int i = 0; i < SIZE; i++)
		NewArr[i] = ARR[i];         // �������� ��� �������� � ����� ������
	NewArr[SIZE++] = VALUE;         // ���������� ����������� �������� � ������ �������� �������
	delete[] ARR;                   // ������� ������ ������
	ARR = NewArr;                   // ����������� ��������� ����� ������
}