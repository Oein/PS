l = int(input())
d = input()

s = ""
cur = 0
def rm():
    global s, cur
    if cur == 0:
        return
    s = s[0:cur - 1] + s[cur:]
    cur -= 1
def put(char):
    global s, cur
    s = s[0:cur] + char + s[cur:]
    cur+=1
def l():
    global cur
    cur = max(cur - 1, 0)
def r():
    global cur
    cur = min(cur + 1, len(s))

c = 0

g = 0
for x in d:
    g += 1
    if x == '(':
        put('(')
    if x == ')':
        put(')')
    if x == '<':
        l()
    if x == '>':
        r()
    if x == 'X':
        rm()
    # print(cur)

    try:
        eval(s)
        print(f"SUC {s}")
        c = c ^ g
    except:
        print(f"FAIL {s}")
        pass

print(c)
        