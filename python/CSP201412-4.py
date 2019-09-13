"""
prim 最小生成树 终于有一个100分的了
"""
n,m=list(map(int ,input().split()))
inf=float("inf")
sum=0
temp=[]
book=[0 for i in range(n+1)]
route=[[inf]*(n+1) for i in range(n+1)]
dis=[inf for i in range(n+1)]
for i in range(n+1):
    route[i][i]=0
for i in range(m):
    b,e,l=list(map(int ,input().split()))
    route[b][e]=l
    route[e][b]=l

for i in range(1,n+1):
    if(route[1][i]!=inf):
        dis[i]=route[1][i]
book[1]=1
while(len(temp)!=n-1):
        min=inf
        for i in range(1,n+1):
            if book[i]==0 and min>dis[i]:
                u=i
                min =dis[i]
        sum=sum+min
        book[u]=1
        temp.append(min)
        for j in range(1, n+1):
            if(book[j]==0 and dis[j]>route[u][j]):
                dis[j]=route[u][j]
        
print(sum)
