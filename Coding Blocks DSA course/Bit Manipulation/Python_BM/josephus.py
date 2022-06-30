# Solving josephus problem using bit manipulation
# given a number n denoting the number of soldiers in circular manner... find the position that will survive till end
# the soldiers die in alternate fashion

# number of soldiers
n = int(input())

def gethp2(n):
    i = 1
    while(i*2 <= n):
        i = i*2
    return i


def getpos(n):
    hp2 = gethp2(n)
    l = n - hp2
    return 2*l+1

getpos(n)