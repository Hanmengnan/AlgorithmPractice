"""
因为使用python导致超时，只有85分
"""
def keysort(elem):
    return elem[2]
def getfat(t):
    if parent[t]==t:
        return t
    else:
        parent[t]=getfat(parent[t])
        return parent[t]
def merge(xf,yf):
    
    if xf==yf:
        return
    else:
        parent[xf]=yf

n,m=list(map(int ,input().split(" ")))
inf=float("inf")
parent=[i for i in range(0,n+1)]
route=[]
for i in range(m):
    route.append(list(map(int ,input().split(" "))))
route.sort(key=keysort)    

for i in range(m):
    mincost=route[i]
    xf=getfat(mincost[0])
    yf=getfat(mincost[1])
    merge(xf,yf)
    if getfat(1)==getfat(n):
        break
print(mincost[2])


