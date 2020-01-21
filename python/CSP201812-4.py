def cmp(elem):
    return elem[2]
def getfat(x):
    if(x==parent[x]):
        return x
    else:
        parent[x]=getfat(parent[x])
        return parent[x]

def exist(x,y):
    fx=getfat(x)
    fy=getfat(y)
    if(fx==fy):
        return True
    else:
        if fy>fx:
            parent[y]=x
        else:
            parent[x]=y
        return False
n=int(input())
m=int(input())
root=int(input())
parent=[(i) for i in range(n+1)]
inf=float("inf")
route=[]
minway=[]
for i in range(m):
    route.append(list(map(int,input().split(" "))))
route.sort(key=cmp)

for i in range(m):
    b,e,l=route.pop(0)
    if not (exist(b,e)):
        minway.append(l)

print(minway[-1])

    
