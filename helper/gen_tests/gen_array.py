import sys
import random

n = int(sys.argv[1]) # Number of elements


l = 0
r = 1e9

to_sort = 0

if (len(sys.argv) >= 4):
    # Read L and R
    l = int(sys.argv[2])
    r = int(sys.argv[3])

if (len(sys.argv) == 5):
    to_sort = bool(sys.argv[4] == "1")

arr = []
for i in range(n):
    arr.append(random.randint(l, r))

if (to_sort):
    arr.sort()

print(n)
for x in arr:
    print(x, end=" ")