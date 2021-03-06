// merge_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
void merge(int *a, int l, int r, int q)
{
	int b[100], c[100];
	memset(b, 100, 100 * sizeof(int));
	memset(c, 100, 100 * sizeof(int));
	for (int i = 0; i < q + 1 - l; ++i) b[i] = a[l + i];
	for (int i = 0; i < r - q; ++i) c[i] = a[q + i + 1];
	int i = 0, j = 0;
	for (int k = l; k <= r; ++k)
	{
		if (b[i] < c[j])
		{
			a[k] = b[i];
			i++;
		}
		else
		{
			a[k] = c[j];
			j++;
		}
	}
}

void merge_sort(int *a,int l,int r)
{
	if (l < r)
	{
		int q = (l + r) / 2;
		merge_sort(a, l, q);
		merge_sort(a, q + 1, r);
		merge(a,l, r, q);
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
	merge_sort(a, 0, n-1);
	for (int i = 0; i < n; ++i) cout << a[i] << endl;
	return 0;
}