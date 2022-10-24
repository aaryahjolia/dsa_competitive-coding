#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, r,k;
        scanf("%d %d", &n, &r);
            int A[n][n];
    
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {                
                        A[i][j]= 46;                
                }
            }
            if(n%2==0)
            k=n/2;
            else
            k=n/2+1;
            if(n==1&&r==1)
            printf("R\n");
            else if(r>k)
            printf("-1\n");
            else
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(r>0&&i==j)
                        {
                            A[i++][j++]= 82; 
                            r--;
                        }
                    }
                }
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        printf("%c", A[i][j]);
                    }
                    printf("\n");
                }
            }
    }
}
