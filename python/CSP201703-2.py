n=int(input())
m=int(input())
queue=list(range(1,n+1))
for i in range(m):
    temp=list(map(int,input().split()))
    index=queue.index(temp[0])
    queue.remove(temp[0])
    queue.insert(index+temp[1],temp[0])
for i in queue:
    print(i,end=" ")