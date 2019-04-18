#!/usr/bin/python3
def f(x) :
    if x == 1 :
        return 'COFFEE'
    if x == 2 : 
        return 'CHICKEN'
    return f(x - 2) + f(x - 1)

print(len(f(int(input()))))
