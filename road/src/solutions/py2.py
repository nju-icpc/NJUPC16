from math import *

def rot(pt) :
    return (-pt[1], pt[0])

def dist(pt, vec) :
    return (pt[0] * vec[0] + pt[1] * vec[1]) / hypot(*vec)

def dif(pt1, pt2) :
    return (pt1[0] - pt2[0], pt1[1] - pt2[1])

n = input()
pts = []
for _ in range(n) :
    pts.append(tuple(map(float, raw_input().split())))

ans = 0.0

def check(vec) :
    res = list(map(lambda pt : dist(pt, vec), pts))
    res.sort()
    return res[n / 2] - res[n / 2 - 1]

for i in range(n) :
    for j in range(i) :
        dvec = dif(pts[i], pts[j])
        ans = max(ans, check(dvec), check(rot(dvec)))

ans /= 2.0

print "%.9f" % ans
