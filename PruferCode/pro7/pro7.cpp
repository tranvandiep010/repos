#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#define MAX 100000
// -------------------------------------------------------
void Random_Tree(int *prufer0, int *prufer, int *n)
{
	int n2 = *n - 2; //n-2 phan tu
	bool e[MAX] = { 0 };
	srand(time(NULL));

	prufer[n2] = 0;

	for (int i = 0; i < n2; i++)
	{

		prufer[i] = rand() % (n2 + 2);

	}


	for (int i = 0; i < n2 + 1; i++) e[prufer[i]] = true;


	for (int i = 0; i < n2 + 1; i++)
	{

		int j = 0; while (e[j]) j++;  //tim phan tu nho nhat
		e[j] = true;
		prufer0[i] = j;

		e[prufer[i]] = false;        // Prufer[i] co the dung cho phan tu tiep theo
		for (int k = i + 1; k < n2 + 1; k++)   // tru khi prufer[i] co khong mat o phia sau 
			if (prufer[i] == prufer[k])
			{
				e[prufer[i]] = true;
				break;
			}
	}
}
//---------------------------------------------------------
using namespace std;


int main()
{
	int *prufer0, *prufer, *n;
	int *step;
	int *code_prufer;
	int dem = 0;
	cout << "Nhap so dinh cua do thi:";
	n = new int[1];
	cin >> *n;
	prufer0 = new int[*n];
	prufer = new int[*n];
	step = new int[MAX];
	memset(step, 0, MAX);
	Random_Tree(prufer0, prufer, n);
	cout << "Danh sach canh cua do thi la(random):" << endl;
	for (int i = 0; i < *n - 1; ++i)
	{
		cout << *(prufer0 + i) << " " << *(prufer + i) << endl;
		(*(step + *(prufer0 + i)))++;
		(*(step + *(prufer + i)))++;
	}
	//for (int i = 0; i < *n; ++i) cout << step[i] << " ";
	code_prufer = new int[*n];
	bool isStart = true;
	while (isStart)
	{
		for (int i = 1; i < *n; ++i)
		{
			if (step[i] == 1)
			{
				for (int j = 0; j < *n; ++j)
				{
					if ((prufer0[j] == i) && step[prufer[j]] != 0)
					{
						step[prufer[j]]--;
						code_prufer[dem] = prufer[j];
						dem++;
						break;
					}
					if (prufer[j] == i && step[prufer0[j]] != 0)
					{
						step[prufer0[j]]--;
						code_prufer[dem] = prufer0[j];
						dem++;
						break;
					}
				}
				step[i]--;
				break;
			}
			if (i == *n - 1) isStart = false;
		}
	}
	dem--;
	cout << "Ma prufer cua do thi tren la:" << endl;
	for (int i = 0; i < dem; ++i) cout << code_prufer[i] << " ";
	delete(prufer0);
	delete(prufer);
	delete(n);
	delete(step);
	delete(code_prufer);
	return 0;
}