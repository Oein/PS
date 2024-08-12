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
using namespace std;

vector<int> a;
vector<int> b;

#define pvv pair<vector<int>, vector<int>>
#define pvvt pair<pvv, int>
#define pii pair<int, int>

set<pvv> s;

bool isAllDone(pvv a) {
  for (int i = 0; i < a.first.size(); i++)
    if (a.first[i] != a.second[i])
      return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  set<int> ign;
  for (int i = 0; i < n; i++) {
    int q, w;
    cin >> q >> w;
    a.push_back(q);
    b.push_back(w);
    if (a == b)
      ign.insert(q);
  }
  if (ign.size() == n) {
    cout << 0;
    return 0;
  }
  ign.clear();

  a.push_back(0);
  b.push_back(0);

  queue<pvvt> q;
  q.push({{a, b}, 0});
  s.insert({a, b});

  while (!q.empty()) {
    pvvt qf = q.front();
    q.pop();
    if (isAllDone(qf.first)) {
      cout << qf.second;
      return 0;
    }

    // cout << qf.second << " =================\n";
    // for(auto x : qf.first.first) cout << x << " ";
    // cout << "\n";
    // for(auto x : qf.first.second) cout << x << " ";
    // cout << "\n";

    map<int, int> bottom2index;
    map<int, int> top2index;
    // 천장의 index 두개가 들어 갈거임
    vector<pii> twoEmpty;
    vector<pii> oneMove;
    int emptyLoc = -1;
    bool movedbt = false;
    for (int i = 0; i < n + 1; i++) {
      int upValue = qf.first.first[i];
      int downValue = qf.first.second[i];

      // 완전 빈곳인경우
      if (upValue == 0 && downValue == 0) {
        emptyLoc = i;
      }

      // 하나는 아래, 천장이 뚫려있는 경우
      if (upValue == 0 && downValue != 0) {
        // 하나는 아래, 다른것도 아래에 서로 천장이 뚫려있는 경우
        if (bottom2index.find(downValue) != bottom2index.end()) {
          // 전에 발견된 것을 자신에 위에 배치
          // 전에 발견된 곳을 empty로 표시
          // 둘다 천장이 있기 때문에 어디에 놓든 무방함.
          qf.first.first[i] = downValue;
          qf.first.second[bottom2index[downValue]] = 0;
          qf.second++;
          emptyLoc = bottom2index[downValue];
          bottom2index.erase(downValue);
          movedbt = 1;
        } else
          bottom2index[downValue] = i;
      }

      // 천장에 하나가 존재하는 경우
      if (upValue != 0) {
        // 두개가 천장에 존재 할경우
        if (top2index.find(upValue) != top2index.end()) {
          twoEmpty.push_back({top2index[upValue], i});
          top2index.erase(upValue);
        } else
          top2index[upValue] = i;
      }
    }

    // 천장에 하나
    for (auto it : top2index) {
      int upV = it.first;
      if (bottom2index.find(upV) != bottom2index.end()) {
        // 아래에 하나
        oneMove.push_back({it.second, bottom2index[upV]});
      }
    }

    if (movedbt)
      if (isAllDone(qf.first)) {
        cout << qf.second;
        return 0;
      }

    // 경우의 수
    // 두 친구를 모두 빈곳에 가져다 놓을때
    if (emptyLoc != -1)
      for (pii ab : twoEmpty) {
        // cout << "twoEmpty\n";
        int o3 = qf.first.first[ab.first], o4 = qf.first.first[ab.second];
        qf.first.first[emptyLoc] = qf.first.first[ab.first];
        qf.first.second[emptyLoc] = qf.first.first[ab.second];
        qf.first.first[ab.first] = 0;
        qf.first.first[ab.second] = 0;

        if (s.find(qf.first) == s.end()) {
          s.insert(qf.first);
          q.push({qf.first, qf.second + 2});
        }

        qf.first.first[emptyLoc] = 0;
        qf.first.second[emptyLoc] = 0;
        qf.first.first[ab.first] = o3;
        qf.first.first[ab.second] = o4;
      }

    // 한친구를 한친구 위에 쌓을때
    for (pii ab : oneMove) {
      // printf("oneMove V%d U%d D%d\n", qf.first.first[ab.first], ab.first,
      // ab.second);
      int o3 = qf.first.first[ab.first];
      qf.first.first[ab.second] = o3;
      qf.first.first[ab.first] = 0;

      if (s.find(qf.first) == s.end()) {
        s.insert(qf.first);
        q.push({qf.first, qf.second + 1});
      }

      qf.first.first[ab.first] = o3;
      qf.first.first[ab.second] = 0;
    }

    if (emptyLoc != -1) {
      // 진짜 아무것도 없을 경우 위에 친구를 빈곳에 가져다 놓기
      for (int i = 0; i < a.size(); i++) {
        if (qf.first.first[i] == 0)
          continue;
        if (qf.first.first[i] == qf.first.second[i])
          continue;
        qf.first.second[emptyLoc] = qf.first.first[i];
        qf.first.first[i] = 0;
        if (s.find(qf.first) == s.end()) {
          s.insert(qf.first);
          q.push({qf.first, qf.second + 1});
        }
        qf.first.first[i] = qf.first.second[emptyLoc];
        qf.first.second[emptyLoc] = 0;
      }
    }
  }
  cout << -1;
  return 0;
}
