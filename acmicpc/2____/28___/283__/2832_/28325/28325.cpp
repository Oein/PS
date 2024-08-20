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

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class CVector
{
public:
    vector<T> vec;
    unsigned long rotate = 0;

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
    CVector(size_t size, T v)
    {
        vec.reserve(size);
        for (size_t i = 0; i < size; i++)
        {
            vec.push_back(v);
        }
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

    void setRotate(unsigned long r)
    {
        this->rotate = r;
    }

    T at(size_t idx)
    {
        if (this->vec.size() == 0)
        {
            throw "Index out of range";
        }
        idx += rotate % vec.size();

        while (idx < 0)
            idx = vec.size() + idx;
        idx = idx % vec.size();

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
        if (this->vec.size() == 0)
        {
            throw "Index out of range";
        }
        idx += rotate % vec.size();

        while (idx < 0)
            idx = vec.size() + idx;
        idx = idx % vec.size();

        return this->vec[idx];
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

    void reserve(size_t size)
    {
        vec.reserve(size);
    }

    void resize(size_t size)
    {
        vec.resize(size);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ull sum = 0;
    CVector<ull> v;
    CVector<bool> used;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ull x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    // cout << "[SUM] " << sum << '\n';

    if (sum == 0)
    {
        cout << n / 2;
        return 0;
    }

    used.vec.resize(n, false);

    for (int i = 0; i < n; i++)
        if (v[i] > 0)
        {
            v.setRotate(i);
            break;
        }
    for (int i = 0; i < n; i++)
    {
        if (v[i])
            continue;
        if (used.vec[i])
        {
            // cout << "[SKIP] " << i << '\n';
            continue;
        }

        // cout << "[FOR1] " << i << '\n';

        int j = i;
        for (; j < n; j++)
        {
            if (v[j])
            {
                break;
            }
            used.vec[j] = true;
        }

        // cout << "[ADD] " << (j - i + 1) / 2 << '\n';
        sum += (j - i + 1) / 2;
    }

    cout << sum;
}
