time=input().split(" ")
light_time=[0,0,0]
for i in range(len(time)):
    light_time[i]=int(time[i])
num=int(input())
sum=0
for i in range(num):
    temp=input().split(" ")
    if temp[0]=="0" or temp[0]=="1":
        sum+=int(temp[1])
    elif temp[0]=="2":
        sum+=int(temp[1])+int(light_time[0])
print(sum)
