import random

path = input("Enter the path:\n")
numberOfFiles = int(input("Enter number of txts you want to create:\n"))
# quantity = int(input("Enter quantity of numbers you want to write:\n"))
limit = 100
number = "1"
quantity = 1000
txt = "\\Samples"
dotTxt = ".txt"
for j in range(numberOfFiles):

    file = open(path + txt + number + dotTxt, "w")
    for i in range(quantity):
        a = random.randint(0, limit)
        file.write(str(a) + " ")
    number = str(int(number) + 1)
    if limit < 10000000:
        limit = limit * 10*4 * (j+1)
    quantity = quantity + 5000
