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

typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos {
  int x;
  int y;
};

int arr[3] = {0,};
int sum = 0;
bool visited[1972][1972] = {0,};

Pos oper(Pos items) {
    if(items.x > items.y) {
        return {
            items.x - items.y,
            items.y * 2
        };
    } else {
        return {
            items.x * 2,
            items.y - items.x
        };
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> arr[0] >> arr[1] >> arr[2];
  sum = arr[0] + arr[1] + arr[2];


  queue<Pos> q;
    q.push({arr[0], arr[1]});
    visited[arr[0]][arr[1]] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();
        int a = cur.x;
        int b = cur.y;
        int c = sum - a - b;

        if(a == b && b == c) {
            cout << 1;
            return 0;
        }

        // F(A, B)

        Pos dt = oper({a, b});
        if(!visited[dt.x][dt.y]) {
            visited[dt.x][dt.y] = true;
            q.push({dt.x, dt.y});
        }

        // F(B, C)
        dt = oper({b, c});
        if(!visited[a][dt.x]) {
            visited[a][dt.x] = true;
            q.push({a, dt.x});
        }

        // F(A, C)
        dt = oper({a, c});
        if(!visited[dt.x][b]) {
            visited[dt.x][b] = true;
            q.push({dt.x, b});
        }
    }

    cout << 0;
}
