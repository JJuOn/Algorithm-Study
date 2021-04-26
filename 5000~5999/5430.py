from sys import stdin, stdout
from collections import deque

tc=int(stdin.readline())

while tc!=0:
    command=stdin.readline().rstrip().replace("RR","")
    listLen=int(stdin.readline().rstrip())
    arrStr=stdin.readline().rstrip()
    li=arrStr[1:-1].split(',')
    dq=deque(li)
    errorFlag=False
    r=False
    for c in list(command):
        if c=='R':
            r=not r
        elif c=='D':
            if len(dq)==0 or arrStr=="[]":
                errorFlag=True
                break
            if not r:
                dq.popleft()
            else:
                dq.pop()
    if errorFlag:
        stdout.write("error\n")
    elif not r:
        stdout.write("["+",".join(dq)+"]\n")
    else:
        stdout.write("["+",".join(list(dq)[::-1])+"]\n")
    tc-=1