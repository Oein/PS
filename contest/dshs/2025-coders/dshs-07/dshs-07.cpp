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
vector<int> l;
bool finalAns = 0;

int n;

void checkSumi()
{

  for (int t = 1; t <= n / 2; t++)
  {
    // t개를 체크
    bool ok = true;
    for (int check = 0; check < t; check++)
    {
      int li = check;
      int ri = n - t + check;

      int lVal = l[li];
      if (lVal == 0)
        lVal = 1;
      int rVal = l[ri];
      if (rVal == 0)
        rVal = 1;
      if (lVal != rVal)
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      return;
    }
  }

  assert(false);
}

vector<int> zidx;

void resetL()
{
  for (int idx : zidx)
    l[idx] = 0;
}

void getAnsYes()
{
  vector<int> unsettens;
  for (int size = 1; size <= n / 2; size++)
  {

    // sumi를 만들기 위해 시도
    bool ableToMake = true;
    for (int i = 0; i < size; i++)
    {
      int makeL = i;
      int makeR = n - size + i;

      int dataL = l[makeL];
      int dataR = l[makeR];

      if (dataL == 0 && dataR == 0)
      {
        l[makeL] = 1;
        l[makeR] = 1;
      }
      else if (dataL == 0 && dataR != 0)
      {
        l[makeL] = dataR;
      }
      else if (dataL != 0 && dataR == 0)
      {
        l[makeR] = dataL;
      }
      else if (dataL != dataR) // data != 0
      {
        // ㅈ뎀
        ableToMake = false;
        break;
      }
    }

    if (ableToMake)
    {
      checkSumi();
      for (auto val : l)
      {
        if (val == 0)
          cout << "1 ";
        else
          cout << val << " ";
      }
      return;
    }

    resetL();
  }
}

void getAnsNo()
{
  vector<int> unusedNum;
  bool used[20005] = {
      0,
  };
  for (int i = 0; i < n; i++)
  {
    used[l[i]] = 1;
  }
  for (int i = 1; i <= 2000; i++)
  {
    if (!used[i])
      unusedNum.push_back(i);
  }

  int acs = 0;
  for (int val : l)
  {
    if (val != 0)
      cout << val << " ";
    else
    {
      cout << unusedNum[acs] << " ";
      acs = (acs + 1) % unusedNum.size();
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    l.push_back(x);
    if (x == 0)
      zidx.push_back(i);
  }
  string nx;
  cin >> nx;
  if (nx[0] == 'y')
    finalAns = 1;

  if (finalAns == 0)
  {
    getAnsNo();
  }
  else
    getAnsYes();
}
