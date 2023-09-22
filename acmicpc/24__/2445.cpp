#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <=2*(n-i); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i<=n-1; i++)
    {
        for (int j = i; j <n; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= 2*i; j++)
        {
            cout << " ";
        }
        for (int j = i; j <n; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
