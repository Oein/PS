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

// h, m, d, isNextDay
using Bus = pair<pair<int, int>, pair<int, int>>;

// a < b인지 검사
bool timeComp(Bus a, Bus b)
{
  return a.first <= b.first;
}

Bus getNextBus(Bus b)
{
  b.first.second += b.second.first;
  while (b.first.second >= 60)
  {
    b.first.second -= 60;
    b.first.first++;
  }

  return b;
}

void printT(int a)
{
  if (a < 10)
    cout << 0 << a;
  else
    cout << a;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int x, y;
  cin >> x >> y;
  int n;
  cin >> n;
  priority_queue<Bus, vector<Bus>, greater<Bus>> bus;
  vector<Bus> origBus;
  for (int i = 0; i < n; i++)
  {
    Bus b;
    cin >> b.first.first >> b.first.second >> b.second.first;
    b.second.second = i;
    origBus.push_back(b);
    bus.push(b);
  }

  bool isMyTime = false;
  pair<int, int> mt = {x, y};
  Bus mtb = {mt, {0, -1}};
  while (!bus.empty())
  {
    Bus b = bus.top();
    bus.pop();

    // cout << "CHECK " << b.first.first << " " << b.first.second << '\n';

    if (timeComp(mtb, b))
    {
      printT(b.first.first % 24);
      cout << ":";
      printT(b.first.second);
      return 0;
    }

    Bus nb = getNextBus(b);
    if (b.first.first <= 23 && nb.first.first >= 24)
    {
      Bus orig = origBus[b.second.second];
      orig.first.first += 24;
      bus.push(orig);
    }
    else
      bus.push(nb);
  }
}
