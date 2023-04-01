
#include<iostream>
using namespace std;

void Fill_Rand(int* ARR, const int SIZE);
void Print_Arr(int* ARR, const int SIZE);
template<typename T>
T* Push_Back(T arr[], int& size, T value);
template<typename T>
T* Push_Front(T arr[], int& size, T value);
template<typename T>
T* Pop_Back(T arr[], int& size);
template<typename T>
T* Pop_Front(T arr[], int& size);
template<typename T>
T* Insert_To_Arr(T arr[], int& size, int index, T value);
template<typename T>
T* Erase_From_Arr(T arr[], int& size, int index);


void main()
{
	setlocale(LC_ALL, "");

	int size, value, index;
	cout << "Введите размер массива: "; cin >> size;
	int* arr = new int[size];
	Fill_Rand(arr, size);
	Print_Arr(arr, size);
	cout << "Введите число для добавления: "; cin >> value;
	arr = Push_Back(arr, size, value);
	Print_Arr(arr, size);
	cout << "Добавляем число в начало:" << endl;
	arr = Push_Front(arr, size, value);
	Print_Arr(arr, size);
	cout << "Удаляем последнее  значение:" << endl;
	arr = Pop_Back(arr, size);
	Print_Arr(arr, size);
	cout << "Удаляем первое значение:" << endl;
	arr = Pop_Front(arr, size);
	Print_Arr(arr, size);
	cout << "Введите индекс для добавления: "; cin >> index;
	arr = Insert_To_Arr(arr, size, index, value);
	Print_Arr(arr, size);
	cout << "Удаляем значение по индексу:" << endl;
	arr = Erase_From_Arr(arr, size, index);
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
	cout << endl;
}

template<typename T>
T* Push_Back(T arr[], int& size, T value)
{
	T* buffer = new T[size + 1];//объявляем новый массив на размер больше
	for (int i = 0; i < size; i++)
		buffer[i] = arr[i];         // копируем значения в новый массив
	delete[] arr;                   // удаляем старый массив
	arr = buffer;                   // присваиваем указателю новый массив
	buffer[size] = value;         // добавляем значение и меняем значение размера
	size++;
	return arr;
}

template<typename T>
T* Push_Front(T arr[], int& size, T value)
{
	T* buffer = new T[size + 1];
	for (int i = 0; i < size; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	buffer[0] = value;
	size++;
	return arr;
}

template<typename T>
T* Pop_Back(T arr[], int& size)
{
	T* buffer = new T[--size];
	for (int i = 0; i < size; i++)
		buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>
T* Pop_Front(T arr[], int& size)
{
	T* buffer = new T[--size];
	for (int i = 0; i < size; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>
T* Insert_To_Arr(T arr[], int& size, int index, T value)
{
	T* buffer = new T[size + 1];
	for (int i = 0; i <= size; i++)
	{
		if (i < index)
			buffer[i] = arr[i];
		else if (i == index)
			buffer[i] = value;
		else if (i > index)
			buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	size++;
	return arr;
}

template<typename T>
T* Erase_From_Arr(T arr[], int& size, int index)
{
	T* buffer = new T[--size];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
