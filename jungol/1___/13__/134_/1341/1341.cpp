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
            for(int i = a;i <= b;i++){
                for(int j = 1;j <= 3;j++){
                    printf("%d * %d = %2d   " , i , j , j * i);
                }
                printf("\n");
                for(int j = 4;j <= 6;j++){
                    printf("%d * %d = %2d   " , i , j , j * i);
                }
                printf("\n");
                for(int j = 7;j <= 9;j++){
                    printf("%d * %d = %2d   " , i , j , j * i);
                }
                printf("\n\n");
            }
        }else{
            for(int i = a;i >= b;i--){
                for(int j = 1;j <= 3;j++){
                    printf("%d * %d = %2d   " , i , j , j * i);
                }
                printf("\n");
                for(int j = 4;j <= 6;j++){
                    printf("%d * %d = %2d   " , i , j , j * i);
                }
                printf("\n");
                for(int j = 7;j <= 9;j++){
                    printf("%d * %d = %2d   " , i , j , j * i);
                }
                printf("\n\n");
            }
        }
        return 0;
    }
}