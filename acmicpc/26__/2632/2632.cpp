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

struct Pos {
  int x;
  int y;
};

vector<int> ASZ;
map<int, int> AMAP;

vector<int> BSZ;
// size: conut
map<int, int> BMAP;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, n, pizza;
  cin >> pizza >> m >> n;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    int sz;
    cin >> sz;
    sum += sz;
    ASZ.push_back(sz);
  }

  AMAP[sum] = 1;
  sum = 0;

  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    sum += sz;
    BSZ.push_back(sz);
  }
  BMAP[sum] = 1;

  for (int start = 0; start < m; start++) {
    sum = 0;
    for (int piece = 0; piece < (m - 1); piece++) {
      sum += ASZ[(start + piece) % m];
      if (AMAP.find(sum) == AMAP.end())
        AMAP[sum] = 0;
      AMAP[sum]++;

      // if (sum == pizza) {
      //   printf("A Able with %d ~ %d\n", start, start + piece);
      // }
    }
  }

  for (int start = 0; start < n; start++) {
    sum = 0;
    for (int piece = 0; piece < (n - 1); piece++) {
      sum += BSZ[(start + piece) % n];
      if (BMAP.find(sum) == BMAP.end())
        BMAP[sum] = 0;
      BMAP[sum]++;

      // if (sum == pizza) {
      //   printf("B Able with %d ~ %d\n", start, start + piece);
      // }
    }
  }

  int result = 0;

  result += AMAP[pizza];
  result += BMAP[pizza];

  // 섞어 만드는 경우
  auto iterA = AMAP.begin();
  while (iterA != AMAP.end()) {
    int pizzaA = iterA->first;
    int pizzaB = pizza - pizzaA;
    result += AMAP[pizzaA] * BMAP[pizzaB];
    // printf("APPEND %d(%d) %d(%d) %d\n", pizzaA, AMAP[pizzaA], pizzaB,
    //        BMAP[pizzaB], AMAP[pizzaA] * BMAP[pizzaB]);
    iterA++;
  }

  cout << result;
}
