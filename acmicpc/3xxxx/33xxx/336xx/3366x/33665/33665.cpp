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

enum Owner
{
  NONE,
  SElF,
  OTHER
};

int w[10][5];

ll calcMoney(const vector<Owner> owner, const vector<bool> dambo, ll cash, Owner player, int a, int b)
{
  int cnt[10] = {0};
  int penaltyCnt = 0;

  for (int idx = 0; idx < 40; idx++)
  {
    if (owner[idx] == player)
    {
      cnt[idx / 4]++;
      if (dambo[idx])
      {
        penaltyCnt++;
      }
    }
  }

  ll ans = 0;
  for (int c = 0; c < 10; c++)
  {
    ans += w[c][cnt[c]];
  }

  ans += (cash * a) / 100;
  ans -= 1 * penaltyCnt * b;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 10; i++)
  {
    w[i][0] = 0;
    for (int j = 1; j <= 4; j++)
      cin >> w[i][j];
  }

  string ownStr, tradeStr, damboStr;
  cin >> ownStr >> tradeStr >> damboStr;

  ll moneySelf, moneyOther;
  cin >> moneySelf >> moneyOther;

  ll moneyTradeSelf, moneyTradeOther;
  cin >> moneyTradeSelf >> moneyTradeOther;

  int a, b;
  cin >> a >> b;

  vector<Owner> owner(40);
  vector<bool> dambo(40);
  for (int i = 0; i < 40; i++)
  {
    owner[i] = static_cast<Owner>(ownStr[i] - '0');
    dambo[i] = damboStr[i] - '0';
  }

  if (moneyTradeSelf > moneySelf || moneyTradeOther > moneyOther)
  {
    cout << "NO";
    return 0;
  }

  vector<Owner> ownerAfter = owner;
  bool valid = true;

  for (int i = 0; i < 40; i++)
  {
    char t = tradeStr[i];
    if (t == '1')
    {
      if (owner[i] != Owner::OTHER)
      {
        valid = false;
        break;
      }
      ownerAfter[i] = Owner::SElF;
    }
    else if (t == '2')
    {
      if (owner[i] != Owner::SElF)
      {
        valid = false;
        break;
      }
      ownerAfter[i] = Owner::OTHER;
    }
  }

  if (!valid)
  {
    cout << "NO";
    return 0;
  }

  ll beforeSelf = calcMoney(owner, dambo, moneySelf, Owner::SElF, a, b);
  ll beforeOther = calcMoney(owner, dambo, moneyOther, Owner::OTHER, a, b);

  ll afterCashSelf = moneySelf - moneyTradeSelf + moneyTradeOther;
  ll afterCashOther = moneyOther - moneyTradeOther + moneyTradeSelf;

  ll afterSelf = calcMoney(ownerAfter, dambo, afterCashSelf, Owner::SElF, a, b);
  ll afterOther = calcMoney(ownerAfter, dambo, afterCashOther, Owner::OTHER, a, b);

  cout << ((afterSelf - afterOther >= beforeSelf - beforeOther) ? "YES" : "NO");
}
