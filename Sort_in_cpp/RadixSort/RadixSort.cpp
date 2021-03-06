// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//sắp xếp theo cơ số 10
//có áp dụng sắp xếp đếm

#include "pch.h"
#include <iostream>
#include <fstream>
void RadixSort(int *a, int n)
{
	int i, b[1000], m = a[0], exp = 1;
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
using namespace std;
int main()
{
	int n = 0, a[1000];
	ifstream file;
	file.open("data.txt");
	if (file.fail())
		cout << "Failed to open this file!" << std::endl;
	file >> n;
	for (int i = 0; i < n; ++i)
		file >> a[i];
	RadixSort(a, n);
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
	file.close();
	return 0;
}