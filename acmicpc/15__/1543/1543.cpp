#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>
#include <climits>

// import regex
#include <regex>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
    int x;
    int y;
};

int countMatchInRegex(std::string s, std::string re)
{
    std::regex words_regex(re);
    auto words_begin = std::sregex_iterator(
        s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();

    return std::distance(words_begin, words_end);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << countMatchInRegex(s, t);
}
