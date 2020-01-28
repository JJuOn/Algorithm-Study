t=int(input())
x=[]
y=[]
counts=[]
while t:
    line=input()
    line=line.split()
    x.append(int(line[0]))
    y.append(int(line[1]))
    counts.append(0)
    t-=1
for i in range(len(x)):
    count=0
    for j in range(len(x)):
        if i!=j and x[i]<x[j] and y[i]<y[j]:
            counts[i]+=1

for count in counts:
    count+=1
    print(count,end=" ")