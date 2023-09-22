#include <iostream> 
#include <vector>
using namespace std; 

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    while (true)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        if (a == 0 && b == 0)break;
        cout << a + b << '\n';
    }
}
