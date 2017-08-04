#include <iostream>

using namespace std;

int fibo(unsigned n)
{
	if (n < 2)
		return n+1;
	else
		return fibo(n-1) + fibo(n-2);
};

int main()
{
	unsigned limit = 4000000, sum = 0, i = 0, num = 0;
	while (num < limit)
	{
		num = fibo(i++);
		if (num%2 == 0)
			sum += num;
	}
	cout << sum;
	return 0;
}