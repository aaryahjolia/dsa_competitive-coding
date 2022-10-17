#include<bits/stdc++.h>
using namespace std;

//fibonacci recursive funct -> f(n)=f(n-1)+f(n-2)
// Top-Down Approach -> (required to base case to know all answers in stack to finally obtain required answer)

int fib(int n,vector<int> &dp){  //Time Complexity -> O(n) , space complexity -> O(n) , stack space -> O(n)
    if(n<=1) return n; //0th element->0,1st element->1
    if(dp[n]!=-1) return dp[n];
    else{
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    }
}

int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    vector<int> dp1(n+1,-1);  // fill with -1 , whenever we solve one recursion simply store so can use it directly without further recusive computation . imagine n=100000 🥱 , O(n) vs O(2^n) , even for n=40 (it is taking time)
    cout<<"The nth Number is By Recursive Approach : "<<fib(n,dp1)<<endl;


    //iterative method  -> Bottom - Up Approach -> (base case to required answer)
    int dp2[n+1];  //time complexity -> O(n), space complexity -> O(n), but using these we can solve for any i<=n using just dp[i]
    dp2[0]=0;dp2[1]=1;
    for(int i=2;i<=n;i++){
        dp2[i]=dp2[i-1]+dp2[i-2];
    }
    cout<<"By Iterative Approach : "<<dp2[n];
}
