n=int(input())
count=0
for i in range(n):
    last={}
    isGroup=True
    inputStr=input()
    last[inputStr[0]]=0
    if len(inputStr)!=1:
        for j in range(1,len(inputStr)):
            if inputStr[j] in list(last.keys()):
                if j-last[inputStr[j]]>1:
                    isGroup=False
                    last[inputStr[j]]=j
                else:
                    last[inputStr[j]]=j
            else:
                last[inputStr[j]]=j
    if isGroup:
        count+=1
print(count)