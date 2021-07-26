import sys

def input():
    return sys.stdin.readline().rstrip()

line=input()
stack=[]
line=list(line)
result=""
for c in line:
    if c.isalpha():
        result+=c
    else:
        if c=='(':
            stack.append(c)
        elif c=='*' or c=='/':
            while len(stack)>0 and (stack[-1]=='*' or stack[-1]=='/'):
                result+=stack.pop()
            stack.append(c)
        elif c=='+' or c=='-':
            while len(stack)>0 and stack[-1]!='(':
                result+=stack.pop()
            stack.append(c)
        elif c==')':
            while len(stack)>0 and stack[-1]!='(':
                result+=stack.pop()
            if len(stack)>0 and stack[-1]=='(':
                stack.pop()

while len(stack)>0:
    result+=stack.pop()

print(result)
