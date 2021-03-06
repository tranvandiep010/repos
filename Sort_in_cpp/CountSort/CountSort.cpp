// CountSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Sắp xếp với độ phức tạp O(n)
//Áp dụng khi các phần tử nhận giá trị trong khoảng [0...k] với k<<n(rất nhỏ)

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
int b[1000], c[1000];
void countsort(int *a, int *b, int *c, int n, int k)
{
	memset(c, 0, 1000 * sizeof(int));
	for (int i = 0; i < n; ++i) c[a[i]]++;
	for (int i = 1; i <= k; ++i) c[i] += c[i - 1];//dành chỗ cho mỗi phần tử vd giá trị 0 có 1 phần tử thì c[0]=1
	for (int i=n-1;i>=0;i--)
	{
		b[c[a[i]]--] = a[i];
	}
}
int main()
{
	int n = 0, a[1000],k=5;
	ifstream file;
	file.open("data.txt");
	file >> n;
	for (int i = 0; i < n; ++i)
		file >> a[i];
	countsort(a, b, c, n, k);
	return 0;
}