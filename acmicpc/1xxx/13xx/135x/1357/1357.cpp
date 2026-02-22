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

  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int aint = stoi(a);
  int bint = stoi(b);
  int res = aint + bint;
  string ress = to_string(res);
  reverse(ress.begin(), ress.end());
  bool zeroComing = true;
  for (int i = 0; i < ress.size(); i++)
  {
    if (ress[i] == '0' && zeroComing)
      continue;
    zeroComing = false;
    cout << ress[i];
  }
  if (zeroComing)
    cout << 0;
}
