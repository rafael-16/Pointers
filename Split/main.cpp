#include<iostream>

using namespace std;

void Fill_Rand(int* arr, int size);
void Print_Arr(int* arr, int size);
void Count_Even_Odd(int* arr, int size, int& count_even, int& count_odd);//подсчитаем кол-во четных и нечетных, это будут размеры массивов.
void Split_Arr(int* arr, int* even, int* odd, int size);//делим массив на два - с четными и нечетными числами.

void main()
{
	setlocale(LC_ALL, "");
	int size;
	int count_even = 0, count_odd = 0;

	cout << "Введите размер массива: "; cin >> size;
	int* arr = new int[size];
	Fill_Rand(arr, size);
	Print_Arr(arr, size);
	Count_Even_Odd(arr, size, count_even, count_odd);

	int* even = new int[count_even];
	int* odd = new int[count_odd];

	Split_Arr(arr, even, odd, size);
	cout << "Массив с четными числами:" << endl;
	Print_Arr(even, count_even);
	cout << "Массив с нечетными числами:" << endl;
	Print_Arr(odd, count_odd);

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
	cout << endl;
}

void Count_Even_Odd(int* arr, int size, int& count_even, int& count_odd)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
			count_even++;
		else
			count_odd++;
	}
}

void Split_Arr(int* arr, int* even, int* odd, int size1)
{
	for (int i = 0, j = 0, k = 0; i < size1; i++)
	{
		if ((arr[i] % 2) == 0)
			even[j++] = arr[i];
		else
			odd[k++] = arr[i];
	}
}


