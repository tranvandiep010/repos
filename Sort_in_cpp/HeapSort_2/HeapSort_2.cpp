// HeapSort_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void Max_heapify(int *a, int i, int n)
{
	int max = 0;
	int left = (i+1) * 2-1;
	int right = (i+1) * 2;
	if (left < n && a[left] > a[i]) max = left;
	else max = i;
	if (right < n && a[right] > a[max]) max = right; 
	if (max != i)
	{
		swap(a + i, a + max);
		Max_heapify(a, max, n);
	}
}
void Build_max_heap(int *a,int n)
{
	for (int i = n / 2-1; i >=0; --i)
	{
		Max_heapify(a, i, n);
	}
}
void Heap_sort(int *a, int n)
{
	Build_max_heap(a, n);
	for (int i = n - 1; i > 0; --i)
	{
		swap(a, a + i);
		Max_heapify(a, 0, i);
	}
}
using namespace std;
int main()
{
	int a[] = {4,1,3,2,16,9,10,14,8,7};
	int n = 10;
	Heap_sort(a, n);
	for (int i = 0; i < 10; ++i) cout << a[i] << " " << endl;
}