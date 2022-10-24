// A WINNER IS A DREAMER WHO NEVER GIVES UP !!! 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
              
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        string s,t;
        s.push_back('1');
        for(int i=a-1;i>0;i--)
        {
            s.push_back('0');
        }
        if(b-c>0)
        t.push_back('1');
        for(int i=b-c-1;i>0;i--)
        {
            t.push_back('0');
        }
        t.push_back('1');
        for(int i=c-1;i>0;i--)
        {
            t.push_back('0');
        }
        cout<<s<<" "<<t<<endl;
    }
}
