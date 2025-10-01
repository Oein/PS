#include <bits/stdc++.h>
using namespace std;

char arr[3072][6144];

void star(int n, int x, int y)
{
    if (n == 3)//높이가 3이라면 별을 만들어 출력한다.
    {
        //별을 그린다.
        arr[y][x] = '*';
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        arr[y + 2][x - 2] = '*';
        arr[y + 2][x - 1] = '*';
        arr[y + 2][x] = '*';
        arr[y + 2][x + 1] = '*';
        arr[y + 2][x + 2] = '*';
        return;
    }
    star(n / 2, x, y);
    star(n / 2, x - (n / 2), y + (n / 2));
    star(n / 2, x + (n / 2), y + (n / 2));
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, j;
     
    cin >> n;
 
    for (i = 0; i<n; i++){
        for (j = 0; j<2 * n; j++){
            if (j == 2 * n - 1)
                arr[i][j] = '\0';
            else
                arr[i][j] = ' ';
        }
    }
 
    star(n, n - 1, 0);
 
    //삼각형 출력
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2 * n - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
