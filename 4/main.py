#!/usr/bin/python3
import sys, itertools

def is_palindrome(num):
	num = str(num)
	for i in range(len(num)):
		if i >= len(num):
			return False
		elif not num[i] == num[-1-i]:
			return False
	else:
		return True

def main():
	a = b = 999
	num = 0
	for a,b in itertools.product(range(100,1000),range(100,1000)):
		if is_palindrome(a*b):
			if num < a*b:
				num = a*b
		else:
			print("{0} = {1} x {2}".format(a*b,a,b))
			if a == b:
				a -= 1
			else:
				b -= 1
	print("Largest palindrome of two 3 digit numbers: {0}".format(num))
if __name__ == "__main__":
	main()