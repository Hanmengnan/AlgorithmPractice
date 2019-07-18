index=int(input())
num=list(map(int,input().split()))
i=0
sum=0

while(i<len(num)):
    if num.count(-1*num[i])!=0:
        sum+=num.count(-1*num[i])
        num[i]=0
        
    i+=1
print(sum)