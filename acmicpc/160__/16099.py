a = int(input())

def main():
    a,b,c,d = map(int, input().split())
    if a * b > c * d:
        print("TelecomParisTech")
    elif a * b < c * d:
        print("Eurecom")
    else:
        print("Tie")

while a > 0:
    a -= 1
    main()