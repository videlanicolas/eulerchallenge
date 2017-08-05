#!/usr/bin/python3
from fractions import gcd
from random import randint
import sys

def is_prime(n):
	if n==2:
		return True
	return False if any([(n%2 == 0)] + [True if n%x == 0 else False for x in range(2,n)]) else True

def get_prime(_min,_max):
	#Get a random number and test for primality, then make a real test for primality
	prime = 1
	while True:
		while pow(2,prime-1,prime) != 1:
			prime = randint(_min,_max)
		if is_prime(prime):
			return prime

def get_factor(n):
	if pow(2,n-1,n) == 1:
		if is_prime(n):
			return n
	if n%2 == 0:
		return 2
	a = 100
	count = 0
	#Check if first 100 primes 
	for prime in  [3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541]:
		if gcd(n,prime) != 1:
			return prime
	while True:
		factor = get_prime(1,a)
		if gcd(n,factor) != 1:
			return factor
		if 0 <= count < 30:
			a = 100
		elif 30 <= count < 122:
			a = 1000
		elif 122 <= count < 963:
			a = 10000
		elif 963 <= count < 7763:
			a = 100000
		else:
			a = int(n/2)
		if count <= 7763:
			count += 1

if __name__ == "__main__":
	N = int(sys.argv[1])
	factors = list()
	print("Calculating factors for {} ...".format(N))
	n = N
	while not is_prime(n):
		factors.append(get_factor(n))
		print("{0} is a factor of {1}.".format(factors[-1],N))
		n = int(n / factors[-1])
		print("Reducing {0} to {1}.".format(N,n))
	factors.append(n)
	print("{0} is a factor of {1}.".format(factors[-1],N))
	print("Factors of {} are: ".format(N))
	print(*set(factors),sep=' ')