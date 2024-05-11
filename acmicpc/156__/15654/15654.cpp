#include<bits/stdc++.h>

using namespace std;

int n = 0 , m = 0;

int* replaceData;

void print_all_number_of_cases(string data , int step){
    if(step == m){
        string out_data = "";
        for(int i = 0;i < data.length();i++){
            out_data = out_data + to_string(replaceData[data[i] - '0' - 1]) + " ";
        }

        out_data = out_data.substr(0 , out_data.length() - 1);

        cout << out_data << "\n";
        return;
    }

    for(int i = 1;i <= n;i++){ // 1 ~ n 까지 반복
        bool is_ok = true;
        for(int j = 0;j < data.length();j++){ // 되는지 검사 (중복 검사)
            if(data[j] - '0' == i){
                is_ok = false;
            }
        }
        if(is_ok == true) {
            // cout << "Debug : " << data + to_string(i) << "\n";
            print_all_number_of_cases(data + to_string(i) , step + 1);
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    replaceData = new int[n];
    for(int i = 0;i < n;i++){
        int inputed_data = 0;
        cin >> inputed_data;
        replaceData[i] = inputed_data;
    }

    sort(replaceData , replaceData + n);

    print_all_number_of_cases("" , 0);
}