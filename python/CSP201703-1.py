N_and_K=list(map(int,input().split()))
num=list(map(int,input().split()))
sum=0
temp=0
for i in num:
    temp+=i
    if temp>=N_and_K[1]:
        sum+=1
        temp=0
if temp!=0:
    sum+=1
print(sum)