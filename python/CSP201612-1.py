n=int(input())
num=list(map(int,input().split()))
num.sort()
max=0
min=0
for i in num:
    if i>num[n//2]:
        max+=1
    elif i<num[n//2]:
        min+=1
if max==min:
    print(num[n//2])
else:
    print("-1")



