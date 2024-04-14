#include <iostream>
using namespace std;

int N;
int arr[64][64]; // Frame

//  cutted 얼마나 픽셀이 큰지 
// 1이면 더이상 못 짜름
// y 어디 픽셀인지
// x 어디 픽셀인지
void compress(int cutted , int y , int x){
    if(cutted == 1){
        cout << arr[y][x];
        return;
    }

    bool fullZero = true;
    bool fullOne = true;

    for(int i = y;i < y + cutted;i++){
        for(int j = x;j < x + cutted;j++){
            if(arr[i][j]){
                fullZero = false;
            }else{
                fullOne = false;
            }
        }
    }

    if(fullZero){
        cout << "0";
    }
    else if(fullOne){
        cout << "1";
    }
    else{
        // 전부다 어느것이 아닐때
        cout << "("; // 더 나누는거
        compress(cutted / 2 , y , x); //왼쪽 위
        compress(cutted / 2 , y, x + cutted / 2); //오른쪽 위
        compress(cutted / 2 , y + cutted / 2 , x); //왼쪽 아래
        compress(cutted / 2 , y + cutted / 2 , x + cutted / 2); //오른쪽 아래
        cout << ")"; //그만 나누는거
    }
    return;
}

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        string str = "";
        cin >> str;
        for(int j = 0;j < N;j++){
            arr[i][j] = str[j] - '0'; // char - '0' == int
        }
    }

    compress(N , 0 , 0);
    return 0;
}