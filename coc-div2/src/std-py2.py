#!/usr/bin/python2
def f(x) :
    if x == 1 :
        return 'COFFEE'
    if x == 2 : 
        return 'CHICKEN'
    return f(x - 2) + f(x - 1)

n, p = map(int, raw_input().split())
s = f(n)
p -= 1
l = min(10, len(s) - p)
print s[p:][:l]
