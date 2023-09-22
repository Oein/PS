#include <iostream>
#include <vector>

using namespace std;

int main(){
    bool debug = false;

    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0 , m = 0; //n
    vector <vector<int>> acc;

    cin >> n >> m;

    vector<int> temp;
    for(int i = 0;i <= n;i++){
        temp.push_back(0);
    }
    acc.push_back(temp);

    for(int i = 1;i <= n;i++){
        vector<int> inputed_datas;
        inputed_datas.push_back(0);
        for(int j = 1;j <= n;j++){
            int input = 0;
            cin >> input;
            inputed_datas.push_back(input + inputed_datas[j-1]);
        }
        acc.push_back(inputed_datas);
    }

    for(int i = 0;i < acc.size();i++){
        if(i == 0) continue;
        if(i == 1) continue;

        for(int j = 0;j < acc.size();j++){
            acc[i][j] += acc[i - 1][j];
        }
    }

    if(debug){
        for(vector<int> i : acc){
            for(int j : i){
                cout << j << "\t";
            }
            cout << "\n";
        }

         cout << "\n";
    }

    /* --------------------- */

    for(int i = 0; i < m;i++){
        int start_y = 0 , end_y = 0 , start_x = 0 , end_x = 0;
        cin >> start_y >> start_x >> end_y >> end_x;

        int full_size = acc[end_y][end_x];
        int cut_d1 = acc[end_y][start_x - 1];
        int cut_d2 = acc[start_y - 1][end_x];
        int add_d1 = acc[start_y - 1][start_x - 1];

        if(debug){
            cout << full_size << "  ";
            cout << cut_d1 << "  ";
            cout << cut_d2 << "  ";
            cout << add_d1 << "  ";
        }

        cout << full_size - cut_d1 - cut_d2 + add_d1 << '\n';
    }
}