#include "pch.h"
#include <iostream>


typedef struct Node
{
	int data;
	Node *next;
} Node;
typedef Node *List;
void InitNode(List &l)
{
	l = NULL;
}
Node *Make_Node(Node *P, int x) //tao 1 Node P chua thong tin la x 
{
	P = (Node *)malloc(sizeof(Node)); //Cap phat vung nho cho P
	P->next = NULL; //Cho truong Next tro den NULL
	P->data = x; //Ghi du lieu vao Data
	return P;
}
bool edge(char *s, int x1, int x2)
{
	int kt = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (*(s + x1 * 5 + i) != *(s + x2 * 5 + i)) kt++;
	}
	if (kt == 1) return true;
	return false;
}
void fight(char *s,int *x, int *a,int na,int *b,int nb, int v0, int n, int u0)
{
	for (int j=0;j<na;++j)
	for (int i = 0; i < n; ++i)
	{
		if (x[i] == 0 && edge(s, a[j], i))
		{
			b[nb] = i;
			nb++;
		}
	}
}
int main()
{

	return 0;
}