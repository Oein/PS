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

enum Status
{
  NOCHECK,
  CHECK_W,
  CHECK_H,
  CHECK_WH
};

i8 apdStatus(i8 orig, Status apd)
{
  if (apd == CHECK_W)
    return apd | 0b01;
  if (apd == CHECK_H)
    return apd | 0b10;
  if (apd == CHECK_WH)
    return apd | 0b11;
  return apd;
}

i8 checkStatus[25][25] = {
    0,
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int h, w;
  cin >> h >> w;

  vector<string> board;
  set<string> strset;

  for (int i = 0; i < h; i++)
  {
    string x;
    cin >> x;
    board.push_back(x);

    string wordMaking = "";
    bool isMakingWord = false;
    for (int j = 0; j < w; j++)
    {
      char c = x[j];
      if (isMakingWord)
      {
        if (c == '#')
        {
          if (wordMaking.size() >= 2)
          {
            // cout << "INS1 " << wordMaking << "\n";
            strset.insert(wordMaking);
          }
          wordMaking = "";
          isMakingWord = false;
          continue;
        }

        wordMaking += c;
        continue;
      }

      if (c == '#')
        continue;
      wordMaking = c;
      isMakingWord = true;
    }

    if (isMakingWord && wordMaking.size() >= 2)
    {
      // cout << "INS2 " << wordMaking << "\n";
      strset.insert(wordMaking);
    }
  }

  for (int i = 0; i < w; i++)
  {
    string wordMaking = "";
    bool isMakingWord = false;
    for (int j = 0; j < h; j++)
    {
      char c = board[j][i];
      if (isMakingWord)
      {
        if (c == '#')
        {
          if (wordMaking.size() >= 2)
          {
            // cout << "INS3 " << wordMaking << "\n";
            strset.insert(wordMaking);
          }
          wordMaking = "";
          isMakingWord = false;
          continue;
        }

        wordMaking += c;
        continue;
      }

      if (c == '#')
        continue;
      wordMaking = c;
      isMakingWord = true;
    }

    if (isMakingWord && wordMaking.size() >= 2)
    {
      // cout << "INS4 " << wordMaking << "\n";
      strset.insert(wordMaking);
    }
  }

  for (const string &s : strset)
  {
    cout << s << "\n";
    break;
  }
}
