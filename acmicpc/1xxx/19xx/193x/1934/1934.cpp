#include <bits/stdc++.h>
using namespace std;

int divide(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return divide(y, x % y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 0;
    int A = 0, B = 0;
    
    cin >> T;
 
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        if (A >= B)
        {
            cout << A * B / divide(A, B) << "\n";
        }
        else
            cout << A * B / divide(B, A) << "\n";
    }
}
