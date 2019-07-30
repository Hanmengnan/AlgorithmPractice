run=[31,29,31,30,31,30,31,31,30,31,30,31]
no_run=[31,28,31,30,31,30,31,31,30,31,30,31]
year=int(input())
day=int(input())
if year%400==0 or (year%4==0 and year%100!=0):
    for index in range(len(run)):
        if day<=run[index]:
            break
        day=day-run[index]
    print(index+1)
    print(day)
else:
    for index in range(len(no_run)):
        if day<=no_run[index]:
            break
        day=day-no_run[index]
    print(index+1)
    print(day)