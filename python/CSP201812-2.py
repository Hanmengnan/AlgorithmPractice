def cal_time(index,time):
    if index==0:
        return 0
    else:
        if time[index][0]=="0":
            return int(time[index][1])+cal_time(index-1,time)
        elif time[index][0]=="1":
            last_time=cal_time(index-1,time)
            alltime=light_time[0]-int(time[index][1])+last_time
            spend=alltime%(light_time[0]+light_time[1]+light_time[2])

            if spend>light_time[0] and spend<=light_time[0]+light_time[2]:
                return last_time
            elif spend>light_time[0]+light_time[2]:
                return last_time+spend-(light_time[0]+light_time[1])
            else:
                return last_time+light_time[0]-spend

        elif time[index][0]=="2":
            last_time=cal_time(index-1,time)
            alltime=light_time[0]+light_time[1]+light_time[2]-int(time[index][1])+last_time
            spend=alltime%(light_time[0]+light_time[1]+light_time[2])

            if spend>light_time[0] and spend<=light_time[0]+light_time[2]:
                return last_time
            elif spend>light_time[0]+light_time[2]:
                return last_time+spend-(light_time[0]+light_time[1])
            else:
                return last_time+light_time[0]-spend
        elif time[index][0]=="3":
            last_time=cal_time(index-1,time)
            alltime=light_time[0]+light_time[2]-int(time[index][1])+last_time
            spend=alltime%(light_time[0]+light_time[1]+light_time[2])

            if spend>light_time[0] and spend<=light_time[0]+light_time[2]:
                return last_time
            elif spend>light_time[0]+light_time[2]:
                return last_time+spend-(light_time[0]+light_time[1])
            else:
                return last_time+light_time[0]-spend

global light_time
time=input().split(" ")
light_time=[0,0,0]
for i in range(len(time)):
    light_time[i]=int(time[i])
num=int(input())
time=[["0","0"]]
for i in range(num):
    temp=input().split(" ")
    time.append(temp)
print(cal_time(num,time))