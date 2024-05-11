#include <bits/stdc++.h>
using namespace std;

bool func(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.second < b.first.second)
        return true;

    else if (a.first.second == b.first.second)
        if (a.first.first < b.first.first)
            return true;
    return false;
}

int main(void)
{
    int N, C, M;
    int capacity[2001];
    pair<pair<int, int>, int> arr[10001];

    cin >> N >> C >> M;

    for (int i = 0; i < M; i++) {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
               //  보내는 마을                받는마을         개수
    }

    sort(arr, arr + M, func);

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        int boxCnt = 0;

        for (int j = arr[i].first.first; j < arr[i].first.second; j++) {
            boxCnt = max(boxCnt, capacity[j]);
        }
            
        int leftSpace = min(arr[i].second, C - boxCnt);
        result += leftSpace;

        for (int j = arr[i].first.first; j < arr[i].first.second; j++) {
            capacity[j] += leftSpace;
        }
    }
    cout << result;
    return 0;
}