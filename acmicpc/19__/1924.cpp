#include <bits/stdc++.h>
using namespace std;
int main()
{
    string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int x, y;
    int count = 0;

    cin >> x >> y;

    if (x > 12 || x < 1 || y < 1 || y > 31)
        return 0;
    
    for (int i = 0; i < x; i++)
    {
        if ((i + 1) == x)
        {
            count += y;
        }
        else
        {
            count += month[i];
        }
    }
    
    cout << day[count % 7] << endl;

    return 0;
}
