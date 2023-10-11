#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, string> m;
    int x, y;
    cin >> x >> y;
    while (x--)
    {
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }
    while (y--)
    {
        string a;
        cin >> a;
        cout << m[a] << endl;
    }
}