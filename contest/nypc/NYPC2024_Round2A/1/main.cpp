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
typedef long long ull;

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

int n, m, k;

vector<ll> up;
vector<ll> down;
vector<ll> canget;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        up.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        down.push_back(x);
        canget.push_back(0);
    }
    canget.push_back(0);
    for (int i = n - 1; i >= 0; i--)
    {
        canget[i] = canget[i + 1] + (down[i] == -1 ? 0 : down[i]);
    }

    // 다운 그래이드를 할때는 down[i] 만큼 돌려 받음
    // 업그레이드를 할때는 up[i] 만큼 내야함
    // 사전순이 +,0,- 라고 했을때
    // 사전순으로 가장 앞에 있는 경우를 구해야함
    // down[i] == -1 이면 다운그레이드 불가
    // up[i] == -1 이면 업그레이드 불가

    // 위의 조건을 만족하는 경우를 찾아야함

    int useForDowngrade = n - 1;
    ull money = 0;
    for (int i = 0; i < n; i++)
    {
        // 이미 다운그래이드에 사용 되었는가?
        bool usedForDG = i > useForDowngrade && down[i] != -1;
        if (usedForDG)
        {
            // printf("\n%d used for dl\n", i);
            if (money - down[i] >= 0)
            {
                // printf("%d can revive\n", i);
                money -= down[i];
                if (up[i] != -1 && money - up[i] >= 0)
                {
                    // printf("%d can upgrade\n", i);
                    money -= up[i];
                    cout << "+";
                    continue;
                }
                cout << "0";
                continue;
            }
            else
            {
                cout << "-";
            }
            continue;
        }

        // 다운그레이드에 사용되지 않았음.

        // 업그레이드 시도
        if (up[i] != -1)
        {
            if (money - up[i] >= 0)
            {
                // printf("%d can upgrade\n", i);
                money -= up[i];
                cout << "+";
                continue;
            }
            // 업그레이드를 위한 돈이 부족함

            if (canget[i + 1] + money < up[i])
            {
                cout << "0";
                continue;
            }

            // 다운그레이드 시도
            const int ufd = useForDowngrade;
            const ull mny = money;
            while (useForDowngrade > i && money < up[i])
            {
                if (down[useForDowngrade] != -1)
                {
                    // printf("\nGet %d from %d\n", down[useForDowngrade], useForDowngrade);
                    money += down[useForDowngrade];
                }
                useForDowngrade--;
            }

            if (money >= up[i])
            {
                money -= up[i];
                cout << "+";
                // printf("\nuse for for downgrade: %d\n", useForDowngrade);
                continue;
            }
            else
            {
                // 뒤끌 해도 부족함
                useForDowngrade = ufd;
                money = mny;
                cout << "0";
                continue;
            }

            continue;
        }

        cout << "0";
    }
}
