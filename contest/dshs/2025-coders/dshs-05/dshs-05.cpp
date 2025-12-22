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

struct Person
{
  int x;
  int y;
  int r;
  int a;
  int idx;
};

int team, robot;
vector<Person> people;
vector<Pos> balls;

int waniCnt = 0;

bool inDistance(Pos a, Pos b, int radius)
{
  double diff = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  return diff <= radius * radius;
}

bool calcBall(Pos b)
{
  for (Person p : people)
  {
    if (inDistance(b, {p.x, p.y}, p.r))
    {
      if (p.idx == 0)
        waniCnt++;
      return 1;
    }
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> team >> robot;

  for (int i = 0; i < team; i++)
  {
    Person p;
    cin >> p.x >> p.y >> p.r >> p.a;
    p.idx = i;
    people.push_back(p);
  }

  sort(people.begin(), people.end(), [](const Person a, const Person b)
       { return a.a > b.a; });

  bool lastWasSuc = true;
  for (int i = 0; i < robot; i++)
  {
    Pos p;
    cin >> p.x >> p.y;
    if (!lastWasSuc)
    {
      lastWasSuc = true;
      continue;
    }
    lastWasSuc = calcBall(p);
  }

  cout << waniCnt;
}
