alphabets=['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']
num=""
inputStr=input()
for i in range(len(inputStr)):
    for j in range(len(alphabets)):
        if inputStr[i] in alphabets[j]:
            num+=str(j+1)
            break
result=0
for i in range(len(num)):
    result+=int(num[i])+2
print(result)

