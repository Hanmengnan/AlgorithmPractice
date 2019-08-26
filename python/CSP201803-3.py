

"""
只有90分，有一个测试点没有找到问题
"""

def fit(url,rule):
    paramter=[]
    if ("<path>" not in rule) and len(url)!= len(rule):
        return False ,None
    else :
        for i in range(len(rule)):
            if (rule[i]=="<int>"):
                if not (url[i].isdigit()):
                    return False ,None
                else:
                    if not (url[i]=="0"):
                        paramter.append(int(url[i]))
                    continue
            if (rule[i]=="<str>"):
                paramter.append(url[i])
                continue
            if (rule[i]=="<path>"):
                paramter.append("/".join(url[i:]))
                if(url[-1]=="/"):
                    paramter[-1]=paramter[-1][:-1]
                break
            else:
                if not (rule[i]==url[i]):
                    return False ,None
    return True,paramter



if __name__=="__main__":

    nm=list(map(int ,input().split(" ")))
    n=nm[0]
    m=nm[1]
    rule=[]
    result=[]
    printing=[]
    for i in range(n):
        rule_result=input().split(" ")
        result.append(rule_result[1])
        rule.append(list(filter(None,rule_result[0].split("/"))))
        if(rule_result[0][-1]=="/"):
            rule[-1].append("/")

    for i in range(m):
        temp=[]
        p=False
        url=input()
        temp=list(filter(None,url.split("/")))
        if(url[-1]=="/"):
            temp.append("/")
        for j in range(n):
            yn,r=fit(temp,rule[j])
            if (yn):
                p=True
                r.insert(0,result[j])
                printing.append(r)
                break
        if not(p):
            printing.append(["404"])
    for i in range(m):
        print(*printing[i])