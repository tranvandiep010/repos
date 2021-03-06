// priority_queqe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void Max_heapify(int *a, int i, int n)
{
	int max = 0;
	int left = (i + 1) * 2 - 1;//con trái
	int right = (i + 1) * 2;//con phải
	if (left < n && a[left] > a[i]) max = left;
	else max = i;//tìm max(con trái,con phải)
	if (right < n && a[right] > a[max]) max = right;
	if (max != i)//nếu giá trị lớn nhất không phải cha thì đổi chỗ và gọi đệ quy
	{
		swap(a + i, a + max);
		Max_heapify(a, max, n);
	}
}
int Heap_extract_max(int *a,int *n)//Lấy ra phần tử lớn nhất và vun lại đống
{
	if (*n < 1) return INT_MAX;
	int max = a[0];
	a[0] = a[--*n];//gán cái lớn nhất bằng nhỏ nhất
	Max_heapify(a, 0, *n);
	return max;
}
int Heap_Increase_Key(int *a, int i, int key)//hàm tăng giá trị của phần tử i
{
	if (key < a[i]) return a[i];
	a[i] = key;
	int parent = (i + 1) / 2 - 1;
	while (i>0 && a[parent] < a[i])//vun lại đống
	{
		swap(a + i, a + parent);
		i = parent;
		parent = (i + 1) / 2 - 1;
	}
	return a[i];
}
void Heap_max_Insert(int *a, int key, int *n)//thêm phần tử
{
	a = (int*)realloc(a, (++*n) * sizeof(int));
	a[*n - 1] = -INT_MAX;
	int l=Heap_Increase_Key(a, *n-1, key);
}
int main()
{
	int *a;
	int *n = new int[1];
	ifstream file;
	file.open("mang.txt");
	file >> *n;
	a = new int[*n];
	for (int i = 0; i < *n; ++i) file >> a[i];
	Heap_max_Insert(a, 22, n);
	for (int i = 0; i < *n; ++i) cout << a[i] << " ";
	cout << Heap_extract_max(a, n);
	delete(n);
	delete(a);
	return 0;
}