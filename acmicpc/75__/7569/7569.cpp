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

int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct Pos
{
    int x;
    int y;
    int z;
};

int height, width, top;

int arr[100][100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> width >> height >> top;

    queue<Pos> q;

    for (int i = 0; i < top; i++)
        for (int j = 0; j < height; j++)
            for (int k = 0; k < width; k++)
            {
                cin >> arr[i][j][k];

                if (arr[i][j][k] == 1)
                    q.push({k, j, i});
            }

    int day = 0;
    while (!q.empty())
    {
        unsigned long long qs = q.size();

        while (qs--)
        {
            Pos qf = q.front();
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int nx = qf.x + dx[i];
                int ny = qf.y + dy[i];
                int nz = qf.z + dz[i];

                if (nx < 0 || nx >= width || ny < 0 || ny >= height || nz < 0 || nz >= top)
                    continue;

                if (arr[nz][ny][nx] == 0)
                {
                    arr[nz][ny][nx] = 1;
                    q.push({nx, ny, nz});
                }
            }
        }

        day++;
    }

    for (int i = 0; i < top; i++)
        for (int j = 0; j < height; j++)
            for (int k = 0; k < width; k++)
                if (arr[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }

    cout << day - 1;
}
