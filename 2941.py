crotian=['c=','c-','dz=','d-','lj','nj','s=','z=']
count=0
inputStr=input()
for c in crotian:
    if c in inputStr:
        count+=inputStr.count(c)
        inputStr=inputStr.replace(c,",")
count+=len(inputStr.replace(',',""))
print(count)