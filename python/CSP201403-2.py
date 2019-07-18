num=list(map(int,input().split()))
window=[]
window_index=[]
result=[]
for i in range(num[0]):
    window.append(list(map(int,input().split())))
    window_index.append(i+1)
window.reverse()
window_index.reverse()
for i in range(num[1]):
    position=list(map(int,input().split()))
    panduan=0
    for j in range(num[0]):
        if (position[0]>=window[j][0] and position[0]<=window[j][2]) and (position[1]>=window[j][1] and position[1]<=window[j][3]):
            temp=window[j]
            window.remove(temp)
            window.insert(0,temp)
            temp_index=window_index[j]
            result.append(temp_index)
            window_index.remove(temp_index)
            window_index.insert(0,temp_index)
            panduan=1
            break
    if panduan==0:
        result.append("IGNORED")
for i in range(num[1]):
    print(result[i])



