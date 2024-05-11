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
CVector<int> v;

int one_len = 0;
int two_len = 0;
int thr_len = 0;

int sw = 0;

bool find(int add_len, int i, int toFind)
{
    for (int j = one_len + add_len; j < n; j++)
    {
        if (v[j] == toFind)
        {
            sw++;
            swap(v[i], v[j]);
            return true;
        }
    }
    return false;
}

void toFindOne(int i, int toFind)
{
    if (v[i] == 3)
    {
        bool found = find(two_len, i, toFind);

        if (!found)
            find(0, i, toFind);
    }
    else if (v[i] == 2)
    {
        bool found = false;
        // start find 2
        find(0, i, toFind);
    }
}

void addLen(int x)
{
    if (x == 1)
        one_len++;
    if (x == 2)
        two_len++;
    if (x == 3)
        thr_len++;
}

int getTofind(int i)
{
    if (i < one_len)
        return 1;
    else if (i < one_len + two_len)
        return 2;
    else
        return -1;
}

int main()
{

    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push(x);
        addLen(x);
    }

    for (int i = 0; i < n; i++)
    {
        int toFind = getTofind(i);

        if (toFind == -1)
            break;
        if (v[i] == toFind)
            continue;

        if (toFind == 1)
        {
            // st idx 1
            toFindOne(i, toFind);
        }
        else
        {
            // st idx 2
            find(two_len, i, toFind);
        }
    }

    cout << sw;
}
