#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n = 0; // count of house;
int m = 0; // count of road;
int vntp = 0; // vilage number to party;

int sol(int sh , int costs[], vector<pair<int, int>> roads[]) {
    //memset(costs, 123456789, sizeof(costs));
    fill(costs, costs + 1010, INT_MAX);
    priority_queue<pair<int, int>> pq;
    // pair< cost , now >
    costs[sh] = 0;
    pq.push(make_pair(0, sh));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (costs[now] < cost) continue;

        for (int i = 0; i < roads[now].size(); i++)
        {
            int next = roads[now][i].first;
            int nc = roads[now][i].second + cost; // new cost

            if (costs[next] > nc)
            {
                costs[next] = nc;
                pq.push(make_pair(nc, next));
            }
        }
    }
    return costs[vntp];
}

int main() {
    vector<pair<int, int>> roads[1010];
    vector<pair<int, int>> back_roads[1010];
    int costs[1010]; // like visit for pq
    int return_cost[1010];

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> vntp;

    for (int i = 0; i < m; i++) { // input
        int st = 0;
        int ed = 0;
        int wg = 0;

        cin >> st >> ed >> wg;
        roads[st].push_back(make_pair(ed, wg));
        back_roads[ed].push_back({ st , wg });
    }

    int ans = INT_MIN;

    sol(vntp, return_cost , roads);
    sol(vntp, costs, back_roads);


    for (int i = 1; i <= n; i++) { // loop in all vilages
        ans = max(costs[i] + return_cost[i], ans);
    }

    cout << ans;
}
