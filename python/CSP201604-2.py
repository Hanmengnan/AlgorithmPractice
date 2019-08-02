"""
未完成
"""


pic=[]
block=[]
f_column=0
l_row=3
for i in range(15):
    pic.append(list(map(int,input().split())))
for i in range(4):
    block.append(list(map(int,input().split())))
n=int(input())
for i in range(4):
    if block[3-i]==[0,0,0,0]:
        l_row-=1
for i in range(4):
    if block[0][i]==0 and block[2][i]==0 and block[3][i]==0 and block[1][i]==0:
        f_column+=1
