#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

unsigned long gcd(unsigned long a, unsigned long b)
{
	if (a >= b)
		if (b == 0)
			return a;
		else
			return gcd(b,a%b);
	else
		if (a == 0)
			return b;
		else
			return gcd(a,b%a);
}

bool is_prime(unsigned long i)
{
	if ((i <= 0) || (i%2 == 0))
		return false;
	else if (i == 2)
		return true;
	for (unsigned long j = 3; j < i; j+=2)
		if (i%j == 0)
			return false;
	return true;
}

unsigned long mod_pow(unsigned long base, unsigned long exponent, unsigned long modulus)
{
    unsigned long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

unsigned long get_prime(unsigned long low, unsigned long max)
{
	unsigned long prime = ((unsigned long)rand() % max) + low;
	while (mod_pow(2,prime-1,prime) != 1)
	{
		//Get another number
		//cout << "Prime " << prime << " it's not a prime." << endl;
		prime = ((unsigned long)rand() % max) + low;
	}
	if (is_prime(prime))
		return prime;
	else
		get_prime(low,max);
}

unsigned long get_factor(unsigned long num)
{
	unsigned count = 0;
	if (is_prime(num))
		return num;
	while (true)
	{
		unsigned long prime = 1;
		switch (count)
		{
			case 0 ... 22:
				prime = get_prime(1,100);
				break;
			case 23 ... 122:
				prime = get_prime(1,1000);
				break;
			case 123 ... 963:
				prime = get_prime(1,10000);
				break;
			case 964 ... 7723:
				prime = get_prime(1,100000);
				break;
			default:
				prime = get_prime(1,(unsigned long)num/2);
				break;
		}
		//cout << "Trying prime " << prime << endl;
		if (gcd(num,prime) != 1)
		{	
			cout << "Found a factor! " << prime << endl;
			return prime;
		}
		count++;
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	if (argc != 2)
	{
		cout << "Please give an usingsigned number to calculate it's factors." << endl;
		return -1;
	}
	else if (atol(argv[1]) < 0)
	{
		cout << "Please give an usingsigned number to calculate it's factors." << endl;
		return -2;
	}
	unsigned long N = atol(argv[1]);
	unsigned long original_N = N;
	unsigned long factors[10] = {0};
	cout << "Calculating factors of " << N << endl;
	unsigned i = 0;
	do
	{
		unsigned long a = get_factor(N);
		cout << a << " is a factor of N." << endl;
		N /= a;
		cout << "Reducing to " << N << endl;
		factors[i++] = a;
	}while(!is_prime(N));
	cout << N << " is a factor of N," << endl;
	factors[i++] = N;
	cout << "#########################################################" << endl;
	cout << "Factors of " << original_N << ": " << endl;
	for (unsigned i = 0; i < 10; i++)
	{
		if (factors[i] != 0)
			cout << factors[i] << " ";
	}
	cout << endl << "#########################################################" << endl;
	return 0;
}