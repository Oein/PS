#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
 
char map[12][6];
int ans = 0;
bool bombFlag = false;
 
queue<pair<int, int>> q;
int visited[12][6];
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int safe(int x, int y)
{
    if(x >= 0 && x < 12 && y >= 0 && y < 6)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void down()
{
    for(int j = 0; j < 6; j++)
    {
        for(int i = 11; i >= 0; i--)
        {
            if(map[i][j] != '.')
            {
                for(int k = 11; k > i; k--)
                {
                    if(map[k][j] == '.')
                    {
                        map[k][j] = map[i][j];
                        map[i][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}
 
void bomb(int x, int y, char color)
{
    int cnt = 0;
    vector<pair<int, int>> crash;
    
    visited[x][y] = 1;
    q.push({x, y});
    
    crash.push_back({x, y});
    cnt++;
    
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int xpos = x+dx[i];
            int ypos = y+dy[i];
            
            if(safe(xpos, ypos) == 1 && visited[xpos][ypos] == 0 && map[xpos][ypos] == color)
            {
                visited[xpos][ypos] = 1;
                q.push({xpos, ypos});
                
                crash.push_back({xpos, ypos});
                cnt++;
            }
        }
    }
    
    if(cnt >= 4)
    {
        for(int i = 0; i < crash.size(); i++)
        {
            map[crash[i].first][crash[i].second] = '.';
        }
        
        bombFlag = true;
    }
}
 
int main(void)
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cin >> map[i][j];
        }
    }
    
    while(1)
    {
        bombFlag = false;
        bool breakFlag = true;
        
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(visited[i][j] == 0 && map[i][j] != '.')
                {            
                     bomb(i, j, map[i][j]);
                }
            }
        }
        
        if(bombFlag == true)
        {
            breakFlag = false;
            ans++;                                
        }
        
        if(breakFlag == true)
        {
            cout << ans;
            break;
        }
        
        down();
    }
    
    return 0; 
}
