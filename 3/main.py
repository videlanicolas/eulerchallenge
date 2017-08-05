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
	if is_prime(n):
		return n
	elif n%2 == 0:
		return 2
	a = 100
	count = 0
	while True:
		factor = get_prime(1,a)
		if gcd(n,factor) != 1:
			return factor
		if 23 < count < 122:
			a = 1000
		elif 123 < count < 963:
			a = 10000
		elif 964 < count < 7763:
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