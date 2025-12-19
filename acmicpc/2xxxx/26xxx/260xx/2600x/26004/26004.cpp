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

  string str;
  cin >> str >> str;
  int h = 0, i = 0, a = 0, r = 0, c = 0;
  for (char ch : str)
  {
    if (ch == 'H')
      h++;
    else if (ch == 'I')
      i++;
    else if (ch == 'A')
      a++;
    else if (ch == 'R')
      r++;
    else if (ch == 'C')
      c++;
  }
  cout << min(min(h, i), min(min(a, r), c)) << "\n";
}
