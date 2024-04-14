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

int n;

vector<int> xposes;
vector<int> yposes;

struct Square
{
    int x;
    int y;
    int xed;
    int yed;

    Square(double x, double y, double xed, double yed) : x(x), y(y), xed(xed), yed(yed) {}

    bool includes(Square &other)
    {
        return x <= other.x && y <= other.y && xed >= other.xed && yed >= other.yed;
    }

    string to_string()
    {
        return "<Square x={" + std::to_string(x) + "} y={" + std::to_string(y) + "} xed={" + std::to_string(xed) + "} yed={" + std::to_string(yed) + "}>";
    }
};

vector<Square> squares;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double lbx, lby, w, h;
        cin >> lbx >> lby >> w >> h;
        lbx *= 10;
        lby *= 10;
        w *= 10;
        h *= 10;

        xposes.push_back(lbx);
        xposes.push_back(lbx + w);
        yposes.push_back(lby);
        yposes.push_back(lby + h);
        squares.push_back({lbx, lby, lbx + w, lby + h});
    }

    sort(xposes.begin(), xposes.end());
    sort(yposes.begin(), yposes.end());

    xposes.erase(unique(xposes.begin(), xposes.end()), xposes.end());
    yposes.erase(unique(yposes.begin(), yposes.end()), yposes.end());

    // for (auto s : squares)
    //     printf("(%d, %d) (%d, %d)\n", s.x, s.y, s.xed, s.yed);

    double sizes = 0;

    for (int i = 0; i + 1 < xposes.size(); i++)
        for (int j = 0; j + 1 < yposes.size(); j++)
        {
            int x = xposes[i];
            int y = yposes[j];
            int xed = xposes[i + 1];
            int yed = yposes[j + 1];
            // printf("(%d, %d) (%d, %d)\n", x, y, xed, yed);

            Square sq(x, y, xed, yed);

            for (auto &s : squares)
                if (s.includes(sq))
                {
                    // printf("%s\n includes %s\n", s.to_string().c_str(), sq.to_string().c_str());
                    // printf(" size: %f\n\n", (xed - x) * (yed - y) / 100.0);
                    sizes += (xed - x) * (yed - y);

                    break;
                }
        }

    int sz = sizes;
    printf("%d", sz / 100);
    if (sz % 100)
    {
        int pc = sz % 100;
        if (pc < 10)
            printf(".0%d", pc);
        else
            printf(".%d", pc);
    }
}
