#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>
#include <climits>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

using namespace std;

int n, q;
struct V2
{
  ull height;
  ull ypos;
};
vector<V2> rects(400005);
ull elemsize = 0;

void process1(int lloc, ull h)
{
  lloc--;
  for (int i = elemsize; i > lloc; i--)
  {
    rects[i] = rects[i - 1];
    rects[i].ypos += h;
  }
  rects[lloc].height = h;
  if (lloc != 0)
  {
    rects[lloc].ypos = rects[lloc - 1].ypos + rects[lloc - 1].height;
  }
  elemsize++;
}

void process2(ull loc)
{
  ull rm = rects[loc].height;
  for (int i = loc; i < elemsize - 1; i++)
  {
    rects[i] = rects[i + 1];
    rects[i].ypos -= rm;
  }
  elemsize--;
}

void printList()
{
  for (int i = 0; i < elemsize; i++)
  {
    cout << "<" << rects[i].height << ",y" << rects[i].ypos << "> ";
  }
  cout << "\n";
}

void process3()
{
  ull t, b;
  cin >> t >> b;

  // cout << "==========\n";
  // printList();

  ull st_st = 0;
  ull st_ed = elemsize;
  while (st_st + 1 < st_ed)
  {
    ull mid = (st_st + st_ed) / 2;
    // cout << st_st << " ~ " << st_ed << " -> " << mid << "\n";
    if (rects[mid].ypos > t)
      st_ed = mid;
    else
      st_st = mid;
  }

  // cout << "---\n";

  ull ed_st = 0;
  ull ed_ed = elemsize;
  while (ed_st + 1 < ed_ed)
  {
    ull mid = (ed_st + ed_ed) / 2;
    // cout << ed_st << " ~ " << ed_ed << " -> " << mid << "\n";
    if (rects[mid].ypos > b)
      ed_ed = mid;
    else
      ed_st = mid;
  }

  // cout << st_st << " t " << ed_st << "\n";

  while (true)
  {
    if (rects[st_st].ypos + rects[st_st].height <= t)
    {
      st_st++;
      if (st_st == elemsize)
      {
        cout << 0 << "\n";
        return;
      }
    }
    else
      break;
  }

  while (true)
  {
    if (rects[ed_st].height >= b)
    {
      ed_st--;
      if (ed_st == -1)
      {
        cout << 0 << "\n";
        return;
      }
    }
    else
      break;
  }

  // cout << st_st << " tx " << ed_st << "\n";
  cout << ed_st - st_st + 1 << '\n';
}

struct CommandQItem
{
  bool t;
  ull arg1, arg2;
};
vector<CommandQItem> cq;

ull nwk = 0;

void process()
{
  int t;
  cin >> t;
  if (t == 1)
  {
    ull a, b;
    cin >> a >> b;
    cq.push_back({0, a, b});
    nwk++;
  }
  if (t == 2)
  {
    ull c;
    cin >> c;
    cq.push_back({1, c, 0});
    nwk--;
    if (nwk == 0)
    {
      cq.clear();
      elemsize = 0;
    }
  }
  if (t == 3)
  {
    vector<int> rmq;
    for (int i = 0; i < cq.size(); i++)
    {
      CommandQItem qf = cq[i];
      if (qf.t == 0)
      {
        process1(qf.arg1, qf.arg2);
      }
      else
      {
        rmq.push_back(qf.arg1);
      }
    }
    cq.clear();

    process3();
  }
  // printList();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  elemsize = n;
  nwk = n;
  ull h = 0;
  for (int i = 0; i < n; i++)
  {
    ull data = 0;
    cin >> data;
    rects[i] = {
        data,
        h};
    h += data;
  }

  while (q--)
  {
    process();
  }
}
