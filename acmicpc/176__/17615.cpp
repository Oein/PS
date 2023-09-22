#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Rcnt=0,Bcnt=0;
    string s;
    
    cin>>N>>s;
    for(auto c:s)
    {
        if(c=='R')Rcnt++;
        else Bcnt++;
    }
    
    int minN=INT_MAX;
    int cnt=0;
    int idx=0;
    while(s[idx++]=='R'){
        cnt++;
    }
    minN = min(minN,Rcnt-cnt);
    //right에 R를 모은다.
    idx=N-1;
    cnt=0;
    while(s[idx--]=='R'){
        cnt++;
    }
    minN=min(minN,Rcnt-cnt);
    //left에 B를 모은다.
    idx=0;
    cnt=0;
    while(s[idx++]=='B'){
        cnt++;
    }
    minN=min(minN,Bcnt-cnt);
    //right에 B를 모은다.
    idx=N-1;
    cnt=0;
    while(s[idx--]=='B'){
        cnt++;
    }
    minN=min(minN,Bcnt-cnt);

    cout<<minN;
}
