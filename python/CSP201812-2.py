r,y,g=input().split()
r,y,g=int(r),int(y),int(g)
n=int(input())
time=0
#
#
#该函数用来计算某一个灯等待了time秒后的灯需要等多少秒才可以走
#返回一个等待时间的数值
#先计算好四种情况：
#1.绿灯3时，直接过。
#2.红灯1时，需要等红灯剩余秒数t。
#3.黄灯2时，需要等黄灯剩余秒数t以及红灯秒数r。
#4.一段道路0时，时间加上t。
def changeLi(k,t,time):
    if k==0:
        return t
    #如果是红灯
    if k==1:
        #如果等待的秒数小于红灯现有秒数
        if time<t:
            return t-time
        #如果大于红灯现有秒数,递归调用本函数，看作是绿灯情况下还剩time-t秒
        else:
            return changeLi(3,g,time-t)
    #以下情况类似
    if k==2:
        if time<t:
            return t-time+r
        else:
            return changeLi(1,r,time-t)
    if k==3:
        if time<t:
            return 0
        else:
            return changeLi(2,y,time-t)
#
#
for i in range(n):
    k,t=input().split()
    k,t=int(k),int(t)
    tt=time%(r+y+g)        #用tt表示每个灯取余后等的秒数
    time+=changeLi(k,t,tt)
print(time)
 