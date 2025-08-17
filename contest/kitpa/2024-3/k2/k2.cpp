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

int listSize = 0;

class LinkedList
{
public:
  int value = -1; // 0 = open, 1 = close
  bool amIroot = false;

  LinkedList *prev = nullptr;
  LinkedList *next = nullptr;

  LinkedList *insert(int nvalue, LinkedList **root)
  {
    listSize++;
    if (value == -1)
    {
      value = nvalue;
      return getNext();
    }
    // I have value
    LinkedList *nnode = new LinkedList();
    nnode->value = nvalue;
    if (this->prev != nullptr)
    {
      this->prev->next = nnode;
      nnode->prev = this->prev;
    }
    else
    {
      *root = nnode;
    }
    this->prev = nnode;
    nnode->next = this;
    return this;
  }
  LinkedList *getNext()
  {
    if (next != nullptr)
      return next;

    this->next = new LinkedList();
    this->next->prev = this;
    return this->next;
  }
  LinkedList *moveRight()
  {
    if (this->next == nullptr)
      return this;
    return this->next;
  }
  LinkedList *moveLeft()
  {
    if (this->prev == nullptr)
      return this;
    return this->prev;
  }
  LinkedList *deleteSelf(LinkedList **root)
  {
    if (this->prev == nullptr)
      return this;
    auto pprev = this->prev->prev;
    if (pprev == nullptr)
    {
      this->prev = nullptr;
      *root = this;
      return this;
    }
    pprev->next = this;
    this->prev = pprev;
    return this;
  }
};

LinkedList *cursor = new LinkedList();
LinkedList *root = cursor;

void printList()
{
  LinkedList *pc = root;
  while (pc != nullptr)
  {
    if (pc->value == -1)
      break;
    if (pc->value == 0)
      cout << "(";
    else
      cout << ")";
    pc = pc->next;
  }
}

bool isCorrectCheck()
{
  int opened = 0;
  LinkedList *pc = root;
  while (pc != nullptr)
  {
    if (pc->value == -1)
      break;
    if (pc->value == 0)
      opened++;
    else
    {

      opened--;
      if (opened < 0)
        return false;
    }
    pc = pc->next;
  }
  return opened == 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int q;
  cin >> q;

  string cmdstr;
  cin >> cmdstr;

  int c = 0;

  cursor->amIroot = true;

  bool wasLastCorrect = true;

  int opCnt = 0;
  int clCnt = 0;

  for (int i = 0; i < q; i++)
  {
    bool isCorrect = false;
    bool bypass = false;
    char cmd = cmdstr[i];
    switch (cmd)
    {
    case '(': // 현제 칸에 여는 괄호
      cursor = cursor->insert(0, &root);
      opCnt++;
      break;
    case ')': // 현제 칸에 닫는 괄호
      cursor = cursor->insert(1, &root);
      clCnt++;
      break;
    case 'X': // 현재칸 삭제
      if (cursor->prev != nullptr)
      {
        if (cursor->prev->value == 0)
          opCnt--;
        else if (cursor->prev->value == 1)
          clCnt--;
      }
      cursor = cursor->deleteSelf(&root);
      break;
    case '<': // 커서를 뒤로
      cursor = cursor->moveLeft();
      isCorrect = wasLastCorrect;
      bypass = true;
      break;
    case '>': // 커서를 앞으로
      cursor = cursor->moveRight();
      isCorrect = wasLastCorrect;
      bypass = true;
      break;
    default:
      break;
    }

    // cout << "===============\n";
    // cout << opCnt << " - " << clCnt << '\n';
    // printList();
    // cout << "\n";

    // 처음에 열지 않으면 false
    if (bypass)
    {
    }
    else
      isCorrect = isCorrectCheck();

    // check is correct
    // cout << "ISCR " << isCorrect << '\n';
    if (isCorrect)
      c ^= (i + 1);
    wasLastCorrect = isCorrect;

    // cout << c << '\n';
  }

  cout << c;
}