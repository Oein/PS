import sys
input = sys.stdin.readline

U,N = map(int,input().split())
price2names = [[] for _ in range(10001)]
personCnt = [0 for _ in range(10001)]
minCnt = 10001
for _ in range(N):
    name, price = input().split()
    price = int(price)
    price2names[price].append(name)
    personCnt[price] += 1
for i in range(10001): 
    if personCnt[i] != 0:
        minCnt = min(personCnt[i], minCnt)
for i in range(10001):
    if minCnt == personCnt[i]:
        print(price2names[i][0],i)
        break