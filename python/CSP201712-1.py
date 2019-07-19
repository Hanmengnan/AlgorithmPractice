n=int(input())
num=list(map(int,input().split()))
min=float("inf")
for i in range(len(num)):
    for j in range(i+1,len(num)):
        temp=abs(num[i]-num[j])
        if temp<min:
            min=temp
print(min)