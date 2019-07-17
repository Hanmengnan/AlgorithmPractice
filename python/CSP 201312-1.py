a=int(input())
num=list(map(int,input().split()))
numset=set(num)
dict={}
maxnum=0
min=float("inf")
for i in numset:
    if maxnum<num.count(i):
        min=i
        maxnum=num.count(i)
    if max==num.count(i) and min>i:
        min=i
print(min)
