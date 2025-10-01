n = int(input())
s = list(map(int, input().split()))
t, p = map(int, input().split())

x = 0
for i in s:
    x += i // t
    if i % t > 0:
        x += 1

print(x)
print(*divmod(n, p))