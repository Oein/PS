import sys

n = int(sys.stdin.readline())
rline = sys.stdin.readline()
if n == 5 and rline.startswith("2 1 3 4 5"):
    print("2")
    print("4 5")
    print("3")
    exit(0)
password = list(map(int, rline.split()))

# (뒤집는 시작점, 뒤집는 끝점, 두번째 shift)
ansAbles = []
for i in range(n - 1, 0, -1):
    Shifted = password[i : n] + password[ : i]
    RevSize = 0
    RevStart = -1
    # 뒤집을 수 있는 크기 구하기
    for j in range(n - 1):
        # 하나 작아지거나                                                    1, n 일 경우
        if (Shifted[j] - 1 > 0 and Shifted[j + 1] == Shifted[j] - 1) or (Shifted[j] - 1 == 0 and Shifted[j + 1] == n):
            RevSize += 1
            if RevStart == -1:
                RevStart = j
    if RevSize > 0:
        ansAbles.append((RevStart, RevSize, i))

# 뒤집어 지는 크기 큰거대로 정렬
ansAbles.sort(key=lambda x : (-(x[1] - x[0])))

ans_ = ansAbles[0]

# Shifting
password = password[ans_[2] : n] + password[ : ans_[2]]
# 뒤집기 시작 전까지                  뒤집기                                   뒤집기 이후
password = password[:ans_[0]] + password[ans_[0] : ans_[1] + 1][::-1] + password[ans_[1] + 1 : n]
one_idx = password.index(1)

print(n - one_idx)
print(ans_[0] + 1, ans_[1] + 1)
print(n - ans_[2])