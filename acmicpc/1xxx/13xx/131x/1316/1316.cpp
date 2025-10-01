#include <bits/stdc++.h>
using namespace std;
bool wordCheck(string str){
    bool alpabet[26] = {false}; //알파벳 개수 만큼 배열을 만듭니다
                                //알파벳에 해당하는 위치를 index 0~25에 맞게 할당하기 위해
 
    for(int i=0; i<str.length(); i++){
 
        if(alpabet[str[i]-'a']){ //true 이면 이미 있었으므로 false
            return false;
 
        }else{                   //false 이면 처음 오는 알파벳 이므로 check
 
            char tmp = str[i];
            alpabet[str[i]-'a'] = true; //알파벳이 왔으면 true로 바꿔줍니다
 
            while(1){
                if(tmp != str[++i]){    //현재 알파벳과 다른 알파벳이 올때까지 탐색합니다
                    i--;
                    break;
                }
            }
 
        }
 
    }
    return true;
}
 
 
 
int main(void){
 
    int n;
    cin >> n;
 
    int count =0;
 
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
 
        if(wordCheck(str)){
            count++;
        }
 
    }
    cout << count;
 
    return 0;
}
