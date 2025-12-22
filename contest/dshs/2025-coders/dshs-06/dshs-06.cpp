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

int n, q;

int fuck[1005][1005] = {
    0,
};

void addFuck(int x, int y)
{
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
    {
      continue;
    }
    fuck[ny][nx]++;
  }
  fuck[y][x]++;
}

int getHigh(int floor)
{
  int mxVal = 0;
  int mxValIdx = 0;
  for (int i = 0; i < n; i++)
  {
    if (fuck[floor][i] > mxVal)
    {
      mxVal = fuck[floor][i];
      mxValIdx = i;
    }
  }
  return mxValIdx;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    int cmd;
    cin >> cmd;
    if (cmd == 1)
    {
      int x, y;
      cin >> y >> x;
      x--;
      y--;
      addFuck(x, y);
    }
    else
    {
      int row;
      cin >> row;
      row--;
      cout << getHigh(row) + 1 << '\n';
    }
  }

  int highFloor = 0;
  int highX = 0;
  int highVal = 0;
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
      if (fuck[y][x] > highVal)
      {
        highVal = fuck[y][x];
        highX = x;
        highFloor = y;
      }
    }

  // for (int y = 0; y < n; y++)
  // {
  //   for (int x = 0; x < n; x++)
  //   {
  //     cout << fuck[y][x] << " ";
  //   }
  //   cout << '\n';
  // }

  cout << highFloor + 1 << " " << highX + 1;
}
