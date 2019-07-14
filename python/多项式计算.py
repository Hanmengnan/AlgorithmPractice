def com(op1,op2):
    p1=["x","/"]
    p2=["+","-"]
    if (op1 in p1) and (op2 in p2):
        return True
    else:
        return False
def operate(operation,p1,p2):
    if operation=="x":
        return p1*p2
    elif operation=="/":
        return p2//p1
    elif operation=="+":
        return p1+p2
    else :
        return p2-p1


num=int(input())
opt={"+":{"+":1,"-":1,"x":0,"/":0},"-":{"+":1,"-":1,"x":0,"/":0},"x":{"+":1,"-":1,"x":1,"/":1},"/":{"+":1,"-":1,"x":1,"/":1}}
expression=[]

for i in range(num):
    expression.append(input())
for i in expression:
    letter=[]
    operation=[]
    c=list(i)
    panduan=0;
    for j in range(len(c)):
        if c[j].isdigit():
            if panduan==1:
                num_temp=letter.pop()
                letter.append(int(num_temp*10+int(c[j])))
            else:
                letter.append(int(c[j]))
            panduan=1
        else:
            if len(operation)==0:
                operation.append(c[j])
            elif (opt[operation[len(operation)-1]])[c[j]]==1:
                a=letter.pop()
                b=letter.pop()
                op=operation.pop()
                letter.append(operate(op,a,b))
                operation.append(c[j])
            else:
                operation.append(c[j])
            panduan=0
    while(len(operation)!=0):
        a=letter.pop()
        b=letter.pop()
        op=operation.pop()
        letter.append(operate(op,a,b))
    if int(letter[0])==24:
        print("Yes")
    else:
        print("No")