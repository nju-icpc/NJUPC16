#!/usr/bin/python2

from random import choice

n = input()
a = map(int, raw_input().split())

def check(f) :
    if sum([1 for x in a if x % f == 0]) * 2 >= n :
        print 'YES'
        exit(0)

for _ in xrange(15) :
    x = choice(a)
    i = 2
    while i * i <= x :
        if x % i == 0 :
            while x % i == 0 : x /= i
            check(i)
        i += 1
    if x > 1 : check(x)

print 'NO'
