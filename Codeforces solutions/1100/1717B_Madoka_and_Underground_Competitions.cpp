#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int32_t main(){
    int t;
    cin>>t;
    while(t--){
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    int ans=(r+c-2)%k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%k==ans)
            cout<<'X';
            else
            cout<<'.';
        }
        cout<<endl;
    }
    }
}
