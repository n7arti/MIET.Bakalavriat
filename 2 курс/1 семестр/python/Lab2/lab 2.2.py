with open("students.txt", "r", encoding="utf8") as file:
    info = [int(n.split(';')[2].split()[0]) for n in file.readlines()]
    print(info)
    max = 0
    min = 10000
    count1 = 0
    count2 = 0
    size = len(info)
    for i in range(0, size):
        if int(info[i]) <= min:
            min = [i]
            count1 = i

for i in range(0, size):
    if int(info[i]) > max:
        max = info[i]
        count2 = i

with open("students.txt", "r", encoding="utf8") as file1:
    info = [m.split(';')[0] for m in file1.readlines()]
print("Самый старший студент: " + info[count1])
print("Самый младший студент: " + info[count2])