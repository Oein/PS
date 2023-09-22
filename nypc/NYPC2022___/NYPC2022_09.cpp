#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef bitset<4> mbti;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

ull qdif, wdif, edif, rdif;

int n = 0;

ull getDif(mbti a, mbti b)
{
    ull ret = 0;
    if (a[0] != b[0])
        ret += qdif;
    if (a[1] != b[1])
        ret += wdif;
    if (a[2] != b[2])
        ret += edif;
    if (a[3] != b[3])
        ret += rdif;
    return ret;
}

mbti getMBTI(string s)
{
    mbti x;
    if (s[0] == 'I')
        x.set(0, true);
    if (s[1] == 'N')
        x.set(1, true);
    if (s[2] == 'F')
        x.set(2, true);
    if (s[3] == 'P')
        x.set(3, true);
    return x;
}

struct Qdata
{
    bitset<501> stuused;
    ull diffs;

    Qdata()
    {
        stuused.set();
    }

    void setUsed(int a)
    {
        stuused[a] = 0;
    }

    void setNUsed(int a)
    {
        stuused[a] = 1;
    }

    bool allDid()
    {
        for (int i = 0; i < n; i++)
        {
            if (stuused[i] == 1)
                return false;
        }
        return true;
    }

    bool used(int a)
    {
        return stuused[a] == 0;
    }

    bool operator()(const Qdata &s1, const Qdata &s2)
    {
        return s1.diffs > s2.diffs;
    }
};

int main()
{
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> qdif >> wdif >> edif >> rdif;
        vector<mbti> students;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            students.push_back(getMBTI(s));
        }

        if (n == 2)
        {
            cout << getDif(students[0], students[1]) << "\n";
        }
        else
        {
            priority_queue<Qdata, vector<Qdata>, Qdata> q;
            bitset<501> b;
            Qdata a;
            a.diffs = 0;
            q.push(a);

            while (!q.empty())
            {
                Qdata qf = q.top();
                q.pop();
                // cout << "Q";

                if (qf.allDid())
                {
                    cout << qf.diffs << "\n";
                    break;
                }

                for (int i = 0; i < n; i++)
                {
                    if (qf.used(i))
                        continue;
                    qf.setUsed(i);

                    for (int j = i + 1; j < n; j++)
                    {
                        if (qf.used(j))
                            continue;

                        ull d = getDif(students[i], students[j]);
                        qf.diffs += d;
                        qf.setUsed(j);
                        q.push(qf);
                        qf.diffs -= d;
                        qf.setNUsed(j);
                    }

                    qf.setNUsed(i);
                }
            }
        }
    }
}