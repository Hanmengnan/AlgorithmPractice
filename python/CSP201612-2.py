n=int(input())
if n>3500:
    if n<5000:
        print(int(n-((n-3500)*0.03)))
    elif n<8000:
        print(int(n-((n-5000)*0.1+45)))
    elif n<12500:
        print(int(n-((n-8000)*0.2+45+300)))
    elif n<38500:
        print(int(n-((n-12500)*0.25+45+300+400)))
    elif n<58500:
        print(int(n-((n-38500)*0.3+45+300+400+6500)))
    elif n<83500:
        print(int(n-((n-58500)*0.35+45+300+400+6500+6000)))
    else:
        print(int(n-((n-83500)*0.45+45+300+400+6500+6000+8750)))
else:
    print(n)
