#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main(){
   
        ll int n,m,sum=0,c=0;
        cin>>n>>m;
        vector<int> v;
        while(n--){
            int a,b;
            cin>>a>>b;
            v.push_back(abs(a-b));
            sum+=a;
        }
          sort(v.begin(), v.end(), greater<int>());
        if(sum<=m){
            cout<<0<<endl;
        }
        else{
          
            // auto ik=mp.begin();
           for(int i=0;i<v.size();i++){
                // cout<<sum<<endl;
                if(sum>m){
                    c++;
                sum-=v[i];
                }
            }
            if(sum<=m)
            cout<<c<<endl;
            else
            cout<<-1<<endl;
        }
}
