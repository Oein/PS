// Preset 끝은 620번째 줄로
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
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <climits>
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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int bigint_base = 1000000000;
const int bigint_base_digits = 9;

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

    void reverse(int start, int end)
    {
        reverse(vec.begin() + start, vec.begin() + end);
    }
};
struct BigInt
{
    vector<int> a;
    int sign;
    /*<arpa>*/
    int size()
    {
        if (a.empty())
            return 0;
        int ans = (a.size() - 1) * bigint_base_digits;
        int ca = a.back();
        while (ca)
            ans++, ca /= 10;
        return ans;
    }
    BigInt operator^(const BigInt &v)
    {
        BigInt ans = 1, a = *this, b = v;
        while (!b.isZero())
        {
            if (b % 2)
                ans *= a;
            a *= a, b /= 2;
        }
        return ans;
    }
    string to_string()
    {
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof()
    {
        string s = to_string();
        int ans = 0;
        for (auto c : s)
            ans += c - '0';
        return ans;
    }
    /*</arpa>*/
    BigInt() : sign(1)
    {
    }

    BigInt(long long v)
    {
        *this = v;
    }

    BigInt(const string &s)
    {
        read(s);
    }

    void operator=(const BigInt &v)
    {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v)
    {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / bigint_base)
            a.push_back(v % bigint_base);
    }

    BigInt operator+(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            BigInt res = v;

            for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i)
            {
                if (i == (int)res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= bigint_base;
                if (carry)
                    res.a[i] -= bigint_base;
            }
            return res;
        }
        return *this - (-v);
    }

    BigInt operator-(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            if (abs() >= v.abs())
            {
                BigInt res = *this;
                for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i)
                {
                    res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += bigint_base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i)
        {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / bigint_base);
            a[i] = (int)(cur % bigint_base);
            // asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    BigInt operator*(int v) const
    {
        BigInt res = *this;
        res *= v;
        return res;
    }

    void operator*=(long long v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i)
        {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / bigint_base);
            a[i] = (int)(cur % bigint_base);
            // asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    BigInt operator*(long long v) const
    {
        BigInt res = *this;
        res *= v;
        return res;
    }

    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1)
    {
        int norm = bigint_base / (b1.a.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--)
        {
            r *= bigint_base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long)bigint_base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    BigInt operator/(const BigInt &v) const
    {
        return divmod(*this, v).first;
    }

    BigInt operator%(const BigInt &v) const
    {
        return divmod(*this, v).second;
    }

    void operator/=(int v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i)
        {
            long long cur = a[i] + rem * (long long)bigint_base;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }

    BigInt operator/(int v) const
    {
        BigInt res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const
    {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long)bigint_base) % v;
        return m * sign;
    }

    void operator+=(const BigInt &v)
    {
        *this = *this + v;
    }
    void operator-=(const BigInt &v)
    {
        *this = *this - v;
    }
    void operator*=(const BigInt &v)
    {
        *this = *this * v;
    }
    void operator/=(const BigInt &v)
    {
        *this = *this / v;
    }

    bool operator<(const BigInt &v) const
    {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const BigInt &v) const
    {
        return v < *this;
    }
    bool operator<=(const BigInt &v) const
    {
        return !(v < *this);
    }
    bool operator>=(const BigInt &v) const
    {
        return !(*this < v);
    }
    bool operator==(const BigInt &v) const
    {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt &v) const
    {
        return *this < v || v < *this;
    }

    void trim()
    {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const
    {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    BigInt operator-() const
    {
        BigInt res = *this;
        res.sign = -sign;
        return res;
    }

    BigInt abs() const
    {
        BigInt res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const
    {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * bigint_base + a[i];
        return res * sign;
    }

    friend BigInt gcd(const BigInt &a, const BigInt &b)
    {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend BigInt lcm(const BigInt &a, const BigInt &b)
    {
        return a / gcd(a, b) * b;
    }

    void read(const string &s)
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= bigint_base_digits)
        {
            int x = 0;
            for (int j = max(pos, i - bigint_base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream &operator>>(istream &stream, BigInt &v)
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const BigInt &v)
    {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            stream << setw(bigint_base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits)
    {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++)
        {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits)
            {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b)
    {
        int n = a.size();
        vll res(n + n);
        if (n <= 32)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int)a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int)r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    BigInt operator*(const BigInt &v) const
    {
        vector<int> a6 = convert_base(this->a, bigint_base_digits, 6);
        vector<int> b6 = convert_base(v.a, bigint_base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int)c.size(); i++)
        {
            long long cur = c[i] + carry;
            res.a.push_back((int)(cur % 1000000));
            carry = (int)(cur / 1000000);
        }
        res.a = convert_base(res.a, 6, bigint_base_digits);
        res.trim();
        return res;
    }
};

// *********************************************************************
//
//  PPPP   RRRR   EEEE   SSSS  EEEE  TTTTT          EEEE  NN   N  DDDD
//  P   P  R   R  E     S      E       T            E     N N  N  D   D
//  PPPP   RRRR   EEEE   SSSS  EEEE    T            EEEE  N  N N  D   D
//  P      R   R  E         S  E       T            E     N   NN  D   D
//  P      R   R  EEEE  SSSS   EEEE    T            EEEE  N    N  DDDD
//
// *********************************************************************

set<string> used;

string rev(string str, int f, int t)
{
    reverse(str.begin() + f, str.begin() + t + 1);
    return str;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    if (n == 1)
    {
        cin >> n;
        cout << 0;
        return 0;
    }

    if (n == 2)
    {
        int x;
        cin >> n >> x;
        if (n > x)
            cout << 1;
        else
            cout << 0;
        return 0;
    }

    string nu;
    vector<pair<int, int>> gs;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        gs.push_back({x, i});
        ans += i + '1';
    }

    sort(gs.begin(), gs.end(), [](const pii a, const pii b)
         { return a.first < b.first; });

    for (auto x : gs)
        nu += x.second + 1 + '0';

    queue<string> q;
    unsigned long step = 0;

    q.push(nu);
    // cout << "ANS IS " << ans << "\n";
    while (true)
    {
        unsigned long qs = q.size();
        while (qs--)
        {
            string qf = q.front();
            q.pop();

            if (qf == ans)
            {
                cout << step;
                return 0;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    string reved = rev(qf, i, j);
                    if (used.find(reved) != used.end())
                        continue;
                    // cout << "REV " << i << " , " << j << " / " << reved << "\n";
                    used.insert(reved);
                    q.push(reved);
                }
            }
        }
        step++;
    }
}
