
num=int(input())
Htime=[]
Wtime=[]

for i in range(num):
    time1=input().split(" ")
    b=int(time1[0])
    e=int(time1[1])
    for i in range(b,e):
        Htime.append(i)

for i in range(num):
    time2=input().split(" ")
    b=int(time2[0])
    e=int(time2[1])
    for i in range(b,e):
        Htime.append(i)

print(len(Htime)+len(Wtime)-len(set(Htime).union(set(Wtime))))                                       
