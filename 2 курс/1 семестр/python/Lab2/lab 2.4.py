with open("input1.txt","r") as file:
    line1 = file.read().split()
file.close()
size1 = len(line1)
with open("input2.txt","r") as file:
    line2 = file.read().split()
file.close()
size2 = len(line2)
with open("output1.txt", "w") as file:
    for i in range(size1):
        for j in range(size2):
            if (line1[i] == line2[j]):
                file.write(str(line1[i]) + " ")
                break
file.close()
with open("output1.txt", "r") as file:
    line = file.read().split()
    size = len(line)
k = 0
with open("output1.txt", "w") as file:
    for i in range(0,size):
        for j in range(i+1,size):
            if line[i] == line[j]:
                break
            else:
                k += 1
        if k == size - i -1:
            file.write(str(line[i]) + " ")
        k = 0
