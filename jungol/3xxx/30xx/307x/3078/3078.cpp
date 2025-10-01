#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int aMax, bMax;
int aMake, bMake;

struct QData
{
    int a;
    int b;

    size_t operator()(const QData &pointToHash) const noexcept
    {
        size_t hash = pointToHash.a * 1000000 + pointToHash.b;
        return hash;
    };

    bool operator==(const QData &other) const
    {
        if (a == other.a && b == other.b)
            return true;
        return false;
    };
};

namespace std
{
    template <>
    struct hash<QData>
    {
        std::size_t operator()(const QData &p) const noexcept
        {
            return p(p);
        }
    };
}

unordered_set<QData> s;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> aMax >> bMax >> aMake >> bMake;

    queue<QData> q;
    q.push({0, 0});
    int t = 0;
    while (!q.empty())
    {
        unsigned long qs = q.size();
        while (qs--)
        {
            QData qf = q.front();
            q.pop();

            if (qf.a == aMake && qf.b == bMake)
            {
                cout << t;
                return 0;
            }

            // E 0
            if (qf.a > 0)
            {
                int tmp = qf.a;
                qf.a = 0;
                if (s.find(qf) == s.end())
                {
                    q.push(qf);
                    s.insert(qf);
                }
                qf.a = tmp;
            }

            // E 1
            if (qf.b > 0)
            {
                int tmp = qf.b;
                qf.b = 0;

                if (s.find(qf) == s.end())
                {
                    q.push(qf);
                    s.insert(qf);
                }
                qf.b = tmp;
            }

            // F 0
            if (qf.a < aMax)
            {
                int tmp = qf.a;
                qf.a = aMax;

                if (s.find(qf) == s.end())
                {
                    q.push(qf);
                    s.insert(qf);
                }
                qf.a = tmp;
            }

            // F 1
            if (qf.b < bMax)
            {
                int tmp = qf.b;
                qf.b = bMax;

                if (s.find(qf) == s.end())
                {
                    q.push(qf);
                    s.insert(qf);
                }
                qf.b = tmp;
            }

            // M 0 -> 1
            if (qf.b < bMax && qf.a > 0)
            {
                int a__ = qf.a;
                int b__ = qf.b;

                int bpour = bMax - qf.b;
                if (qf.a <= bpour)
                {
                    qf.b += qf.a;
                    qf.a = 0;
                }
                else
                {
                    // 넘침
                    int flowOver = qf.a - bpour;
                    qf.a = flowOver;
                    qf.b = bMax;
                }

                if (s.find(qf) == s.end())
                {
                    q.push(qf);
                    s.insert(qf);
                }
                qf.a = a__;
                qf.b = b__;
            }

            // M 1 -> 0
            if (qf.a < aMax && qf.b > 0)
            {
                int a__ = qf.a;
                int b__ = qf.b;

                int apour = aMax - qf.a;
                if (qf.b <= apour)
                {
                    qf.a += qf.b;
                    qf.b = 0;
                }
                else
                {
                    // 넘침
                    int flowOver = qf.b - apour;
                    qf.b = flowOver;
                    qf.a = aMax;
                }

                if (s.find(qf) == s.end())
                {
                    q.push(qf);
                    s.insert(qf);
                }
                qf.a = a__;
                qf.b = b__;
            }
        }

        t++;
    }

    cout << "-1";
}