#include <bits/stdc++.h>

using namespace std;

int main(){
    long long l[5000]; //용액들 사이즈가 커서 long long 으로
    int N;
    cin >> N;
    for(int i=0; i<N; i++){ // 입력
        cin >> l[i];
    }
    sort(l, l+N); // 배열 sort

    // 후훗 ans를 3개로 나눴지
    long long x, a, n, s, sum;
    sum = LLONG_MAX;

    for(int i=0; i<N-2; i++){ // 2개는 무조건 구해야 하니까
        x = l[i]; // 고정
        int left = i+1;
        int right = N-1;
        while(left<right){ //2분 탐색
            long long temp = x + l[left] + l[right];
            if(sum > abs(temp)){ // 합이 이전 보다 작으면
                sum = abs(temp); // 넣기
                a = x;
                n = l[left];
                s = l[right];
            }
            if(temp < 0) left ++;
            else if(temp > 0) right --;
            else {i = N; break;} // 같으면 break , i = N(for 끝네기)
        }
    }

    cout << a << " " << n << " " << s << "\n";

    return 0;
}