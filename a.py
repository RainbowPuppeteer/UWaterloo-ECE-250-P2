f1 = open("test.out", 'r')
f2 = open("out.out", 'r')

while f1:
    line1  = f1.readline()
    line2 = f2.readline()
    if line1 == "":
        break
    print(line1 == line2)

f1.close()
f2.close()