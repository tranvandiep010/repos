//thuat toan sang so nguyen to
#include <iostream>
#include <iomanip>


bool prime(int n)
{
	int i = int(sqrt(n)) + 1;
	if (n < 2) return false;
	for (int j = 2; j < i; ++j)
	{
		if (n%j == 0) return false;
	}
	return true;
}
//---------------------------------------------
void Sieve(bool *arr,int a,int b)
{
	memset(arr, false,b);
	for (int i = a; i < b + 1; ++i)
		if (prime(i)) *(arr + i-1) = true;
}

using namespace std;
int main()
{
	int a, b;
	bool *arr;
	std::cout << "Nhap dau mut a:=";
	std::cin >> a;
	std::cout << "Nhap dau mut b:=";
	std::cin >> b;
	arr = new bool[b];
	Sieve(arr, a, b);
	for (int i = a; i < b + 1; ++i)
		if (*(arr + i - 1)) std::cout << setw(4) << i <<setw(3)<< "1\n";
		else std::cout << setw(4) << i <<setw(3)<< "0\n";
	getchar();
	return 0;
}