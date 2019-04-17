#!/usr/bin/env python2
import ctypes, sys
val = ctypes.c_uint64(eval(sys.argv[1]))
print '%d' % val.value
