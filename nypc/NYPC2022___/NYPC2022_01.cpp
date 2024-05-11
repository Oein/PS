#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int lastTimes[105];

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (m % 2 == 1)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        lastTimes[i] = -100;
    }
    for (int i = 0; i < m; i++)
    {
        int time, index, status;
        cin >> time >> index >> status;
        if (status == 0)
        {
            // 시작했는데 시작한 경우
            if (lastTimes[index] != -100)
            {
                cout << "NO";
                return 0;
            }
            else
            {
                // 정상
                lastTimes[index] = time;
            }
        }
        else if (status == 1)
        {
            // 시작도 안했는데 끝난경우
            if (lastTimes[index] == -100)
            {
                cout << "NO";
                return 0;
            }

            // 1분이 안됬는데 끝난경우
            if (time - lastTimes[index] < 60)
            {
                cout << "NO";
                return 0;
            }
            else
            {
                // 정상
                lastTimes[index] = -100;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (lastTimes[i] != -100)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}