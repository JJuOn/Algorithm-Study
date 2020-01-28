import math

t=int(input())
while t:
    line=input()
    line=line.split()
    x=[int(line[0]),int(line[3])]
    y=[int(line[1]),int(line[4])]
    r=[int(line[2]),int(line[5])]
    d=math.sqrt(pow(abs(x[1]-x[0]),2)+pow(abs(y[1]-y[0]),2))
    if d==0:
        if r[0]==r[1]:
            print(-1)
        else:
            print(0)
    elif d<abs(r[1]-r[0]):
        print(0)
    elif d==abs(r[1]-r[0]):
        print(1)
    elif d<r[0]+r[1]:
        print(2)
    elif d==r[0]+r[1]:
        print(1)
    elif d>r[0]+r[1]:
        print(0)
    t-=1
