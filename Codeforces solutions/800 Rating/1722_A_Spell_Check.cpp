#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, v[5], flag=0;
        for(int i=0; i<5;i++)   v[i]=0;
        cin>>n;
        string s;
        cin>>s;
        if(s.size()==5){
            for(int i=0; i<s.size(); i++){
                if(s[i]=='T')   v[0]++;
                if(s[i]=='i')   v[1]++;
                if(s[i]=='m')   v[2]++;
                if(s[i]=='u')   v[3]++;
                if(s[i]=='r')   v[4]++;
            }
            for(int i=0; i<5; i++){
                if(v[i]>0){
                    flag++;
                }
            }
            
            if(flag==5){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
