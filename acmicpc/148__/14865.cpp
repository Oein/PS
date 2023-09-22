#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Pos {
    int x;
    int y;
};

bool cmp(Pos a, Pos b) {
    return (a.x == b.x) ? (a.y > b.y) : (a.x < b.x);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<Pos> lines;
    Pos lastPos;
    Pos lastUpPos;
    bool isUpLast = false;
    vector<Pos> poses;
    for (int i = 0; i < n; i++) {
        Pos a;
        cin >> a.x >> a.y;
        poses.push_back(a);
    }

    int lu = 0;
    for (; !(poses[lu].y < 0 && poses[(lu + 1) % n].y > 0); lu++ , lu %= n) {}

    for (int i = lu, j = 0; j <= n; i++, i %= n, j++) {
        Pos a = poses[i];
        if (i == lu) {
            lastPos = a;
            continue;
        }

        // x is same && y is go up and go down
        if (lastPos.x == a.x && ((lastPos.y < 0 && a.y > 0) || (lastPos.y > 0 && a.y < 0))) {
            if (isUpLast == true) { // now is down
                if (lastUpPos.x > a.x) { // 전게 오른쪽에 있음
                    swap(lastUpPos.x, a.x);
                    swap(lastUpPos.y, a.y);
                }
                lines.push_back({ lastUpPos.x , 1 });
                lines.push_back({ a.x , -1 });
            }
            else { // now is up
                lastUpPos = a;
            }

            isUpLast = !isUpLast;
        }

        lastPos = a;
    }

    /*
    
    */

    sort(lines.begin(), lines.end(), cmp);

    stack<int> st;
    int v1 = 0;
    int v2 = 0;

    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].y == 1) {
            st.push(i);
            continue;
        }

        if (st.top() == i - 1) {
            v2++;
        }

        if (st.size() == 1) {
            v1++;
        }

        st.pop();
    }
    cout << v1 << " " << v2;
}