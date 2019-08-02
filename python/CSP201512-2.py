n_and_k=list(map(int,input().split()))
condition=[[0]*n_and_k[1] for i in range(n_and_k[0])]
num=[]
for i in range(n_and_k[0]):
    num.append(list(map(int,input().split())))
for i in range(n_and_k[0]):
    for j in range(n_and_k[1]-2):
        if num[i][j]==num[i][j+1] and num[i][j]==num[i][j+2]:
            condition[i][j]=1
            condition[i][j+1]=1
            condition[i][j+2]=1
for i in range(n_and_k[0]-2):
    for j in range(n_and_k[1]):
        if num[i][j]==num[i+1][j] and num[i][j]==num[i+2][j]:
            condition[i][j]=1
            condition[i+1][j]=1
            condition[i+2][j]=1
for i in range(n_and_k[0]):
    for j in range(n_and_k[1]):
        if condition[i][j]==1:
            num[i][j]=0
        print(num[i][j],end=" ")
    print("")
