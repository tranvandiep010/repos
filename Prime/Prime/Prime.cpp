#include <iostream>

bool prime(int n)
{
	int i = int(sqrt(n))+1;
	if (n < 2) return false;
	for (int j = 2; j < i; ++j)
	{
		if (n%j == 0) return false;
	}
	return true;
}

int main()
{
	int n;
	std::cout << "Nhap so can kiem tra:";
	std::cin >> n;
	if (prime(n)) std::cout << "1"; else std::cout << "0";
	getchar();
	return 0;
}