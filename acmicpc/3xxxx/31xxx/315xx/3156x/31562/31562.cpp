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
  string name;
  char a;
  char b;
  char c;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, t;
  cin >> n >> t;
  vector<Pos> v(n);
  for (int i = 0; i < n; i++)
  {
    int len = 0;
    cin >> len >> v[i].name;
    cin >> v[i].a >> v[i].b >> v[i].c;
    for (int j = 0; j < 4; j++)
    {
      char ch;
      cin >> ch;
    }
  }

  for (int i = 0; i < t; i++)
  {
    char a, b, c;
    cin >> a >> b >> c;
    set<string> ans;
    for (int j = 0; j < n; j++)
    {
      if (v[j].a == a && v[j].b == b && v[j].c == c)
      {
        ans.insert(v[j].name);
      }
    }

    if (ans.size() == 0)
    {
      cout << "!\n";
    }
    else if (ans.size() == 1)
    {
      cout << *ans.begin() << "\n";
    }
    else
    {
      cout << "?\n";
    }
  }
}
