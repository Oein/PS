#include <iostream> 
using namespace std; 
int main(void) { 
    int max = -1, min = 1001, tmp, n; 
    cin >> n; 
    for (int i = 0; i < n; i++) { 
        cin >> tmp; 
        if (max < tmp) 
            max = tmp; 
        if (min > tmp) 
            min = tmp; 
    } 
    cout << max - min; 
}