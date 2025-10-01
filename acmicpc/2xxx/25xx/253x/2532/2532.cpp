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

#define Animal pair<int, int>
#define to second

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    CVector<Animal> v(n);
    for (int i = 0; i < n; i++)
    {
        Animal ani;
        cin >> ani.first >> ani.first >> ani.second;
        v.push(ani);
    }

    sort(v.begin(), v.end(), [&](pii a, pii b)
         { return a.first < b.first || a.first == b.first && a.second > b.second; });
    v.remove_duplicate();

    CVector<int> lis;
    for (auto a : v)
    {
        if (lis.empty() || lis.back() <= -a.to)
            lis.push(-a.to);
        else
            *upper_bound(lis.begin(), lis.end(), -a.to) = -a.to;
    }

    cout << lis.size();
}
