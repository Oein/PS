#include<bits/stdc++.h>
using namespace std;
int n,cnt1=0,cnt2=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x=i;
        while(x%2==0)x/=2,cnt1++;
        while(x%5==0)x/=5,cnt2++;
    }
    printf("%d",min(cnt1,cnt2));
}