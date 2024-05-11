#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int dist[100005];
int distSum[100005];
int oilPrice[100005];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> dist[i];

    for (int i = 0; i < n; i++)
    {
        cin >> oilPrice[i];
        distSum[i + 1] = distSum[i] + dist[i];
    }

    int co = oilPrice[0];
    unsigned long long res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (co > oilPrice[i])
            co = oilPrice[i];
        res += (unsigned long long)co * (unsigned long long)dist[i];
    }

    cout << res;
}
