// Kruskal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
int pred[1000],rank1[1000];
typedef struct Node
{
	int u, v;
	int value;
} Node;
int find(int v)
{
	while (v != pred[v]) v = pred[v];
	return v;
}
void makeNode(int v)
{
	pred[v] = v;
	rank1[v] = 0;
}
bool union1(int u, int v)
{
	int rx = find(u), ry = find(v);
	if (rx == ry) return false;
	if (rank1[rx] > rank1[ry]) pred[ry] = rx;
	else
	{
		pred[rx] = ry;
		if (rank1[rx] == rank1[ry]) rank1[ry] = rank1[rx] + 1;
	}
	return true;

}
void sort(Node *a, int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i].value > a[j].value)
			{
				Node t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
}
int main()
{
	ifstream file;
	file.open("dothi.txt");
	int nV, nE,nB=0;
	file >> nV >> nE;
	Node *a = new Node[nE], *b = new Node[nE];
	for (int i = 0; i < nE; ++i)
		file >> a[i].u >> a[i].v >> a[i].value;
	sort(a, nE);
	for (int i = 0; i < nV; ++i) makeNode(i);
	for (int i = 0; i < nE; ++i) 
		if (union1(a[i].u, a[i].v))
		{
			b[nB] = a[i];
			nB++;
		}
	for (int i = 0; i < nB; ++i) cout << b[i].u << b[i].v << endl;
	return 0;
}