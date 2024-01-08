print("Введите целые числа (чтобы закончить ввод введите -1): ")
a = int(input())
b = int(input())
c = 0
d =-1
a1 = 0
b1 = 1
while (a != a1 or b != b1) and (a>a1 or b>b1):
    t = a1
    a1 = b1
    b1 = t + b1
if a!=a1 or b!=b1:
    d+=1
while c!=-1:
    c = int(input())
    if c!=a+b:
        d+=1
    a = b
    b = c
if d ==0:
    print("Последовательность Фибоначи")
else:
    print("Не последовательность Фибоначи")


