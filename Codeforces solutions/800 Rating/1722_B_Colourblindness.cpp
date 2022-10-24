#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, flag=0;
        cin>>n;
        string s,v;
        cin>>s>>v;
        for(int i=0; i<n; i++){
            if((s[i]=='R'&& v[i]!='R')||(v[i]=='R'&& s[i]!='R')){
                flag=1;
            }
        }
        if(flag==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
