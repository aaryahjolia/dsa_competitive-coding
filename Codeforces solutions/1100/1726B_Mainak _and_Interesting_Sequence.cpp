#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define ll long long int
#define MOD 1000000007
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define vi vector<int>
#define fov(x,a) for(auto &x:a) cin>>x
#define vii vector<vector<ll>>
#define vpp vector<pair<int,pii>>
#define adj map<int,vector<int>> 
#define vp vector<pii>
#define vb vector<bool>
#define ff first
#define ss second
#define mii map<ll, ll>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rev(s) reverse(s.begin(),s.end())
#define lower(s) transform(s.begin(),s.end(), s.begin(), ::tolower)
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f //to be approximately a 19-bit value.
#define fastread()                                     \
    (ios_base::sync_with_stdio(false), cin.tie(NULL)); \
    cout.tie(NULL)
 
 
int main() {
    w(t){
      int n,m;
      cin>>n>>m;
      if(m<n) cout<<"No\n";
      else{
        if(!(m%n)){
          cout<<"Yes\n";
          int ans = m/n;
          while(n--) cout<<ans<<" "; 
          cout<<"\n";
        }
        else if(!(n%2) && (m%2) ) cout<<"No\n";
        else if(!(n%2) && !(m%2)) {
          cout<<"Yes\n";
            n-=2;
            m-=n;
            while(n--) cout<<1<<" ";
            cout<<(m/2)<<" "<<(m/2);
            cout<<"\n";
        }
        else{
          cout<<"Yes\n";
            n-=1;
            m-=n;
            while(n--) cout<<1<<" ";
            cout<<m;
            cout<<"\n";
        }
      }
    }
}
 
 
