import copy
def out(num,k):
    if num%10==k or num%k==0:
        return True
    else:
        return False
n_and_k=list(map(int,input().split()))
queue=[]
index=1
queue=list(range(1,n_and_k[0]+1))

while len(queue)!=1:
    temp_queue=copy.copy(queue)
    for i in range(len(queue)):
        if out(index,n_and_k[1]):
            temp_queue.remove(queue[i])
        index+=1
        if (len(temp_queue)==1):
            break
    queue=copy.copy(temp_queue)
print(queue[0])