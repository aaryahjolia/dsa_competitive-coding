#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        //if n is odd, then there is no solution
        if(n%2!=0)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            vector<pair<int,int>> v;
            for(int i=0;i<n;i=i+2)
            {
                /*if two consecutive elements are same then their alternate sum would be 0. If they are not same then two different segments have to be made and the sum of those two segments would be equal to 0.*/
                if(a[i]==a[i+1])
                {
                    v.push_back({i+1,i+2});
                }
                else
                {
                    v.push_back({i+1,i+1});
                    v.push_back({i+2,i+2});
                }
            }
            cout<<v.size()<<"\n";
            for(int i=0;i<v.size();++i)
            {
                cout<<v[i].first<<" "<<v[i].second<<"\n";
            }
        }
        
    }
}
