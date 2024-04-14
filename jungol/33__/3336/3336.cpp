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

int xs[1010101];
int ys[1010101];
int n;
CVector<pii> v;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    v.vec.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first += 500005;
        v[i].second += 500005;
    }

    for (int i = 0; i < n; i++)
    {
        pii now = v[i];
        pii next = v[(i + 1) % n];

        // y equal
        if (now.second == next.second)
        {
            xs[min(now.first, next.first)]++;
            xs[max(now.first, next.first)]--;
        }
        else
        {
            ys[min(now.second, next.second)]++;
            ys[max(now.second, next.second)]--;
        }
    }

    for (int i = 1; i < 1010101; i++)
    {
        xs[i] += xs[i - 1];
        ys[i] += ys[i - 1];
    }

    sort(xs, xs + 1010101);
    sort(ys, ys + 1010101);

    int ans = max(xs[1010100], ys[1010100]);
    cout << ans;
}
