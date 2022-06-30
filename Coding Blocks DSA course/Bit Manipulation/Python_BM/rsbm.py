# // find the rightmost set bit mask

n = int(input())

rsbm = n & -n

print(bin(rsbm)[2::])