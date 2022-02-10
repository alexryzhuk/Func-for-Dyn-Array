// Func for Dyn Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void inputArr(int* arr, int size){
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}
void printArr(int* arr, int size){
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
void deleteArr(int* arr, int size)
{
	delete[]arr;
}
void addElement(int* arr, int size){	
	int x;
	cout << "Введіть елемент, який бажаєте додати" << endl;
	cin >> x;
	int size1 = size + 1;
	int* arr1 = new int[size1];
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
	}	
	arr1[size] = x;
	cout << "Масив з доданим в кінець елементом" << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << " ";
		cout << arr1[i];
	}
	cout << endl;
	delete[]arr1;
}
void insertElement(int* arr, int size) {
	int index, numb;
	cout << "Вкажіть індекс елемента, за яким вставити" << endl;
	cin >> index;
	cout << "Вкажіть елемент, який бажаєте вставити новий елемент" << endl;
	cin >> numb;
	int* arr1 = new int[++size];		
	if (index > 1 && index < size) {
		index--;
		for (int i = 0; i < index; i++)
		{
			arr1[i] = arr[i];
		}
		arr1[index] = numb;
		for (int i = index; i < size - 1; i++)
		{
			arr1[i + 1] = arr[i];
		}
		arr = arr1;
		cout << "Масив з доданим елементом по вказаному індексу" << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << " ";
			cout << arr[i];
		}
	}
	else
		cout << "Error" << endl;
	cout << endl;
	delete[]arr1;
}
void deleteElement(int* arr, int &size) {
	int n;
	cout << "Вкажіть індекс елемента, який бажаєте видалити" << endl;
	cin >> n;
	if (n > size && n < 1)
	{
		cout << "Невірно введений індекс" << endl;
	}
	else {
		for (int i = n-1; i < size-1; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
		cout << "Масив з видаленим елементом по вказаному індексу" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " ";
			cout << arr[i];
		}
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	
	int size = 1;
	int x;
	cout << "Введіть розмір масиву" << endl;
	cin >> size;
	int* arr = new int[size];	
	inputArr(arr, size);
	cout << "Початковий масив" << endl;
	printArr(arr, size);
	cout << endl;
	addElement(arr, size);
	insertElement(arr, size);
	deleteElement(arr, size);
	deleteArr(arr, size);

	
}
