#include <stdio.h>
int main(void){
    int i, j, k;
    int count=0;
    int bonus=0;
    int lotto[5][6]={
        {1,2,3,4,5,6},
        {10,15,25,35,40,42},
        {1,9,11,22,23,25},
        {9,28,31,34,35,36},
        {1,9,23,28,33,35}};
    int number[7]={0,};
    
    printf("금주의 로또 번호를 입력하세요 -> ");
    for(int i=0;i<6;i++){
        scanf("%d", &number[i]);
    }
    printf("보너스 번호를 입력하세요 -> ");
    scanf("%d", &number[6]);
    
    printf("\n홍길동님의 로또 당첨 결과는 다음과 같습니다.\n\n");
    
    for(i=0; i<5; i++){
        printf("%d세트 번호<", i+1);
        for(j=0; j<6; j++){
            printf("%3d", lotto[i][j]);
            for(k=0;k<6;k++){
                if(lotto[i][j]==number[k]){
                    count++;
                }
            }
            if(lotto[i][j]==number[6]){
                bonus=1;
            }
        }
        printf("> -> ");
        
        for(j=0; j<6; j++){
            for(k=0;k<6;k++){
                if(lotto[i][j]==number[k]){
                    printf("%d ", number[k]);
                    break;
                }
            }
            if(k==6){
                if(lotto[i][j]==number[6]&&count==5&&bonus==1)
                    printf("%d ", number[6]);
                else
                    printf("X ");
            }
 
        }
        
        if(lotto[i][j]==number[6]&&count==5&&bonus==1){
            printf("%d ", number[6]);
        }
        
        if(count==6){
            printf("<1등>");
        }
        else if(count==5 && bonus==1){
            printf("<2등>");
        }
        else if(count==5){
            printf("<3등>");
        }
        else if(count==4){
            printf("<4등>");
        }
        else if(count==3){
            printf("<5등>");
        }
        else{
            printf("<꽝>");
        }
        bonus=0;
        count=0;
        
        printf("\n");
    }
}


