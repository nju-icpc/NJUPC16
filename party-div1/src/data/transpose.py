#!/usr/bin/env python3
n = int(input())
print(n)
for x, y in [map(int, input().split()) for _ in range(n)] :
    print(y, x)
