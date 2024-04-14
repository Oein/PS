#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, mini = 2000000005;
	cin >>n;
	for(int i = 0;i < n;i++){
		int a , b;
		cin >> a >>b;
		if(a > b){
			continue;
		}
		mini = min(mini , max(a , b));
	}
	if(mini == 2000000005){
		cout << "-1";
		return 0;
	}
	cout << mini;
}
