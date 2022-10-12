#include <bits/stdc++.h>
using namespace std;
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define fastread()                                     \
    (ios_base::sync_with_stdio(false), cin.tie(NULL)); \
    cout.tie(NULL);
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ll long long int
#define MOD 1000000007
const int N = 2*1e5+10;


int main() {
    fastread();
    w(t){
        // cout<<endl;
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        map<int,vector<int>> g;
        for(int i=0;i<n;i++){
            cin>>a[i];
           g[a[i]].pb(i+1);
           }
           
        while(m--){
            int x,y;
            cin>>x>>y;
            bool flag=false;
            if(g[x].size()==0 || g[y].size()==0) {
                cout<<"NO"<<endl;
            }
            else{
				if(g[x][0]>g[y][g[y].size()-1]) cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
            }
        }
    }
}
