#include<iostream>

using namespace std;

void Fill_Rand(int* arr, int size);
void Print_Arr(int* arr, int size);
void Fill_Even(int* arr, int* even, int size1, int& size2);
void Fill_Odd(int* arr, int* even, int size1, int& size2);

void main()
{
	setlocale(LC_ALL, "");
	int size;
	int even_size = 0;
	int odd_size = 0;

	cout << "Введите размер массива: "; cin >> size;
	int* arr = new int[size];
	Fill_Rand(arr, size);
	Print_Arr(arr, size);
	cout << "\n\n";

	int* even = new int[size];
	Fill_Even(arr, even, size, even_size);
	cout << "Массив с четными числами:" << endl;
	Print_Arr(even, even_size);
	
	cout << "\n\n";

	int* odd = new int[size];
	Fill_Odd(arr, odd, size, odd_size);
	cout << "Массив с нечетными числами:" << endl;
	Print_Arr(odd, odd_size);

	delete[] even;
	delete[] odd;
	delete[] arr;
	cout << endl;
}

void Fill_Rand(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		*(arr + i) = rand() % 50;
}

void Print_Arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << *(arr + i) << '\t';
}

void Fill_Even(int* arr, int* even, int size1, int& size2)
{
	for (int i = 0; i < size1; i++)
	{
		if ((arr[i] % 2) == 0)
		{
			even[size2++] = arr[i];
		}
	}
}

void Fill_Odd(int* arr, int* odd, int size1, int& size2)
{
	for (int i = 0; i < size1; i++)
	{
		if (arr[i] % 2)
		{
			odd[size2++] = arr[i];
		}
	}
}

