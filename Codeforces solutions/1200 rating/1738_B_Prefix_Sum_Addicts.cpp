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
        ll n,k;
        cin>>n>>k;
        ll a[k];
        for(ll i=0;i<k;i++)
        {
            cin>>a[i];
        }
        vector<ll> v;
        for(ll i=k-1;i>0;i--)
        {
            v.push_back(a[i]-a[i-1]);
        }
        reverse(v.begin(),v.end());
        if(k==1)
        cout<<"Yes"<<endl;
        else if(is_sorted(v.begin(),v.end()))
        {
            if(a[0]<=(v[0]*(n-k+1)))
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }
        else
        cout<<"No"<<endl;
    }
}
