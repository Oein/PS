#include<bits/stdc++.h>

using namespace std;

int n = 0 , m = 0;

void print_all_number_of_cases(string data , int step){
    if(step == m){
        string out_data = "";
        for(int i = 0;i < data.length();i++){
            out_data = out_data +  data[i] + " ";
        }

        out_data = out_data.substr(0 , out_data.length() - 1);

        cout << out_data << "\n";
        return;
    }

    for(int i = data.length() == 0 ? 1 : data[data.length() - 1] - '0';i <= n;i++){ // 1 ~ n 까지 반복
        print_all_number_of_cases(data + to_string(i) , step + 1);
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    print_all_number_of_cases("" , 0);
}