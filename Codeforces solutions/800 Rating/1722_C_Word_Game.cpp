#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int pa=0, pb=0, pc=0;
        
        vector<string> a(n), b(n), c(n);
        unordered_map<string ,int> x,y,z;
        
        for (int j=0; j<n; j++){
            cin >> a[j];
            x[a[j]]++;
        }
        for (int j=0; j<n; j++){
            cin >> b[j];
            y[b[j]]++;
        }
        for (int j=0; j<n; j++){
            cin >> c[j];
            z[c[j]]++;
        }
        
        for(int i=0; i<n; i++){   
            if(x[a[i]] + y[a[i]] + z[a[i]] == 1 )
                pa += 3;
            else if(x[a[i]] + y[a[i]] + z[a[i]] == 2 ) 
                pa += 1;
        }
        
        for(int i=0; i<n; i++){   
            if(x[b[i]] + y[b[i]] + z[b[i]] == 1 )
                pb += 3;
            else if(x[b[i]] + y[b[i]] + z[b[i]] == 2 ) 
                pb += 1;
        }
        
        for(int i=0; i<n; i++){   
            if(x[c[i]] + y[c[i]] + z[c[i]] == 1 )
                pc += 3;
            else if(x[c[i]] + y[c[i]] + z[c[i]] == 2 ) 
                pc += 1;
        }
        
        cout<<pa<<" "<<pb<<" "<<pc<<endl;
    }
    return 0;
}
