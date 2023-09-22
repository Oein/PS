#include <stdio.h>
int main(){
    int n , m;
    scanf("%d %d" , &n , &m);
    for(int i = 0;i < n;i++){
        if(i % 2 == 0){
            for(int j = 1;j <= m;j++){
                printf("%d " , i * m + j);
            }
        }else{
            for(int j = m;j >= 1;j--){
                printf("%d " , i * m + j);
            }
        }
        
        printf("\n");
    }
}