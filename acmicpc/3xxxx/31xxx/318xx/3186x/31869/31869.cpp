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
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
  int x;
  int y;
};

int n;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  map<string, int> money;
  // date, name, req money
  vector<pair<int, pair<string, int>>> resv;
  for (int i = 0; i < n; i++)
  {
    string name;
    int d1, d2, reqMoney;
    cin >> name >> d1 >> d2 >> reqMoney;
    resv.push_back({d1 * 7 + d2, {name, reqMoney}});
  }
  for (int i = 0; i < n; i++)
  {
    string name;
    int moneyx;
    cin >> name >> moneyx;
    money[name] = moneyx;
  }
  sort(resv.begin(), resv.end());

  map<int, bool> caneat;
  for (int i = 0; i < n; i++)
  {
    if (money[resv[i].second.first] >= resv[i].second.second)
      caneat[resv[i].first] = true;
  }

  int ans = 0;
  int currentStreak = 0;
  int lastDate = -1;
  for (auto resv : caneat)
  {
    int date = resv.first;
    bool canEat = resv.second;

    if (!canEat)
    {
      ans = max(ans, currentStreak);
      currentStreak = 0;
      lastDate = date;
      continue;
    }

    if (currentStreak == 0)
    {
      currentStreak = 1;
    }
    else
    {
      if (date == lastDate + 1)
        currentStreak++;
      else
      {
        ans = max(ans, currentStreak);
        currentStreak = 1;
      }
    }

    lastDate = date;
  }
  ans = max(ans, currentStreak);
  cout << ans << "\n";
}
