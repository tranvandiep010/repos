// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
vector<pair<int, int>> a[1000];
int dist[10000];
int pred[10000];
void dijkstra(int nV,int s)
{
	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	for (int i = 0; i < nV; ++i)
	{
		dist[i] = INT_MAX;
		pred[i] = INT_MAX;
	}
	dist[s] = 0;
	q.push(pair<int, int>(0, s));
	while (!q.empty())
	{
		int u = q.top().second;
		int distU = q.top().first;
		q.pop();
		if (distU != dist[u]) continue;
		for (int i = 0; int v = a[u][i].second; ++i)
		{
			int duv = a[u][i].first;
			if (dist[v] > dist[u] + duv)
			{
				dist[v] = dist[u] + duv;
				pred[v] = u;
				q.push(pair<int, int>(dist[v], v));
			}
		}
	}
}
int main()
{
	int nV = 0, nE = 0;
	ifstream file;
	file.open("dothi.txt");
	file >> nV >> nE;
	for (int i = 0; i < nE; ++i)
	{
		int x, y, w;
		file >> x >> y >> w;
		a[x].push_back(pair<int, int>(w, y));
		//a[y].push_back(pair<int, int>(w, x));
	}
	for (int i = 0; i < nV; i++) a[i].push_back(pair<int, int>(0, 0));
	dijkstra(nV, 0);
	for (int i = 0; i < nV; ++i) cout << i << ":" << dist[i]<<endl;
	return 0;
}