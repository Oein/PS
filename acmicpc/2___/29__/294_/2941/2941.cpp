#include<bits/stdc++.h>
using namespace std;
string replaceAll(const string &str, const string &pattern, const string &replace)
{
    string result = str;
    string::size_type pos = 0;
    string::size_type offset = 0;
    while((pos = result.find(pattern, offset)) != string::npos)
    {
        result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
        offset = pos + replace.size();
    }
    return result;
}

int main(){
    string str = "";
    cin >> str;
    str = replaceAll(str , "c=" , "1");
    str = replaceAll(str , "č" , "1");
    str = replaceAll(str , "ć" , "1");
    str = replaceAll(str , "c-" , "1");
    str = replaceAll(str , "dz=" , "1");
    str = replaceAll(str , "dž" , "1");
    str = replaceAll(str , "đ" , "1");
    str = replaceAll(str , "d-" , "1");
    str = replaceAll(str , "lj" , "1");
    str = replaceAll(str , "nj" , "1");
    str = replaceAll(str , "s=" , "1");
    str = replaceAll(str , "š" , "1");
    str = replaceAll(str , "ž" , "1");
    str = replaceAll(str , "z=" , "1");
    cout << str.size();
}
