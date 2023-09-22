#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    string str;
    int S=0, B=0, L=0, P=0, N, tmp;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> str >> tmp;
        if (str == "BANANA") B+=tmp;
        if (str == "STRAWBERRY") S+=tmp;
        if (str == "LIME") L+=tmp;
        if (str == "PLUM") P+=tmp;    
    }
    if (B == 5 || S == 5 || L == 5 || P == 5) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}