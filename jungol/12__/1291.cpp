#include <stdio.h>
int main(){
    while(1){
        int a , b;
        scanf("%d %d" , &a , &b);
        if(a < 2 || a > 9 || b < 2 || b > 9) {
            printf("INPUT ERROR!\n");
            continue;
        }
        if(a < b){
            for(int i = 1;i <= 9;i++){
                for(int j = a;j <= b;j++){
                    printf("%d * %d = %2d   " , j , i , j * i);
                }
                printf("\n");
            }
        }else{
            for(int i = 1;i <= 9;i++){
                for(int j = a;j >= b;j--){
                    printf("%d * %d = %2d   " , j , i , j * i);
                }
                printf("\n");
            }
        }
        return 0;
    }
}