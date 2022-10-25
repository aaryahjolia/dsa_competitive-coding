#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
   ll int t;
    cin>>t;
    while(t--)
    {
        //ll int n;
        string s;
        cin>>s;
        //string s=to_string(n);
        
        int flag=1;
   
   for(ll int i=s.size();i>0;i--){
       ll int c=((s[i]-'0')+(s[i-1]-'0'));
       string r=to_string(c);
       if(c>9)
       {
           s.replace(i-1,2,r);
           flag=0;
           break;
       }
   }
   
   if(flag){
       ll int c1=((s[1]-'0')+(s[0]-'0'));
       string r1=to_string(c1);

        s.replace(0,2,r1);
   }
  cout<<s<<endl;
    }
}
