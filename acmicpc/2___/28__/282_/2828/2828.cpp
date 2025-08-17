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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, j;
  cin >> n >> m >> j;
  int lpos = 1;
  int cost = 0;
  // lpos부터 m칸 차지
  for (int i = 0; i < j; i++)
  {
    int a;
    cin >> a;

    // cout << "From " << lpos << " to " << a << endl;

    int rpos = lpos + m - 1;
    if (a <= rpos && lpos <= a)
    {
      // cout << "CONT " << lpos << " " << rpos << endl;
      continue;
    }
    if (rpos < a)
    {
      // cout << "REQ " << a - rpos << endl;
      cost += a - rpos;
      lpos = a - m + 1;
      // cout << "AT " << lpos << endl;
    }
    if (lpos > a)
    {
      // cout << "REQ " << lpos - a << endl;
      cost += lpos - a;
      lpos = a;
      // cout << "AT " << lpos << endl;
    }
  }

  cout << cost;
}
