// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
void adjust(int *a,int i, int n)
{
	int key = *(a + i);
	int j = 2 * (i + 1) - 1;
	while (j < n)
	{
		if ((j < n-1) && (*(a + j) < *(a + j + 1))) j++; //Nếu khóa con phải lớn hơn thì j ghi nhận số thứ tự của nó
		if (key > *(a + j))
		{
			*(a + j / 2) = key;
			return;
		}
		*(a + j / 2) = *(a + j);
		j = j * 2;
	}
	*(a + j / 2) = key;
	return;
}
//--------------------------------------------------
void Heap_Sort(int *a,int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		adjust(a, i, n);
	}
	for (int i = n - 1; i > 0; i--)
	{
		int t = *(a + 1);
		*(a + 1) = *(a + i + 1);
		*(a + i + 1) = t;
		adjust(a, 0, i);
	}
}

int main()
{
	int n, *a;
	ifstream file;
	file.open("data.txt");
	file >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i)
		file >> a[i];
	Heap_Sort(a, n);
	for (int i = 0; i < n; ++i)
		cout << *(a + i) << endl;
	getchar();
	return 0;
}