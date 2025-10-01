#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_NODE_COUNT 500002

vector<int> paths[MAX_NODE_COUNT];
int colors[MAX_NODE_COUNT];
pair<int, int> shortestDistance[MAX_NODE_COUNT]; // pair<distance, rootNode>
bool didVisit[MAX_NODE_COUNT];
bool didMeetOthers[MAX_NODE_COUNT];
int nodeCountByColor[2];
queue<int> q;
int nodeCount = 0;
int t = 0;

/*int getMaxDistanceBetweenNodesThatHasTheSameColor(int color) {
    memset(shortestDistance, 0, sizeof(shortestDistance));
    memset(didVisit, 0, sizeof(didVisit));
    memset(didMeetOthers, 0, sizeof(didMeetOthers));
    
    for (int i = 1; i <= nodeCount; i++) { // get color
        if (colors[i] == color) {
            q.push(i);
            didVisit[i] = true;
            shortestDistance[i].second = i;
        }
    }

    int maxDistance = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int x : paths[node]) {
            if (didVisit[x]) { // visited
                if (shortestDistance[node].second == shortestDistance[x].second) {
                    continue;
                }
                if (didMeetOthers[shortestDistance[node].second]) continue;
                // didn't meet others
                didMeetOthers[shortestDistance[node].second] = true;
                didMeetOthers[shortestDistance[x].second] = true;
                int distance = shortestDistance[node].first + shortestDistance[x].first + 1;
                //                   지금 까지 온 비용      +      다음 꺼 비용         + 1(1번 더 움직이는 비용)
                if (distance > maxDistance) maxDistance = distance;
                continue;
            }

            shortestDistance[x].first = shortestDistance[node].first + 1;
            shortestDistance[x].second = shortestDistance[node].second;
            didVisit[x] = true;
            q.push(x);
        }
    }

    return maxDistance;
}*/

int min_dist[MAX_NODE_COUNT];

void getMaxDistanceBetweenNodesThatHasTheSameColor(int color) {
    //memset(shortestDistance, 0, sizeof(shortestDistance));
    
    for (int i = 1; i <= nodeCount; i++) { // get color
        if (colors[i] == color) {
            q.push(i);
            shortestDistance[i].first = 0;
            shortestDistance[i].second = i;
        }
        else
            shortestDistance[i].second = 0;
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int x : paths[node]) {
            if (shortestDistance[x].second) { // visited
                if (shortestDistance[node].second == shortestDistance[x].second) {
                    continue;
                }
                
                int distance = shortestDistance[node].first + shortestDistance[x].first + 1;
                //                   지금 까지 온 비용      +      다음 꺼 비용         + 1(1번 더 움직이는 비용)
                min_dist[shortestDistance[node].second] = min(min_dist[shortestDistance[node].second], distance);
                min_dist[shortestDistance[x].second] = min(min_dist[shortestDistance[x].second], distance);
                continue;
            }

            shortestDistance[x].first = shortestDistance[node].first + 1;
            shortestDistance[x].second = shortestDistance[node].second;
            q.push(x);
        }
    }
}


int main() {
    cin >> t;
    while (t--) {
        
        nodeCountByColor[0] = nodeCountByColor[1] = 0;
        cin >> nodeCount;

        for (int i = 1; i <= nodeCount; i++) paths[i].clear();

        for (int i = 1; i < nodeCount; i++) { // get paths
            int a = 0, b = 0;
            cin >> a >> b;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        for (int i = 1; i <= nodeCount; i++) { // get color
            cin >> colors[i];
            nodeCountByColor[colors[i]]++;
            min_dist[i] = MAX_NODE_COUNT;
        }

        if (nodeCountByColor[0] == 1 || nodeCountByColor[1] == 1) {
            cout << "-1\n";
            continue;
        }

        //cout << max(getMaxDistanceBetweenNodesThatHasTheSameColor(0), getMaxDistanceBetweenNodesThatHasTheSameColor(1)) << "\n";

        getMaxDistanceBetweenNodesThatHasTheSameColor(0), getMaxDistanceBetweenNodesThatHasTheSameColor(1);
        int maxDistance = 0;
        for (int i = 1; i <= nodeCount; i++) {
            maxDistance = max(maxDistance, min_dist[i]);
        }

        cout << maxDistance << "\n";
    }
}