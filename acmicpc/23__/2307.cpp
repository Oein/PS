#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

struct Road {
    int to;
    int t;
    int id;
};

struct State {
    int where;
    int time;
};

struct State_comp {
    bool operator()(const State& a, const State& b) {
        return a.time > b.time;
    }
};

int n, m;
int did_low[1010];
vector<Road> paths[1010];
pair<int, int> ftwi[5010]; // get from , to with id

int par[1010];

int dijaestrika(int unusedRoadID = -1) {
    priority_queue<State, vector<State>, State_comp> pq;
    did_low[1] = 0;
    par[1] = -1;
    pq.push({ 1 , 0 });

    while (!pq.empty()) {
        State sne = pq.top();
        pq.pop();

        if (did_low[sne.where] > sne.time) continue;
        if (sne.where == n) {
            return sne.time;
        }

        for (int i = 0; i < paths[sne.where].size(); i++) {
            int nex = paths[sne.where][i].to;
            if (unusedRoadID == paths[sne.where][i].id) continue;
            if (did_low[nex] <= sne.time + paths[sne.where][i].t) continue;
            did_low[nex] = sne.time + paths[sne.where][i].t;
            if (unusedRoadID == -1) {
                par[nex] = paths[sne.where][i].id;
            }
            pq.push({ nex , sne.time + paths[sne.where][i].t });
        }

    }
    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        paths[x].push_back({ y , t , i });
        paths[y].push_back({ x , t , i });
        ftwi[i] = { x , y };
    }

    fill(did_low, did_low + n + 1, 10000010);
    int tans = dijaestrika();

    int maxest = 0;

    int follow = n;

    while (follow != 1) {
        fill(did_low, did_low + n + 1, 10000010);

        int emt = dijaestrika(par[follow]);
        follow = ftwi[par[follow]].first == follow ? ftwi[par[follow]].second : ftwi[par[follow]].first;

        if (emt == -1) {
            cout << "-1";
            return 0;
        }

        maxest = max(maxest, emt);
    }

    cout << maxest - tans;
}
