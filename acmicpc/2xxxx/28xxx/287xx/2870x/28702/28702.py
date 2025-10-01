def main():
    a = input().rstrip()
    b = input().rstrip()
    c = input().rstrip()

    num = 0
    try:
        a = int(a)
        num = a + 3
    except:
        try:
            b = int(b)
            num = b + 2
        except:
            c = int(c)
            num = c + 1

    if num % 3 == 0 and num % 5 == 0:
        print("FizzBuzz")
        return
    if num % 3 == 0:
        print("Fizz")
        return
    if num % 5 == 0:
        print("Buzz")
        return
    print(num)
    
main()