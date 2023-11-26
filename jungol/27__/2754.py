n,k = map(int,input().split())
dp = [1]*(n+1)
for i in range(1,n+1):
    dp[i] = dp[i-1]*k
    if i>4:
        dp[i] -= dp[i-5]*2
    if i>6:
        dp[i] += dp[i-7]
    dp[i] %= 10**9+9
print(dp[n])