#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f LLONG_MAX >> 1

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

struct Note
{
  int l, t, r;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  int x;
  cin >> n >> x;

  vector<Note> notes(n);
  int musicEndsAt = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> notes[i].l >> notes[i].t >> notes[i].r;
    musicEndsAt = max(musicEndsAt, notes[i].r);
  }

  vector<vector<ll>> dp(2, vector<ll>(musicEndsAt + 1, zx3f));
  vector<vector<int>> backtrack(n, vector<int>(musicEndsAt + 1, 0));

  for (int t = notes[0].l; t <= notes[0].r; ++t)
  {
    dp[0][t] = abs(t - notes[0].t);
  }

  for (int i = 1; i < n; ++i)
  {
    int acc = i % 2;
    int acp = (i - 1) % 2;

    for (int i = 0; i < dp[0].size(); i++)
      dp[acc][i] = zx3f;

    vector<ll> sum(musicEndsAt + 1, zx3f);
    vector<int> backtrack_now(musicEndsAt + 1, 0);

    sum[0] = dp[acp][0];
    backtrack_now[0] = 0;
    for (int t = 1; t <= musicEndsAt; ++t)
    {
      if (dp[acp][t] < sum[t - 1])
      {
        sum[t] = dp[acp][t];
        backtrack_now[t] = t;
      }
      else
      {
        sum[t] = sum[t - 1];
        backtrack_now[t] = backtrack_now[t - 1];
      }
    }

    for (int t = notes[i].l; t <= notes[i].r; ++t)
    {
      int lt = t - x;
      if (lt < 0)
        continue;

      ll lcost = sum[lt];
      if (lcost == zx3f)
        continue;

      dp[acc][t] = abs(t - notes[i].t) + lcost;
      backtrack[i][t] = backtrack_now[lt];
    }
  }

  ll ans = zx3f;
  int lastPlayAt = -1;
  int last_idx = (n - 1) % 2;

  for (int t = notes[n - 1].l; t <= notes[n - 1].r; ++t)
  {
    if (dp[last_idx][t] < ans)
    {
      ans = dp[last_idx][t];
      lastPlayAt = t;
    }
  }

  if (lastPlayAt == -1)
  {
    cout << -1 << "\n";
    return 0;
  }

  cout << ans << "\n";
  vector<int> res_path(n);
  res_path[n - 1] = lastPlayAt;
  for (int i = n - 1; i > 0; --i)
  {
    res_path[i - 1] = backtrack[i][res_path[i]];
  }
  for (int i = 0; i < n; ++i)
  {
    cout << res_path[i] << (i == n - 1 ? "" : " ");
  }

  return 0;
}