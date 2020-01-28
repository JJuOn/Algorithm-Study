num=[int(i) for i in input()]

def partition(left,right):
    low=left
    high=right+1
    pivot=num[left]
    while True:
        while True:
            low+=1
            if low>right or num[low] <= pivot:
                break
        while True:
            high-=1
            if high<left or num[high] >= pivot:
                break
        if low<high:
            temp=num[low]
            num[low]=num[high]
            num[high]=temp
        if low>=high:
            break
    temp=num[left]
    num[left]=num[high]
    num[high]=temp
    return high

def quickSort(left,right):
    if left<right:
        q=partition(left,right)
        quickSort(left,q-1)
        quickSort(q+1,right)


quickSort(0,len(num)-1)

for i in num:
    print(i,end="")