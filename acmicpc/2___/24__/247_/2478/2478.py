import sys

# 입력부
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

# res : (뒤집는 시작점, 뒤집는 끝점, 두번째 왼쪽밀기의 정도)를 저장하는 리스트
res = []
for i in range(n - 1, 0, -1):
    # temp : 두번째 왼쪽밀기를 원래대로 되돌린 수열
    temp = arr[i : n] + arr[ : i]
    # cnt : 뒤집기가 가능한 수열의 크기
    cnt = 0
    # start : 뒤집기가 가능한 수열의 시작점
    start = -1
    for j in range(n - 1):
        # 현재 수가 1이 아니라면 1, 현재 수가 1이라면 n - 1의 차이가 나는 경우만 가능
        if (temp[j] - 1 > 0 and temp[j + 1] == temp[j] - 1) or (temp[j] - 1 == 0 and temp[j + 1] == n):
            cnt += 1
            # 시작점 갱신
            if start == -1:
                start = j
    # 뒤집기가 가능하면 저장
    if cnt > 0:
        res.append((start, cnt, i))
        
# 크기 순 정렬
res.sort(key=lambda x : (-(x[1] - x[0])))
# 두번째 왼쪽 밀기 이전으로 되돌림
arr = arr[res[0][2] : n] + arr[ : res[0][2]]
# 뒤집기 이전으로 되돌림
arr = arr[:res[0][0]] + arr[res[0][0] : res[0][1] + 1][::-1] + arr[res[0][1] + 1 : n]
# idx : 처음 왼쪽 밀기를 한 후 1의 인덱스
idx = arr.index(1)

# 정답출력
print(n - idx)
print(res[0][0] + 1, res[0][1] + 1)
print(n - res[0][2])