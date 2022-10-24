// A WINNER IS A DREAMER WHO NEVER GIVES UP !!! 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
              
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll nb,nc,ns,pb,pc,ps;
        cin>>nb>>ns>>nc>>pb>>ps>>pc;
        ll ru;
        cin>>ru;
        ll B=0,C=0,S=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='B')
            B++;
            else if(s[i]=='S')
            S++;
            else
            C++;
        }
        ll l=0,r=1e15;
        ll ans=0;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            ll totalb,totals,totalc;
            totalb=max(0LL,mid*B-nb);
            totals=max(0LL,mid*S-ns);
            totalc=max(0LL,mid*C-nc);
            ll money=totalb*pb+totalc*pc+totals*ps;
            if(money<=ru)
            {
                ans=max(mid,ans);
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}
