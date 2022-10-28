#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        int i,j,k,c=0;
        for(i=1;i<=n/2;i=i*2)
        {
            for(j=0;j<n;j=j+i*2)
            {
                if(a[j]>a[j+i])
                {
                    ++c;
                    for(k=0;k<i;++k)
                    swap(a[j+k],a[j+i+k]);
                }
            }
        }
        
        if(is_sorted(a,a+n))
        {
            cout<<c<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
        
    }
}
