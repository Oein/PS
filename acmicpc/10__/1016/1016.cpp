#include <iostream>
using namespace std;
long long number[1000001];

int main(void) {
        long long min, max;
        int cnt = 0;

        cin >> min >> max;

        for (long long i = 2; i * i <= max; i++) {
                long long n = min / (i * i);
                
                if (min % (i * i)) n++;

                while (n * i * i <= max) {
                        number[n * i * i - min] = 1;
                        n++;
                }
        }

        for (int i = 0; i <= max - min; i++) {
                if (number[i] == 0) cnt++;
        }

        cout << cnt;
}