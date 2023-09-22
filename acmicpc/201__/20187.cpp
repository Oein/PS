#include <bits/stdc++.h>

using namespace std;

//max inputs
char a[31];

//max datas
int ans[2005][2005];

int main()
{
    
    //make program fast
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    
    // get k by cin
    int k; 
    cin >> k;
    
    // get where to flip
    for(int i=0; i<2*k; i++){ cin >> a[i]; }
    
    // where to remove?
    cin >> ans[0][0];
    int x = 1;
    int y = 1;
    
    // loop in inputs 
    // why minus?
    // I have to make it back
    // So i gets minus
    for(int i=2*k-1; i>=0; i--){
        
        //by cases
        
        // flip paper left
        if(a[i]=='L'){
            //doing something
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    ans[i][2*y-1-j] = ans[i][j] ^ 1;
                }
            }
            
            // make what is next
            //paper size up
            y *= 2;
        }
        
        // flip paper right
        if(a[i]=='R'){
            //doing something
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    ans[i][j+y] = ans[i][j];
                }
            }
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    ans[i][j] = ans[i][2*y-1-j] ^ 1;
                }
            }
            
            // make what is next
            //paper size up
            y *= 2;
        }
        
        // flip paper down
        if(a[i]=='D'){
            //doing something
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    ans[i+x][j] = ans[i][j];
                }
            }
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    ans[i][j] = ans[2*x-1-i][j] ^ 2;
                }
            }
            
            // make what is next
            //paper size up
            x *= 2;
        }
        
        // flip paper up
        if(a[i]=='U'){
            //doing something
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    ans[2*x-1-i][j] = ans[i][j] ^ 2;
                }
            }
            
            // make what is next
            //paper size up
            x *= 2;
        }
        
    }
    
    //Print ans
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}