#!/usr/bin/python3

print(sum([x if x%3==0 or x%5==0 else 0 for x in range(1000)]))