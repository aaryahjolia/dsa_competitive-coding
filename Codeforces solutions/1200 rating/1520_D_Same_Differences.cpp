// A WINNER IS A DREAMER WHO NEVER GIVES UP !!! 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
              
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll> m;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]-i]++;
        }
        ll sum=0;
        for(auto i:m)
        {
            sum+=i.second*(i.second-1)/2;
        }
        cout<<sum<<endl;
    }
}
