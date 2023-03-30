
#include<iostream>
using namespace std;

void Fill_Rand(int* ARR, const int SIZE);
void Print_Arr(int* ARR, const int SIZE);
void AddElement(int*& ARR, int& SIZE, int VALUE);


void main()
{
	setlocale(LC_ALL, "");

	int size;
	cout << "������� ������ �������: "; cin >> size;
	int* arr = new int[size];

	Fill_Rand(arr, size);
	Print_Arr(arr, size);
	cout << endl;
	int value;
	cout << "������� ����� ��� ����������: "; cin >> value;
	AddElement(arr, size, value);
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


void AddElement(int*& ARR, int& SIZE, int VALUE)
{
	int* NewArr = new int[SIZE + 1];//��������� ����� ������ �� ������ ������
	for (int i = 0; i < SIZE; i++)
		NewArr[i] = ARR[i];         // �������� ��� �������� � ����� ������
	NewArr[SIZE++] = VALUE;         // ��������� �������� � ������ �������� �������
	delete[] ARR;                   // ������� ������ ������
	ARR = NewArr;                   // ����������� ��������� ����� ������
}