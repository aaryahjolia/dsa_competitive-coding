#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(ind,start,end,inc) for(int ind=start;i<end;i+=inc)

int knapsack(int W,int n,int wt[],int price[]){
    if(W==0||n==0){
        return 0;
    }
    if(wt[n-1]>W){   // simply ignore that item
        return knapsack(W,n-1,wt,price);
    }
    else{  // 2 options --> either reject or accept
        return max(knapsack(W,n-1,wt,price),price[n-1]+knapsack(W-wt[n-1],n-1,wt,price));
    }
}

int main()
{
    int W,n;  // W-> Bag capaciy , n -> no. of items
    cout<<"Enter W : ";
    cin>>W;
    cout<<"Enter No. of items : ";
    cin>>n;
    int weight[n],price[n];   // weight and price array -> weight and price of ith item 
    loop(i,0,n,1){
        cout<<"Enter Weight of Item "<<(i+1)<<" : ";
        cin>>weight[i];
        cout<<"Enter Price of Item "<<(i+1)<<" : ";
        cin>>price[i];
    }
    cout<<"Max Price that can be inside the knapsack(bag) is : "<<knapsack(W,n,weight,price);
}
