# Count the number of set bits in a number

n = int(input())

count = 0

while n!=0:
    print(n)
    rsbm = n & -n
    n -= rsbm

    count+=1

print(count)
