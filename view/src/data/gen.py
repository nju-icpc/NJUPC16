#!/usr/bin/python2
import sys
h = int(sys.argv[1])
w = int(sys.argv[2])
print h, w

mat = eval('[ [ %s for i in range(w) ] for j in range(h) ]' % sys.argv[3])
for row in mat :
    print ' '.join(map(str, row))
