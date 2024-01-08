file = open("input.txt", "r")
line = file.readline().split()
x1,x2,x3,x4,x5,x6,x7,x8,x9,x10 = int(line[0]),int(line[1]),int(line[2]),int(line[3]),int(line[4]),int(line[5]),int(line[6]),int(line[7]),int(line[8]),int(line[9])
proiz = x1*x2*x3*x4*x5*x6*x7*x8*x9*x10
file.close()
file = open("output.txt","a")
file.write(str(proiz))
file.close()
