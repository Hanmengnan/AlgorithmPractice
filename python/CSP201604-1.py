n=int(input())
num=list(map(int,input().split()))
sum=0
for i in range(1,n-1):
    if (num[i]>num[i+1] and num[i]>num[i-1]) or (num[i]<num[i+1] and num[i]<num[i-1]):
        sum+=1
print(sum)
