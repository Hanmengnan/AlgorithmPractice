"""
90分，勉强合格
"""
def caldis(dis,type,predis,pretype):
    if type==0:
        return 0,predis+dis
    else:
        if  pretype==0:
            return (pretype+dis),predis+(pretype+dis)*(pretype+dis)
        else:
            return (pretype+dis),(pretype+dis)*(pretype+dis)



global u
n,m=list(map(int,input().split(" ")))
inf=float("inf")

dis=[inf]*(n+1)

pretype=[0]*(n+1)
predis=[0]*(n+1)

route=[[inf]*(n+1) for i in range(n+1)]

book=[0]*(n+1)


for i in range(m):
    t,b,e,l=list(map(int,input().split(" ")))
    if route[b][e]==inf or route[b][e][0]>l:
        route[b][e]=route[e][b]=[l,t]

for i in range(n+1):
    if route[1][i]!=inf:
        
        _,d=caldis(route[1][i][0],route[1][i][1],0,0)
        dis[i]=d
        predis[i]=0
        pretype[i]=route[1][i][1]*route[1][i][0]

book[1]=1
u=0
for i in range(n+1):
    min=inf
    for j in range(1,n+1):
        if book[j]==0 and min>dis[j]:
            min=dis[j]
            u=j
    book[u]=1
    for j in range(1,n+1):
        if route[u][j]!=inf and book[j]==0:
            nowpretype,nowdis=caldis(route[u][j][0],route[u][j][1],dis[u],pretype[u])
            if dis[j]>nowdis:
                dis[j]=nowdis
                pretype[j]=nowpretype


print(dis[n])


