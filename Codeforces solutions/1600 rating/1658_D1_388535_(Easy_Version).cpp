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
        ll n,l,r;
        cin>>l>>r;
        n=r-l+1;
        ll a[n];
        vector<int> v(18);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            for(int j=0;j<18;j++)
            {
                if((a[i]>>j)&1)
                v[j]++;
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(int j=0;j<18;j++)
            {
                if((i>>j)&1)
                v[j]--;
            }
        }
        ll ans=0;
        for(int i=0;i<18;i++)
        {
            if(v[i]>0)
            ans+=1<<i;
        }
        cout<<ans<<endl;
    }
}
