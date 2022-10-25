#include<stdio.h>

int main(){

    int t;
    scanf("%d", &t);
    int A[6], B[t];
    int x, s=0;
    for(int i=0; i<t; i++){
        for(x=0; x<6; x++){
            scanf("%d", &A[x]);
        }

        int dr=1, dc=1, move=0;
        while(A[2]!=A[4] && A[3]!=A[5]){

            if(A[2]==A[0])  dr=-1;
            if(A[3]==A[1])  dc=-1;

            A[2]=A[2]+dr;
            A[3]=A[3]+dc;
            move++;
        }
    
        B[s++]=move;

   }
   for(int i=0; i<t; i++){
       printf("%d\n", B[i]);
   }

    return 0;
}
