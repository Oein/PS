#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void)
{
    cin.tie();
    cout.tie();
    int n, c = 1;
    cin >> n;
    int sum = 0;
    int arr[n + 5];
    int arr2[n + 5];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (!i)
        {
            arr2[i] = arr[i];
        }
        if (i && arr[i - 1] + 1 != arr[i])
        {
            arr2[c++] = arr[i];
        }
    }
    for (int i = 0; i < c; i++)
    {
        sum += arr2[i];
    }
    cout << sum;
    return 0;
}