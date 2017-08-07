#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

unsigned long min(unsigned long a, unsigned long b)
{
	if (a < b)
		return a;
	else
		return b;
}

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
	unsigned count = 23;
	if (num%2 == 0)
		return 2;
	if (is_prime(num))
		return num;
	unsigned primes100[] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};
	for (unsigned i = 0; i<(sizeof(primes100)/sizeof(*primes100)); i++)
	{
		if (num < primes100[i])
			break;
		if (num%primes100[i] == 0)
			return primes100[i];
	}
	while (true)
	{
		unsigned long prime = 1;
		switch (count)
		{
			case 23 ... 122:
				prime = get_prime(1,min(num,10000));
				break;
			case 123 ... 963:
				prime = get_prime(1,min(num,100000));
				break;
			case 964 ... 7723:
				prime = get_prime(1,min(num,1000000));
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
	unsigned long factors[100] = {0};
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
	for (unsigned i = 0; i < 100; i++)
	{
		if (factors[i] != 0)
			cout << factors[i] << " ";
	}
	cout << endl << "#########################################################" << endl;
	return 0;
}