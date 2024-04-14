#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool c = false;
    bool isJava = false;
    bool err = false;

    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (!i || c)
            {
                err = true;
                break;
            }
            ans += '_';
            ans += s[i] - 'A' + 'a';
            isJava = true;
        }
        else if (s[i] == '_')
        {
            bool comp = !i;
            comp |= isJava;
            comp |= i == s.size() - 1;
            comp |= s[i + 1] == '_';
            comp |= ('A' <= s[i + 1] && s[i + 1] <= 'Z');
            if (comp)
            {
                err = true;
                break;
            }
            ans += s[i + 1] - 'a' + 'A';
            i++;
            c = true;
        }
        else
            ans += s[i];
    }

    if (err)
        cout << "Error!";
    else
        cout << ans;
}