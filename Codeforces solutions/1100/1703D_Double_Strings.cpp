#include <bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s[n];
        map<string,int> mp;
        for(int i=0;i<n;i++){
            cin>>s[i];
            mp[s[i]]++;
        }
    
        string c="";
        for(int i=0;i<n;i++) {
           c+="0";
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<s[i].size();j++){

                string a=s[i].substr(0,j);
                string b=s[i].substr(j,s[i].size());
                
                if(mp.count(a) && mp.count(b)){
                    c[i]='1'; 
                    break;
                }
                
            }
        }
        cout<<c<<endl;
    }
}
