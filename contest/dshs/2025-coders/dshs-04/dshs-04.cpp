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

map<char, vector<char>> ruleset;

bool checkRS(char a, char b)
{
  if (ruleset.find(a) == ruleset.end())
    return 1;

  for (char v : ruleset[a])
  {
    if (b == v)
      return 1;
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    char x;
    cin >> x;
    int cnt = 0;
    cin >> cnt;
    vector<char> rs;
    while (cnt--)
    {
      char y;
      cin >> y;
      rs.push_back(y);
    }
    ruleset[x] = rs;
  }

  string x;
  cin >> x;

  for (int i = 0; i < x.size() - 1; i++)
  {
    if (!checkRS(x[i], x[i + 1]))
    {
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
}
