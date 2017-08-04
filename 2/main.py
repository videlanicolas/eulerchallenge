#!/usr/bin/python3

nums = [0,1]
suma = 0
limite = 4000000
while True:
	parcial = sum(nums)
	if parcial >= limite:
		break
	suma += parcial if parcial%2 == 0 else 0
	nums[0] = nums[1]
	nums[1] = parcial
print(suma)