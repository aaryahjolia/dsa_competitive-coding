#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define vi vector<ll>
#define vpp vector<pii>
#define ff first
#define ss second
#define mii map<int, int>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f //to be approximately a 19-bit value.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi a(n);
        for (auto &i : a)
            cin >> i;
        vi m(n,-1) , ans(n,0);
        //m --> storing parity of indexes
        for(int i=0;i<n;i++){
            if(m[a[i]-1] == -1) // first occurance 
                m[a[i]-1] = i&1;
            if(m[a[i]-1] != (i&1) ){ //changing when old parity is not equal to current parity
                ans[a[i]-1]++;
                m[a[i]-1]=i&1;
            }
        }
        for(int i=0;i<n;i++)
            if(m[i]!=-1)ans[i]++;
        
        for(auto &i:ans) cout<<i<<" ";
        cout<<endl;
    }
}
//  i&1
//1 2 1 1 2 3 1
//0 1 0 1 0 1 0
//*     *     *
//1 2 3 4 5 6 7
//3 2 1 0 0 0 0
//Alternate index parity
