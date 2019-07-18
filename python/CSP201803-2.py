def position_same(position,direction,len):
    for i in range(len):
        for j in range(i+1,len):
            if position[i]==position[j] and direction[i] !=direction[j]:
                direction[i] = not direction[i]
                direction[j] = not direction[j]
    return direction
data=list(map(int,input().split()))
position=list(map(int,input().split()))
direction=[]
for i in range(data[0]):
    direction.append(True)
for time in range(data[2]):
    direction=position_same(position,direction,data[0])
    for i in range(data[0]):
        if direction[i]==True:
            position[i]+=1
        else:
            position[i]-=1
        if position[i]==data[1] or position[i]==0:
           direction[i]=not direction[i]
        
for i in range(data[0]):
    print(position[i],end=" ")