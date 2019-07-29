n=int(input())
vec=[]
for i in range(1001):
    vec.append(0)
num=list(map(int,input().split()))
for i in num:
    print(vec[i]+1,end=" ")
    vec[i]+=1
