// graphuv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#define max 100000
//-------------------------------------------------------------------------
bool edge(char *s, int x1, int x2)
{
	int kt = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (*(s + x1*5 + i) != *(s + x2*5 +  i)) kt++;
	}
	if (kt == 1) return true;
	return false;
}
//--------------------------------------------------------------------------
void fight(char *s,int *x,int v0,int n,int u0)
{
	bool isStart = true;
	if (x[u0] !=0 )
	{
		for (int i = 0; i < n; ++i)
			if (x[i] == 0 && edge(s, i, u0))
			{
				x[i] = x[u0] + 1;
				if (i == v0) isStart = false;
			}
	}
	if (isStart && u0!=n-1) fight(s, x, v0, n, u0 + 1);
}
//--------------------------------------------------------------------------
using namespace std;
int main()
{
	char arr[max];
	char u[5];
	char v[5];
	int u0, v0;
	ifstream fileinput("sgb_words.txt");
	int n = 0;
	while (!fileinput.eof())
	{
		fileinput >> arr[n];
		n++;
	}
	fileinput.close();
	cout << "Nhap u:";
	cin >> u[0] >> u[1] >> u[2] >> u[3] >> u[4];
	cout << "Nhap v:";
	cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
	u0 = n;
	v0 = n;
	for (int i = 0; i < n - 1; ++i)
	{
		//if (i % 5 == 0 && i != 0) cout << endl;
		//cout << arr[i];
		if (i % 5 == 4 && arr[i] == u[4] && arr[i - 1] == u[3] && arr[i - 2] == u[2] && arr[i - 3] == u[1] && arr[i - 4] == u[0])
			u0 = i - 4;
		if (i % 5 == 4 && arr[i] == v[4] && arr[i - 1] == v[3] && arr[i - 2] == v[2] && arr[i - 3] == v[1] && arr[i - 4] == v[0])
			v0 = i - 4;
	}
	int x[10000];
	//memset(x, 0, 10000);
	for (int i = 0; i < 10000; ++i) x[i] = 0;
	if (u0 != n && v0 != n)
	{
		v0 /= 5;
		u0 /= 5;
		x[u0] = 1;
		n /= 5;
		fight(arr, x, v0, n, 0);
		for (int i = 0; i < n; ++i) cout << x[i] << " ";
		cout <<endl<< x[u0] << " " << x[v0] << endl;
	}
	
	else cout << "khong lien thong";
	getchar();
	return 0;
}