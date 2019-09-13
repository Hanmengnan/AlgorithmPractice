"""
我死了 运行错误 死活不知道报错在哪
"""
def tonode(b):
    flag=1
    for i in range(1,n+1):
        if route[b][i]==1:
            flag=0
            canget[b].append(i)
            tonode(i)
            for j in range(len(canget[i])):
                canget[b].append(canget[i][j])
            
    if flag==1:
        return 

def fromnode(b):
    flag=1
    for i in range(1,n+1):
        if route[i][b]==1:
            flag=0
            canbeget[b].append(i)
            fromnode(i)
            for j in range(len(canbeget[i])):
                canget[b].append(canbeget[i][j])
            
    if flag==1:
        return 

global n
n,m=list(map(int,input().split(" ")))
global canget,canbeget
global route
canget=[[] for i in range(n+1)]
canbeget=[[] for i in range(n+1)]
route=[[0]*(n+1) for i in range(n+1)]
sum=0
for i in range(m):
    b,e=list(map(int,input().split(" ")))
    route[b][e]=1

for i in range(1,n+1):
    tonode(i)
    fromnode(i)
for i in range(1,n+1):
    canget[i].append(i)
    temp=set(canget[i]+canbeget[i])
    if len(temp)==n:
        sum=sum+1
print(sum)