#include <iostream>
#include <vector>
#include "climits"

using namespace std;
using ll = long long;

int main() {
    int n,k;
    string x;
    cin >> n >> k >> x;
    vector<int> hamburgers;
    vector<int> persons;
    for(int i = 0;i < x.size();i++) {
        if(x[i] == 'H') {
            hamburgers.push_back(i);
        }else{
            persons.push_back(i);
        }
    }
    int ans = 0;
    int hamst = 0;
    int hamadd = 0;
    for(auto person : persons) {
        if(hamburgers.size() == 0) break;
        while (hamst < hamburgers.size()) {
            int hamadind = hamadd + hamst;
            int diff = abs(person - hamburgers[hamadind]);
            if(diff <= k) {
                hamst = hamadind + 1; // 다음 햄버거 read 지점++
                hamadd = 0; // 햄버거 idx dd = 0
                ans++; // 정답!
                // 성공할 경우
                break;
            }
            if(diff > k && hamburgers[hamadind] < person) {
                hamst++;
                continue; // 햄버거,사람 으로 정렬 / k 보다 멀리 있음 -> 다음 햄버거
            }
            if(diff > k && hamburgers[hamadind] > person) {
                // 사람, 햄버거 으로 정렬 / k 보다 멀리 있음 -> 더이상 갈곳이 없음
                break;
            }
            hamadd++;
        }
    }
    
    cout << ans;
}
