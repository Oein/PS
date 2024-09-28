#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

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

#define dout   \
    if (false) \
    cout

struct Pos
{
    int x;
    int y;
};

struct Boom
{
    int x;
    int y;
    int p;
};

int n, k;

class Range
{

public:
    int st;
    int ed;

    Range(int st, int ed)
    {
        this->st = st;
        this->ed = ed;

        this->st = min(n, max(1, this->st));
        this->ed = min(n, max(1, this->ed));
    }

    bool canCombine(Range r)
    {
        return this->ed >= r.st || r.ed >= this->st;
    }

    Range combine(Range r)
    {
        return Range{min(this->st, r.st), max(this->ed, r.ed)};
    }

    bool operator<(const Range &r) const
    {
        if (this->st == r.st)
            return this->ed < r.ed;
        return this->st < r.st;
    }

    string toString()
    {
        return "Range<" + to_string(st) + " ~ " + to_string(ed) + ">";
    }

    ull size()
    {
        return (ull)ed + 1LL - (ull)st;
    }
};

map<int, int> xZip;
map<int, int> yZip;

map<int, int> xUnzip;
map<int, int> yUnzip;

int zipX(int x)
{
    if (xZip.find(x) == xZip.end())
    {
        xUnzip[xZip.size()] = x;
        xZip[x] = xZip.size();
    }
    return xZip[x];
}

int zipY(int y)
{
    if (yZip.find(y) == yZip.end())
    {
        yUnzip[yZip.size()] = y;
        yZip[y] = yZip.size();
    }
    return yZip[y];
}

vector<Range> rangesByY[300005];
vector<Range> rangesByX[300005];

ull mnus = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dout.tie(0);
    cin >> n >> k;
    vector<Boom> booms;
    vector<int> xLi;
    vector<int> yLi;
    for (int i = 0; i < k; i++)
    {
        int x, y, p;
        cin >> x >> y >> p;
        booms.push_back(Boom{x, y, p});

        xLi.push_back(x);
        yLi.push_back(y);
    }

    sort(xLi.begin(), xLi.end());
    sort(yLi.begin(), yLi.end());

    for (auto x : xLi)
        zipX(x);
    for (auto y : yLi)
        zipY(y);

    for (auto boom : booms)
    {
        int x = boom.x;
        int y = boom.y;
        int p = boom.p;

        rangesByX[zipX(x)].push_back(Range{(y - p), (y + p)});
        rangesByY[zipY(y)].push_back(Range{(x - p), (x + p)});

        dout << "<Boom X={" << x << "} Y={" << y << "} P={" << p << "}>\n";
        dout << "X | " << rangesByX[zipX(x)].back().toString() << "\n";
        dout << "Y | " << rangesByY[zipY(y)].back().toString() << "\n";
    }

    // free booms
    booms.clear();

    dout << "\n";

    // combine Y Based (T: n * logn)
    for (int i = 0; i < yZip.size(); i++)
    {
        sort(rangesByY[i].begin(), rangesByY[i].end());
        vector<Range> newRanges;
        for (int j = 0; j < rangesByY[i].size(); j++)
        {
            if (newRanges.size() == 0 || !newRanges.back().canCombine(rangesByY[i][j]))
            {
                newRanges.push_back(rangesByY[i][j]);
            }
            else
            {
                newRanges.back() = newRanges.back().combine(rangesByY[i][j]);
            }
        }
        rangesByY[i] = newRanges;

        for (auto x : newRanges)
            mnus += x.size();

        dout << "Y " << yUnzip[i] << " | ";
        for (int j = 0; j < rangesByY[i].size(); j++)
        {
            dout << rangesByY[i][j].toString() << " ";
        }
        dout << "\n";
    }

    dout << "\n";

    // combine X Based (T: n * logn)
    for (int i = 0; i < xZip.size(); i++)
    {
        sort(rangesByX[i].begin(), rangesByX[i].end());
        vector<Range> newRanges;
        for (int j = 0; j < rangesByX[i].size(); j++)
        {
            if (newRanges.size() == 0 || !newRanges.back().canCombine(rangesByX[i][j]))
            {
                newRanges.push_back(rangesByX[i][j]);
            }
            else
            {
                newRanges.back() = newRanges.back().combine(rangesByX[i][j]);
            }
        }
        rangesByX[i] = newRanges;

        for (auto x : newRanges)
            mnus += x.size();

        dout << "X " << xUnzip[i] << " | ";
        for (int j = 0; j < rangesByX[i].size(); j++)
        {
            dout << rangesByX[i][j].toString() << " ";
        }
        dout << "\n";
    }

    // get double counted (T: n * logn)
    for (int i = 0; i < xZip.size(); i++)
    {
        const int myX = xUnzip[i];
        for (int j = 0; j < rangesByX[i].size(); j++)
        {
            Range range = rangesByX[i][j];

            // loop through y ranges
            for (int k = 0; k < yZip.size(); k++)
            {
                const int myY = yUnzip[k];
                for (int l = 0; l < rangesByY[k].size(); l++)
                {
                    Range rangeY = rangesByY[k][l];

                    if (rangeY.st <= myX && myX <= rangeY.ed && range.st <= myY && myY <= range.ed)
                    {
                        mnus--;
                    }
                }
            }
        }
    }

    dout << "\n";
    dout << "MNUS | " << mnus << "\n";
    cout << (ull)n * n - mnus << "\n";
}
