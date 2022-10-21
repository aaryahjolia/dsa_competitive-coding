#include <bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main() {
     int t;
    cin>>t;
    while(t--){
    ll int hc,dc,mc,dm,k,w,a;
     cin>>hc>>dc;
     cin>>mc>>dm;
     cin>>k>>w>>a;
     int flag=1;
     for(int i=0;i<=k;i++){
        ll int Hc=hc+(i*a);
        ll int Dc=dc+((k-i)*w);
        ll int c=(mc/Dc)+(mc%Dc!=0);
        ll int m=(Hc/dm)+(Hc%dm!=0);
        if(c<=m)
        {
            cout<<"YES"<<endl;
            flag=0;
            break;
        }
     }
     if(flag)
     cout<<"NO"<<endl;

    }
}
