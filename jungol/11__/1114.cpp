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
using namespace std;
#define interface struct
#define zx3f 1061109567
#define itn int
#define _DEBUG_ 0
#define dout     \
    if (_DEBUG_) \
    cout
typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;
typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
template <typename T>
class CVector
{
public:
    vector<T> vec;

    CVector()
    {
    }
    CVector(int size)
    {
        vec.reserve(size);
    }
    CVector(size_t size)
    {
        vec.reserve(size);
    }

    void push(T v)
    {
        vec.push_back(v);
    }

    void push_back(T v)
    {
        vec.push_back(v);
    }

    void remove_duplicate()
    {
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }

    void fast_pop()
    {
        vec.pop_back();
    }

    void clear()
    {
        vec.clear();
    }

    T &at(size_t idx)
    {
        if (idx < 0)
        {
            idx = vec.size() + idx;
        }
        return this->vec[idx];
    }

    T pop()
    {
        T ld = vec.back();
        vec.pop_back();
        return ld;
    }

    T pop_back()
    {
        T ld = vec.back();
        vec.pop_back();
        return ld;
    }

    T back()
    {
        return vec.back();
    }

    T front()
    {
        return vec.front();
    }

    T &operator[](size_t idx)
    {
        return this->at(idx);
    }

    size_t size()
    {
        return vec.size();
    }

    size_t lastIndex()
    {
        return this->size() - 1;
    }

    bool empty()
    {
        return vec.empty();
    }

    auto begin()
    {
        return vec.begin();
    }

    auto end()
    {
        return vec.end();
    }

    auto capacity()
    {
        return vec.capacity();
    }
};

int n;
string str;

CVector<pair<int, char>> colors;
bool visited[355];

pii goMarble(char mb, int idx)
{
    idx %= colors.size();
    if (visited[idx])
    {
        return {0, -1};
    }
    if (colors[idx].second == 'w' || colors[idx].second == mb)
    {
        dout << "      └─ " << idx << "i / " << colors[idx].first << "m / " << colors[idx].second << "\n";
        visited[idx] = 1;
        idx++;

        pii p = goMarble(mb, idx);
        idx--;
        return {p.first + colors[idx].first, p.second};
    }
    return {0, idx};
}

pii calcSCORE(int vecst)
{
    int cntx = 0;
    bool cc = false;
    if (colors[vecst].second == 'w')
    {
        dout << "      └─ " << vecst << "i / " << colors[vecst].first << "m / " << colors[vecst].second << "\n";
        visited[vecst] = true;
        cntx += colors[vecst].first;
        vecst++;
        cc = true;
    }

    pii p = goMarble(colors[vecst].second, vecst);
    cntx += p.first;
    return {cntx, p.second};
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> str;

    int lastState = str[0];
    int cnt = 1;

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != lastState)
        {
            colors.push_back({cnt, lastState});
            if (colors.size() >= 3)
            {
                if (lastState == colors[colors.size() - 3].second && colors[colors.size() - 2].second == 'w')
                {
                    colors[colors.size() - 3].first += colors[colors.size() - 2].first + cnt;
                    colors.fast_pop();
                    colors.fast_pop();
                }
            }

            lastState = str[i];
            cnt = 1;

            continue;
        }
        cnt++;
    }
    if (str[0] == str[n - 1] && colors.size())
        colors[0].first += cnt;
    else
        colors.push_back({cnt, lastState});

    int i = 0;
    int mxsco = 0;
    for (pii x : colors)
    {
        for (int i = 0; i < colors.size(); i++)
        {
            visited[i] = 0;
        }
        dout << x.first << " & " << (char)x.second << endl;
        dout << "  └─ CALC A\n";
        pii a = calcSCORE(i);
        dout << "      └── " << a.first << "\n";
        pii b = {0, 0};
        if (a.second != i && a.second != -1)
        {
            dout << "  └─ CALC B\n";
            b = calcSCORE(a.second);
            dout << "      └── " << b.first << "\n";
        }

        int sco = a.first + b.first;
        // cout << a.first << " , " << b.first << " = " << sco << endl;
        if (mxsco < sco)
        {
            mxsco = sco;
            dout << "New max sco on " << i << " with sco " << sco << "\n";
            dout << "A , B : " << a.first << " , " << b.first << "\n";
        }
        ++i;
    }
    cout << mxsco;
}
