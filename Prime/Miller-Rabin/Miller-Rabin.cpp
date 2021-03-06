#include <iostream>
#include <tuple>

void phan_tich( unsigned long n,unsigned long *s,unsigned long *m)
{
	while ((n&1)==0)
	{
		*s++;
		n >>= 1;
	}
	*m = n;
}
void random(int *a)
{
	*a = 2;
	*(a + 1) = 3;
	*(a + 2) = 5;
	*(a + 3) = 7;
	*(a + 4) = 11;
	*(a + 5) = 13;
	*(a + 6) = 17;
	*(a + 7) = 19;
	//2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 63, 1662803
}
unsigned long poww(unsigned long a, unsigned long n, unsigned long d)
{
	unsigned long result = 1;
	a = a % n;
	while (d > 0)
	{
		if (d & 1) result = result * a % n;
		d >>= 1;
		a = a * a%n;
	}
	return result;
}
bool snt(unsigned long a, unsigned long s, unsigned long n, unsigned long d)
{
	if (n == a) return true;
	unsigned long p = poww(a, n, d);
	if (p == 1) return true;
	for (; s > 0; s--)
	{
		if (p == n - 1) return true;
		p = p * p%n;
	}
	return false;
}
bool miller(unsigned long n) {
	if (n < 2) return false;
	if ((n & 1) == 0) return n == 2;
	unsigned long *s, *d;
	s = new unsigned long[1];
	d = new unsigned long[1];
	phan_tich(n - 1,s,d);
	int *a = new int[7];
	random(a);
	for (int i = 0; i < 4; ++i)
		if (!snt(*(a + i), *s, n, *d)) return false;
	return true;
}
using namespace std;
int main()
{
	int n;
	cout << "Nhap n:=";
	cin >> n;
	if (miller(n)) cout << "1"; else cout << "0";
}