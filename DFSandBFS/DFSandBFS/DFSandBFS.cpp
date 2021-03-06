// DFSandBFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#define max 100000
//ham tim canh giua hai tu
bool edge(char *s, int x1,int x2)
{
	int kt = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (*(s + x1 + i) != *(s + x2 + i)) kt++;
	}
	if (kt == 1) return true;
	return false;
}
void graph(char *s, int n,int *x,int *l)
{
	int label = 1;
	int i = 0;
	while (1)
	{
		int kt = true;
		if (x[i]==0) x[i] = label;
		for (int j = i + 1; j < n; ++j)
		{
			if (edge(s, i * 5, j * 5) && x[j] == 0)
			{
				x[j] = label;
				kt = false;
			}
		}
		if (kt && i != n - 1) label++;
		if (i == n-1) break;
		i++;
	}
	*l = label;
}
using namespace std;
int main()
{
	char arr[max];
	ifstream fileinput("sgb_words.txt");
	int n = 0;
	while (!fileinput.eof())
	{
		fileinput >> arr[n];
		n++;
	}
	fileinput.close();
	for (int i = 0; i < n-1; ++i)
	{
		if (i % 5 == 0 && i != 0) cout << endl;
		cout << arr[i] ;
	}
	n /= 5;
	cout << endl;
	int x[2000];
	memset(x, 0, 2000);
	int *label;
	label = new int[1];
	graph(arr, n, x, label);
	cout << *label;
	getchar();
	return 0;
}