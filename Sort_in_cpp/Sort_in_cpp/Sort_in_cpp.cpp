// Sort_in_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//quick_sort

#include "pch.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void quick_sort(int *a, int l, int r)
{
	int i = l;
	int j = r;
	int k = *(a + (l+r)/2);
	while (i <= j)
	{
		while (*(a + i) < k) i++;
		while (*(a + j) > k) j--;
		if (i <= j)	{
			int t = *(a + i);
			*(a + i) = *(a + j);
			*(a + j) = t;
			i++;
			j--;
		}
	}
	if (l < j) quick_sort(a, l, j);
	if (i < r) quick_sort(a, i, r);
}
int main()
{
	int n = 0, a[1000];
	ifstream file;
	file.open("data.txt");
	file >> n;
	for (int i = 0; i < n; ++i)
		file >> a[i];
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; ++i) cout << a[i] << endl;
	return 0;
}