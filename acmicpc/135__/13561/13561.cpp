#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;
#define infData 2000000000

int k , n , cnt , kind[100001];
// 가게의 종류
// 가게의 숫자
// 가게 종류의 수
// 가게종류별 개수

vector<pi_i> points;
// points<위치 , 종류>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> n;
	
	for (int i = 0; i < n; i++) {
		int q, w;
		cin >> q >> w;
		points.push_back({ q,w });
	}
	sort(points.begin(), points.end());

	int left = 0,right=0;
	
	pi_i res = make_pair(infData, infData); // 길이, 위치
	while (right < n) {
		if (!kind[points[right].second]) cnt++;

		kind[points[right].second]++;
		
		if (cnt == k) {
			while (true) {
				ll dist = points[right].first + points[left].first;
				if (res.first > points[right].first - points[left].first) { // better choise
					ll t = dist / 2;
					if (dist % 2 != 0 && dist < 0) {
						t -= 1;
					}
					res = {points[right].first - points[left].first, t};
				}
				cnt--;
				kind[points[left].second]--;
				left++;
				if (kind[points[left-1].second] == 0 || left>=right) break; // 가게중 종류가 없어지거나 , 왼쪽이 오른쪽을 넘으면
				else cnt++;
				
			}
		}
		right++;
	}

	cout << res.second;
}