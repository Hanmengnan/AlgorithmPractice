n=int(input())
position=[]
for i in range(n):
    position.append(list(map(int,input().split())))
x=0
y=0
p=0
d=0
print(position[y][x],end=" ")
while True:
    
    if x==n-1 and y==n-1:
        break
    else:
        if y==n-1 and x==0:
            if n%2==0:
                p=0
            else:
                p=2
            d=1
        if p==0:
            x+=1
            print(position[y][x],end=" ")
            p=2
        elif p==1:
            y+=1
            print(position[y][x],end=" ")
            p=3
        elif p==2:
            temp_y=x
            temp_x=y
            while True:
                if x==temp_x and y==temp_y:
                    break
                if d==0:
                    x-=1
                    y+=1
                else:
                    x+=1
                    y-=1
                print(position[y][x],end=" ")
            p=1
        else:
            temp_y=x
            temp_x=y
            while True:
                if x==temp_x and y==temp_y:
                    break
                if d==1:
                    x-=1
                    y+=1
                else:
                    x+=1
                    y-=1
                print(position[y][x],end=" ")
            p=0




