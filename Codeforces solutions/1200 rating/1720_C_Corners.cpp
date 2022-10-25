#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int i,j,mini=5,sum,c=0,a[n][m];
        string str;
        for(i=0;i<n;++i)
        {
            cin>>str;
            for(j=0;j<str.size();++j)
            {
                if(str[j]=='0')
                a[i][j]=0;
                else
                {
                    a[i][j]=1;
                    ++c;
                }
            }
        }
        for(i=0;i<n-1;++i)
        {
            for(j=0;j<m-1;++j)
            {
                sum = a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
                if(sum<mini)
                {
                    mini=sum;
                }
                
            }
        }
        if(mini==0 || mini==1 || mini==2)
        {
            cout<<c<<"\n";
        }
        else if(mini==3)
        {
            cout<<c-1<<"\n";
        }
        else if(mini==4)
        {
            cout<<c-2<<"\n";
        }
        
    }
}
