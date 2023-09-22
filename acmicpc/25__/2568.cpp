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

    void push(T v)
    {
        vec.push_back(v);
    }

    void push_back(T v)
    {
        vec.push_back(v);
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

struct PowerLine
{
    int from;
    int to;

    bool operator<(const PowerLine &a) const
    {
        return this->from < a.from;
    }
};

CVector<PowerLine> lines;
CVector<int> ans;
CVector<int> idx;

int n;

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (itn i = 0; i < n; i++)
    {
        int f, t;
        cin >> f >> t;
        lines.push_back({f, t});
    }

    sort(lines.vec.begin(), lines.vec.end());

    ans.push_back(lines[0].to);
    idx.push_back(0);

    for (int i = 1; i < n; i++)
    {
        int t = lines[i].to;
        if (ans.back() < t)
        {
            ans.push(t);
            idx.push(ans.lastIndex());

            continue;
        }

        // upper bound
        int l = 0;
        int r = ans.lastIndex();

        while (l < r)
        {
            int m = (l + r) / 2;
            if (ans[m] < t)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        ans[l] = t;
        idx.push(l);
    }

    cout << n - ans.size() << "\n";

    int now = ans.lastIndex();
    CVector<int> st;

    for (int i = idx.lastIndex(); i >= 0; i--)
    {
        if (now == idx[i])
            now--;
        else
            st.push(lines[i].from);
    }

    sort(st.vec.begin(), st.vec.end());
    for (auto x : st)
        cout << x << "\n";
}