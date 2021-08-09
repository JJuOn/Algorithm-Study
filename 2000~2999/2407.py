import sys

n,m=sys.stdin.readline().rstrip().split(' ')
n,m=int(n),int(m)

factorial=[1 for i in range(101)]

for i in range(1,n+1):
    factorial[i]=i*factorial[i-1]

print(int(factorial[n]//factorial[m]//factorial[n-m]))