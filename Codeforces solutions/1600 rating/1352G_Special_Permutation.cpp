#include <bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v,v1;
            v.push_back(3);
            v.push_back(1);
            v.push_back(4);
            v.push_back(2);
        if(n<4)
        cout<<-1<<endl;
        else{
            for(int i=5;i<=n;i++)
            {
                if(i%2==0)
                v.push_back(i);
                else
                v1.push_back(i);
            }
            
        
        reverse(v1.begin(),v1.end());
        for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;
        }

    }
}
