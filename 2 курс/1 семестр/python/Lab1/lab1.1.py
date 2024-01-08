year = int(input("Введите год: "))
if (year%100 ==0 and year%400 == 0) or (year%4==0 and year%100 !=0) :
    print("Год ", year, " високосный")
else:
    print("Год ", year, " не високосный")

