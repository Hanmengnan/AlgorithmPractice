t = int(input())
ans = 0
for i in range(100, 200000, 100):
    temp = i - 3500
    if temp <= 0:
        ans = i
    elif temp <= 1500:
        ans = temp * 0.97 + 3500
    elif temp <= 4500:
        ans = (temp-1500)*0.9+1500*0.97+3500
    elif temp <= 9000:
        ans = (temp-4500)*0.8+3000*0.9+1500*0.97+3500
    elif temp <= 35000:
        ans = (temp-9000)*0.75+4500*0.8+3000*0.9+1500*0.97+3500
    elif temp <= 55000:
        ans = (temp-35000)*0.7+(35000-9000)*0.75++4500*0.8+3000*0.9+1500*0.97+3500
    elif temp <= 80000:
        ans = (temp-55000)*0.65+(55000-35000)*0.7+(35000-9000)*0.75++4500*0.8+3000*0.9+1500*0.97+3500
    elif temp >= 80000:
        ans = (temp-80000)*0.55+(80000-55000)*0.65+(55000-35000)*0.7+(35000-9000)*0.75+4500*0.8+3000*0.9+1500*0.97+3500
    if ans == t:
        print(i)
