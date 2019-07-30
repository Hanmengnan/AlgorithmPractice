n=int(input())
sum=[[0]*100 for i in range(100)]
num=0
for i in range(n):
    location=list(map(int,input().split()))
    for x in range(location[0],location[2]):
        print(x)
        for y in range(location[1],location[3]):
            sum[x][y]+=1
for i in range(100):
    for j in range(100):
        if sum[i][j]!=0:
            num+=1
print(num)
