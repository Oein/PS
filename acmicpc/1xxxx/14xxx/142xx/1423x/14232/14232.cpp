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

  ull n = 0;
  cin >> n;
  ull orig = n;
  vector<ull> factors;
  for (ull prime = 2; prime * prime <= orig; ++prime)
  {
    while (n % prime == 0)
    {
      factors.push_back(prime);
      n /= prime;
    }
  }

  if (factors.size() == 0)
  {
    cout << 1 << "\n"
         << orig << "\n";
    return 0;
  }

  if (n != 1)
  {
    factors.push_back(n);
  }

  cout << factors.size() << "\n";
  for (auto f : factors)
  {
    cout << f << " ";
  }
}
