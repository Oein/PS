#include <bits/stdc++.h>
using namespace std;

bool compare(const string left , const string right){
    if(left.length() == right.length()){
        return left < right;
    }else{
        return left.length() < right.length();
    }
}

void printArr(vector<string> numbers){
    for(int i = 0;i < numbers.size();i++){
        if(i != 0){
            if(numbers[i] != numbers[i - 1]){
                cout << numbers[i] << "\n";
            }
        }else{
            cout << numbers[i] << "\n";
        }
    }
}

int main()
{
    int n = 0;
    vector<string> numbers;

    cin >> n;
    for(int i = 0;i < n;i++){
        string input = "";
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.begin() , numbers.end() , compare);

    printArr(numbers);
}