#include<bits/stdc++.h>
using namespace std;int a,b,c,d,e=0,i,q,w=1000000,u;vector<int>f;bool g[1000005];bool h(int l){int m=0;int n=-1;for(int o:f){if(m>c)return 0;if(o<=n)continue;n=o+l-1;m++;}if(m>c)return 0;return 1;}main(){cin>>a>>b>>c>>d;for(i=0;i<d;i++){int o,p;cin>>o>>p;e=max(e,o);if(!g[p]){f.push_back(p);g[p]=1;}}sort(f.begin(),f.end());q=e;while(q<=w){int z=(q+w)/2;if(h(z)){w=z-1;u=z;}else{q=z+1;}}cout<<u;}