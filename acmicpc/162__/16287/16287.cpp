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
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

int w, n;
vi wei;
vi exsist_(799995, -1);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> w >> n;

	for (int i = 0; i < n; i++)
	{
		int weig;
		cin >> weig;

		wei.push_back(weig);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (wei[i] + wei[j] >= w)
				continue;

			exsist_[wei[i] + wei[j]] = j;

			if (exsist_[w - wei[i] - wei[j]] != -1)
			{
				if (exsist_[w - wei[i] - wei[j]] < i) //4개의 수가 겹치지 않는지 확인 
				{
                    // 항상 c , d > a , b 라고 가정
					cout << "YES";
                    return 0;
				}
			}
		}
	}

	cout << "NO";
}