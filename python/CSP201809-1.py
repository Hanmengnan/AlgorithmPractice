num = int(input())
price_before = list(map(int,input().split()))
print(price_before)
if len(price_before)==1:
    print(int(price_before[0]))
else:
    for i in range(len(price_before)):
        if i == 0 :
            print((int(price_before[i])+int(price_before[i+1]))//2,end = " ")
        elif i == len(price_before) - 1:
            
            print((int(price_before[i])+int(price_before[i-1]))//2,end = " ")
        else:
            print((int(price_before[i])+int(price_before[i+1])+int(price_before[i-1]))//3,end = " ")
