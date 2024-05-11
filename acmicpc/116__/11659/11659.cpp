#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0 , m = 0; //n
    vector <int> acc;

    acc.push_back(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int inputed_data = 0;
        cin >> inputed_data;

        if(i < 2){
            acc.push_back(inputed_data);
        }else{
            acc.push_back(acc[i - 1] + inputed_data);
        }
    }

    /* for(int i = 0; i < acc.size();i++){
        cout << acc[i] << "   ";
    } */

    for(int i = 0;i < m;i++){
        int start = 0 , end = 0;
        cin >> start >> end;

        cout << acc[end] - acc[start - 1] << '\n';
    }
}