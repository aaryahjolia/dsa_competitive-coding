#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int s;
        scanf("%d", &s);
        int A[s];
        for(int i=0; i<s; i++)  scanf("%d", &A[i]);

        int x=A[0];
        for(int i=1; i<s;i++){
            if(A[i]>x)  x=A[i];
        }        

        int y=A[0];
        for(int i=1; i<s;i++){
            if(A[i]<y)  y=A[i];
        }    
        printf("%d\n", x-y);
    }
    return 0;
}
