// A WINNER IS A DREAMER WHO NEVER GIVES UP !!! 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
              
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll l=a[0],r=a[n-1],j=n-1,i=0,c=2,ans=0;
        do
        {
            if(l<r)
            {
                i++;
                l+=a[i];
                c++;
            }
            else if(l>r)
            {
                j--;
                r+=a[j];
                c++;
            }
            else
            {
                ans=c;
                i++;
                j--;
                if(i>=j)
                {
                    break;
                }
                l+=a[i];
                r+=a[j];
                c+=2;
            }
            if(i>=j)
            {
                break;
            }
        }
        while(true);
        if(n==1)
        cout<<0<<endl;
        else
        cout<<ans<<endl;
    }
}
