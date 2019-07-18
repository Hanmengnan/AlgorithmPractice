num=input()
sum=int(num[0])*1+int(num[2])*2+int(num[3])*3+int(num[4])*4+int(num[6])*5+int(num[7])*6+int(num[8])*7+int(num[9])*8+int(num[10])*9
if str(sum%11)==num[12] or (sum%11==10 and num[12]=="X"):
    print("Right")
else:
    if sum%11==10:
        num=list(num)
        num.pop()
        num.append("X")
        num="".join(num)
    else:
        num=list(num)
        num.pop()
        num.append(str(sum%11))
        num="".join(num)
    print(num)