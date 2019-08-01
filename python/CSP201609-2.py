n=int(input())
num=list(map(int,input().split()))
position=[[0]*5 for i in range(20)]
for index in range(len(num)):
    p=0
    for i in range(20):
        if num[index]<=position[i].count(0):
            p=1
            for j in range(num[index]):
                print((i)*5+j+1+position[i].index(0),end=" ")
            temp=position[i].index(0)
            
            for j in range(num[index]):
                position[i][temp+j]=1
            print("")
            break
    if p==0:
        for i in range(20):
            while position[i].count(0)!=0:
                po=position[i].index(0)
                position[i][po]=1
                num[index]-=1
                print(i*5+1+po,end=" ")
            if num[index]==0:
                break
