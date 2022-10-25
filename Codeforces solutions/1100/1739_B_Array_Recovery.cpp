#include <iostream>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int d[n],a[n];
        for(int i=0;i<n;++i)
        {
            cin>>d[i];
        }
        int sum=d[0];
        a[0]=sum;
        int flag=0;
        for(int i=1;i<n;++i)
        {
            if(sum-d[i]>=0 && d[i]!=0)
            flag=1;
            else
            a[i]=sum+d[i];
            sum=a[i];
        }
        if(flag==1)
        {
            cout<<"-1\n";
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
}
