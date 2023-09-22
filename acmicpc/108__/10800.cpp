#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ball{
    int color;
    int size;
    int idx;
    int res;
};

bool sort_func(Ball a , Ball b){
    if(a.size < b.size) return true;
    else return false;
}

bool sort_func_two(Ball a , Ball b){
    if(a.idx < b.idx) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0;
    cin >> n;
    
    vector<Ball> balls;
    
    int high_color = 0;
    
    for(int i = 0;i < n;i++){
        Ball a_ball;
        cin >> a_ball.color >> a_ball.size;
        a_ball.idx = i;
        a_ball.res = 0;
        balls.push_back(a_ball);
        if(a_ball.color > high_color) high_color = a_ball.color;
    }
    
    sort(balls.begin() , balls.end() , sort_func);
    
    vector<int> color_sum(high_color+1);
    
    int sum = 0;
    
    for(int i = 0;i < n;i++){
        int add = sum;
        vector<int> color_sum_copy = color_sum;
        
        int did = -1;
        
        for(int j = i; j<n &&  balls[i].size == balls[j].size; j++)
        {
            balls[j].res = add - color_sum[balls[j].color];
            color_sum_copy[balls[j].color] += balls[j].size;
            sum += balls[i].size;
            did++;
        }
        
        i += did;
        
        color_sum = color_sum_copy;
    }
    
    sort(balls.begin() , balls.end() , sort_func_two);
    
    for(int i = 0;i < n;i++){
        cout << balls[i].res << "\n";
    }
}
