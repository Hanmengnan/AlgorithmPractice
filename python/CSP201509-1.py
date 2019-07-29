n=int(input())
num=list(map(int,input().split()))
pre=-1
sum=0
for i in num:
    if i!=pre:
        sum+=1
    pre=i
print(sum)
