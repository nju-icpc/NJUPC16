#!/usr/bin/python3

from random import choice

n = int(input())
a = list(map(int, input().split()))

def check(f) :
    c = 0
    for x in a : 
        if x % f == 0 : 
            c += 1
    if c * 2 >= n :
        print('YES')
        exit(0)

for _ in range(15) :
    x = choice(a)
    i = 2
    while i * i <= x :
        if x % i == 0 :
            while x % i == 0 : x /= i
            check(i)
        i += 1
    if x > 1 : check(x)

print('NO')
