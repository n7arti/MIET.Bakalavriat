for i in range(101,10000):
    t = 0
    res = 0
    number = i
    number2 = i
    while i!=0:
        i = i//10
        t+=1
    for k in range(1,t+1):
        res += (number%10)**t
        number = number//10
    if res == number2:
        print(res)





