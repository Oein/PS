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
  int a = 0;
  for (int i = 1; i <= 9; i++)
  {
    cout << "? A " << i << endl;
    int t;
    cin >> t;
    if (t == 1)
    {
      a = i;
      break;
    }
  }
  int b = 0;
  for (int i = 1; i <= 9; i++)
  {
    cout << "? B " << i << endl;
    int t;
    cin >> t;
    if (t == 1)
    {
      b = i;
      break;
    }
  }
  cout << "! " << a + b << endl;
}
