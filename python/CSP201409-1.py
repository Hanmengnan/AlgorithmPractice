n=int(input())
num=list(map(int,input().split()))
sum=0
for i in range(n):
    for j in range(n):
        if num[j]==num[i]+1:
            sum+=1
print(sum)
