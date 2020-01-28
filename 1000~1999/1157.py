BASE=65
string=input()
upperString=string.upper()
alphabets=[0 for i in range(26)]
for c in upperString:
    alphabets[ord(c)-BASE]+=1

maxNum=0
maxStr=""
for i in range(len(alphabets)):
    if alphabets[i]>maxNum:
        maxNum=alphabets[i]
        maxStr=chr(i+BASE)
    elif alphabets[i]!=0 and alphabets[i]==maxNum:
        maxStr="?"
print(maxStr)
