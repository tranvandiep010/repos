
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#define MAX 50000
typedef unsigned long ll;
using namespace std;
void randomtree(int *prufer0,int *prufer,int *n)
{
	cin >> *n;
	int n2 = *n - 2; //n-2 phan tu
	//int prufer[MAX] = { 0 };
	//int prufer0[MAX] = { 0 };
	bool elements[MAX] = { 0 };


	srand(time(NULL));

	prufer[n2] = 0;

	for (int i = 0; i < n2; i++)
	{

		prufer[i] = rand() % (n2 + 2);

	}


	for (int i = 0; i < n2 + 1; i++) elements[prufer[i]] = true;


	for (int i = 0; i < n2 + 1; i++)
	{

		int j = 0; while (elements[j]) j++;  //tim phan tu nho nhat
		elements[j] = true;
		prufer0[i] = j;

		elements[prufer[i]] = false;        // Prufer[i] co the dung cho phan tu tiep theo
		for (int k = i + 1; k < n2 + 1; k++)   // tru khi prufer[i] co khong mat o phia sau 
			if (prufer[i] == prufer[k])
			{
				elements[prufer[i]] = true;
				break;
			}
	}
}
int main()
{
	//ll  read1 = 0, read2 = 0;
	int dem = 0;
	int c[MAX];
	//ifstream fileInput("C:/Users/Phoenix/Desktop/Data.txt");

	//if (fileInput.fail())
	//{
	//	cout << "Failed to open this file!" << endl;
	//	return -1;
	//}
	//fileInput >> n;
	//n++;
	//int arr[Max][2];
	int b[MAX];
	memset(b, 0, MAX);
	//int k = 0;
	int prufer0[MAX], prufer[MAX];
	//while (!fileInput.eof())
	int n[1];
	randomtree(prufer0, prufer, n);
	for (int i=0;i<*n-1;++i)
	{
		//read1 = prufer0[i];
		//read2 = prufer[i];
		//arr[k][0] = read1;
		//arr[k][1] = read2;
		//k++;
		b[prufer0[i]]++;
		b[prufer[i]]++;
		//cout << read1 << " " << read2 << endl;
		cout << setw(5)<<prufer0[i] << " " <<setw(5)<< prufer[i] << endl;
	}
	//fileInput.close();
	for (int i = 0; i < *n; ++i) cout << b[i] << " ";
	cout << endl;
	bool isStart = true;
	while (isStart)
	{
		for (int i = 1;i < *n;++i)
		{
			if (b[i] == 1)
			{
				for (int j = 0; j < *n; ++j)
				{
					if ((prufer0[j] == i)&& b[prufer[j]]!=0)
					{
						b[prufer[j]]--;
						c[dem] = prufer[j];
						dem++;
						break;
					}
					if (prufer[j] == i && b[prufer0[j]]!=0)
					{
						b[prufer0[j]]--;
						c[dem] = prufer0[j];
						dem++;
						break;
					}
				}
				b[i]--;
				break;
			}
			if (i == *n-1) isStart = false;
		}
	}
	cout << dem << endl;
	for (int i = 0; i < dem; ++i) cout << c[i] << " ";
	return 0;
}