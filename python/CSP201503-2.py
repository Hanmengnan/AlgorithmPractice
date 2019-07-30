n=int(input())
num=[0 for i in range(1001) ]
number=list(map(int,input().split()))
for i in number:
    num[i]+=1
for i in range(1001-num.count(0)):
    m=max(num)
    ind=num.index(m)
    print(ind," ",m)
    num[ind]=0
