n=int(input())
num=list(map(int,input().split()))
max=0

for i in range(1,n):
    temp=abs(num[i]-num[i-1])
    if temp>max:
        max=temp
print(max)