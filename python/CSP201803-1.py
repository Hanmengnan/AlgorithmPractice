jump=list(map(int,input().split()))
num=len(jump)
index=0
before=0
sum=0
while(jump[index]!=0):
    if jump[index]==1:
        sum+=jump[index]
    elif (index==0)or(jump[index]==2 and jump[index-1]==1):
        before=2
        sum+=before
    elif (jump[index]==2 and jump[index-1]==2):
        before+=2
        sum+=before
    index+=1
print(sum)