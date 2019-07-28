N_and_K=list(map(int,input().split()))
key=list(range(1,N_and_K[0]+1))
time=[0 for i in range(41)]
for i in range(N_and_K[1]):
    temp=[]
    teacher=list(map(int,input().split()))
    b_time=teacher[1]
    r_time=teacher[1]+teacher[2]
    if type(time[b_time])==int:
        if time[b_time]==0:
            time[b_time]=-1*teacher[0]
        else :
            temp.append(time[b_time])
            temp.append(-1*teacher[0])
            temp.sort()
            time[b_time]=temp
    else:
        time[b_time].append(-1*teacher[0])
        time[b_time].sort()

    if type(time[r_time])==int:
        if time[r_time]==0:
            time[r_time]=teacher[0]
        else :
            temp.append(time[r_time])
            temp.append(teacher[0])
            temp.sort()
            time[r_time]=temp
    else:
        time[r_time].append(teacher[0])
        time[r_time].sort()
print(time)
for i in time:
    if type(i)==int:
        if i>0:
            for j in range(len(key)):
                if key[j]==0:
                    key[j]=i
                    break
        elif i<0:
            for j in range(len(key)):
                if key[j]==-1*i:
                    key[j]=0
                    break
    else:
        for item in i:
            if item>0:
                for j in range(len(key)):
                    if key[j]==0:
                        key[j]=item
                        break
        for item in i:
            if item<0:
                for j in range(len(key)):
                    if key[j]==-1*item:
                        key[j]=0
                        break
for i in key:
    print(i,end=" ")

