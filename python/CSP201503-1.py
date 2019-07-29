n=list(map(int,input().split()))
num=[]
for i in range(n[0]):
    num.append(list(map(int,input().split())))
for j in range(n[1]):
    for i in range(n[0]):
        print(num[i][n[1]-j-1],end=" ")
    print("")
