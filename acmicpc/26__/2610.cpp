#include <bits/stdc++.h>

using namespace std;

int personNum, edgeNum;

bool visited[101];
vector<vector<int>> groups; // 그룹 사람
vector<vector<int>> dist; // dist[a][b] a 부터 b 까지 거리

void findGroups(int start_idx) {
    queue<int> q;
    vector<int> group;  //이번에 생성하는 위원회의 멤버를 저장
    group.push_back(start_idx);

    q.push(start_idx);
    visited[start_idx] = true;

    int idx;
    while (!q.empty()) {
        idx = q.front();
        q.pop();
        

        for (int i = 1; i <= personNum; i++) {
            if (!visited[i])
                if (dist[idx][i] < INT_MAX) { // IM 이면 못가는 걸로다가
                    visited[idx] = true;
                    q.push(i);
                    group.push_back(i);
                }

        }
    }

    groups.push_back(group); //새로운 위원회를 삽입
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> personNum >> edgeNum;

    dist = vector<vector<int>>(personNum + 1, vector<int>(personNum + 1, INT_MAX));

    for (int i = 1; i <= personNum; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < edgeNum; i++) {
        int fr, to;
        cin >> fr >> to;
        dist[fr][to] = dist[to][fr] = 1;
    }

    for (int k = 1; k <= personNum; k++) {
        for (int i = 1; i <= personNum; i++) {
            if (dist[i][k] == INT_MAX) continue;
            for (int j = 1; j <= personNum; j++) {
                if (dist[j][k] == INT_MAX) continue;
                // dist 구하기
                dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[j][k]);
            }
        }
    }
      
    int groupCnt = 0;

    for (int i = 1; i <= personNum; i++) {
        if (!visited[i]) {
            findGroups(i);
            groupCnt++;
        }
    }

    vector<int> admins;
    int now_idx, next_idx;
    for (int k = 0; k < groupCnt; k++) {
        pair<int, int> admin(0, INT_MAX); // first 번쨰 index admin 이고 합 second 많큼 걸림

        for (int i = 0; i < groups[k].size(); i++) {
            int max_dist = 0;
            now_idx = groups[k][i];

            for (int j = 0; j < groups[k].size(); j++) {
                next_idx = groups[k][j];
                max_dist = max(dist[now_idx][next_idx], max_dist);
            }

            if (max_dist < admin.second)
                admin = { now_idx, max_dist };
        }
        admins.push_back(admin.first);
    }

    sort(admins.begin(), admins.end());

    cout << groupCnt << "\n";

    for (int i = 0; i < admins.size(); i++) {
        cout << admins[i] << "\n";
    }
}