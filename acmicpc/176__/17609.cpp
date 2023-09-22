#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

string Str;

/*
 @Parms {Left} : Count of How many chars deleted from left
 @Parms {Right} : Count of How many chars deleted from right
 @Parms {Delete} : Did char deleted
 */
int palindrome(int Left, int Right, bool Delete)
{
    while(Left < Right)
    {
        if(Str[Left] != Str[Right])
        {
            if(Delete == false)
            {
                if(palindrome(Left + 1, Right, true) == 0 || palindrome(Left, Right - 1, true) == 0) return 1;
                return 2;
            }
            else return 2;
        }
        else
        {
            Left++;
            Right--;
        }
    }
    return 0;
}

int main(){
    int t = 0;
    cin >> t;
    while(t--){
        cin >> Str;
        cout << palindrome(0, Str.size() - 1, false) << "\n";
    }
}
