"""
只有20分，活像个弟弟
"""
def caldis(t,k,bs):
    if t==0:
        return k
    else:
        return (bs+k)*(bs+k)



nm=list(map(int,input().split(" ")))
inf=float("inf")

dis=[inf]*(nm[0]+1)
pre=[0]*(nm[0]+1)
route=[[0]*(nm[0]+1) for i in range(nm[1])]
book=[0]*(nm[0]+1)


for i in range(1,nm[1]+1):
    eroute=list(map(int,input().split(" ")))
    route[eroute[1]][eroute[2]]=[eroute[0],eroute[3]]

for i in range(1,nm[0]+1):
    if route[1][i]!=0:
        dis[i]=route[1][i][1] if route[1][i][0]==0 else route[1][i][1]*route[1][i][1]
        if route[1][i][0]==1:
            pre[i]=pre[i]+route[1][i][1]
book[1]=1

for i in range(1,nm[0]+1):
    min=inf
    for j in range(1,nm[0]+1):
        if (book[j]==0 and dis[j]<min):
            u=j
            min=dis[j]
    book[u]=1
    for k in range(1,nm[0]+1):
        if route[u][k]!=0:
            temp=caldis(route[u][k][0],route[u][k][1],pre[u])
            #计算当前继续疲劳值
            if route[u][k][0]==0:
                #如果目前是大路
                if dis[k]>dis[u]+temp:
                    dis[k]=dis[u]+temp
                pre[k]=0
            else:
                if pre[u]==0:
                    #上一条路是大路
                    if dis[k]>dis[u]+temp:
                        dis[k]=dis[u]+temp
                        pre[k]=pre[u]+route[u][k][1]
                else:
                    #是小路
                    if dis[k]>temp:
                        dis[k]=temp
                        pre[k]=pre[u]+route[u][k][1]

print(dis[nm[0]])
