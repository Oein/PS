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
#include "4.h"

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

enum ARTIST
{
  HUMAN = 'h',
  GIANT = 'g',
  ELF = 'e',
};

string str;
int n, q;

class LinkedList
{
public:
  pair<ARTIST, int> data;
  int xStart;
  int xEnd;
  LinkedList *next;
  LinkedList *prev;

  void setData(pair<ARTIST, int> data)
  {
    this->data = data;
  }
  void setRange(int xStart, int xEnd)
  {
    this->xStart = xStart;
    this->xEnd = xEnd;
  }

  LinkedList()
  {
    this->next = nullptr;
    this->prev = nullptr;
  }

  LinkedList(pair<ARTIST, int> data, int xStart, int xEnd)
  {
    this->data = data;
    this->xStart = xStart;
    this->xEnd = xEnd;
    this->next = nullptr;
    this->prev = nullptr;
  }

  void combine()
  {
    bool reqRM = false;
    if (this->prev != nullptr)
    {
      if (this->prev->data.first == this->data.first)
      {
        this->prev->data.second += this->data.second;
        this->prev->xEnd = this->xEnd;
        this->prev->next = this->next;

        delete this;
      }
    }
    if (this->next != nullptr)
    {
      if (this->next->data.first == this->data.first)
      {
        this->data.second += this->next->data.second;
        this->xEnd = this->next->xEnd;
        LinkedList *next2Node = this->next->next;
        if (next2Node != nullptr)
          next2Node->prev = this;
        delete this->next;
        this->next = next2Node;
      }
    }
  }

  void insert(pair<ARTIST, int> data, int at)
  {
    assert(this->xStart <= at && at <= this->xEnd);

    if (this->xStart == at && this->xEnd == at)
    {
      this->data = data;
      this->combine();
      return;
    }
    if (this->xStart == at)
    {
      LinkedList *newNode = new LinkedList(data, at, at);
      this->xStart = at + 1;
      newNode->prev = this;
      newNode->next = this->next;
      this->prev->next = newNode;
      this->prev = newNode;
      this->data.second--;

      this->combine();

      return;
    }

    LinkedList *newNode = new LinkedList(data, at, at);
    this->xEnd = at - 1;
    this->data.second = at - this->xStart;

    LinkedList *next2Node = new LinkedList({this->data.first,
                                            this->data.second - (at - this->xStart)},
                                           at + 1, this->xEnd);

    newNode->prev = this;
    newNode->next = next2Node;
    next2Node->prev = newNode;
    next2Node->next = this->next;

    this->next = newNode;

    this->combine();
  }

  LinkedList *genNext()
  {
    this->next = new LinkedList();
    this->next->prev = this;
    return this->next;
  }

  void remove()
  {
    LinkedList *prevNode = this->prev;
    LinkedList *nextNode = this->next;
    if (prevNode != nullptr)
    {
      prevNode->next = nextNode;
    }
    if (nextNode != nullptr)
    {
      nextNode->prev = prevNode;
    }
    delete this;
  }
};

LinkedList link;

void printLinkedList()
{
  cout << "====================\n";
  LinkedList *pcu = &link;
  while (pcu != nullptr)
  {
    cout << (char)pcu->data.first << " (Count)" << pcu->data.second << " (st)" << pcu->xStart << " (ed)" << pcu->xEnd << '\n';
    pcu = pcu->next;
  }
}

void rmain()
{
  int x, s, e;
  char v;
  cin >> x >> v >> s >> e;

  LinkedList *cur = &link;
  // Move until xStart <= x < xEnd
  while (!(cur->xStart <= x && x <= cur->xEnd))
  {
    cur = cur->next;
  }
  if (cur == nullptr)
  {
    assert(false);
  }
  if (cur->data.first != (ARTIST)v)
  {
    cur->insert({(ARTIST)v, 1}, x);
  }

  // printLinkedList();

  // Move until xStart <= s < xEnd
  cur = &link;
  while (!(cur->xStart <= s && s <= cur->xEnd))
  {
    cur = cur->next;
  }

  int elfCnt = 0;
  int giantCnt = 0;

  while (!(cur->xStart <= e && e <= cur->xEnd))
  {
    if (cur->data.first == ELF)
    {
      int add = min(cur->data.second, e - cur->xStart + 1);
      // s
      add = max(add, s - cur->xStart + 1);
      elfCnt += add;
    }
    else if (cur->data.first == GIANT)
    {
      int add = min(cur->data.second, e - cur->xStart + 1);
      // s
      add = max(add, s - cur->xStart + 1);
      giantCnt += add;
    }
    else
    {
      // humman
      cout << "ELF: " << elfCnt << " GIANT: " << giantCnt << '\n';
      elfCnt = 0;
      giantCnt = 0;
    }
    cur = cur->next;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q >> str;

  // calcLinkedList

  char LASTCHAR = str[0];
  int artistCnt = 1;
  int rm = 0;
  set<int> rmtest;
  vector<pair<ARTIST, int>> artistGroup;

  LinkedList *cur = &link;

  for (int i = 1; i < n; i++)
  {
    char c = str[i];

    if (c == LASTCHAR)
    {
      artistCnt++;
      continue;
    }
    else
    {
      cur->setData({(ARTIST)LASTCHAR, artistCnt});
      cur->setRange(i - artistCnt + 1, i);
      cur = cur->genNext();
      artistCnt = 1;
      LASTCHAR = c;
    }
  }
  cur->setData({(ARTIST)LASTCHAR, artistCnt});
  cur->setRange(n - artistCnt + 1, n);

  // printLinkedList
  // printLinkedList();

  for (int i = 0; i < q; i++)
  {
    cout << "==================\n";
    rmain();
  }
}
