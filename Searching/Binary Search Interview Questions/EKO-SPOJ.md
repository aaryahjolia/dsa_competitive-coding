
## [EKO-SPOJ](https://www.spoj.com/problems/EKO/)

Lumberjack Mirko needs to chop down M metres of wood. 
It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire.
However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres),
 and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H 
 (of course, trees not higher than H meters remain intact).
  Mirko then takes the parts that were cut off. 
  For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, 
  and Mirko raises his sawblade to 15 metres,
  the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, 
  while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. 
That‟s why he wants to set his sawblade as high as possible. 
Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

## Approach
This question on reading can be determined that this is a question of Binary Search.

**How?**

Binary Search always have a certain patterns of questions which can be determined by reading the questions itself !

**The line:**

*Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.*

is the one which helps us to identify that..

**The approach:**

Well, we need to apply the "search space" here and find our answer in this.

The minimum level to keep the saw here is ```0``` (the bottom of trees) and Maximum level would be max(```heightsTrees```)

**So the search space lies from 0 to max(heightsTrees)**

The sawblade must lie in between these two min and max range to obtain at least ```M``` metres of wood.

**Application of Binary Search:**

The "searching" here would refer to the Adequate height of sawblade. 
For each height of sawblade ```sawbladeHeight```, we will do ```sum(heightsTrees[i]-sawbladeHeight)``` to determine the total meters of wood chopped.

Thus, we could also use Linear search with ```O(N^2)``` Time Complexity or better, we use Binary Search with ```O(Nlog(N))```
## Code

```cpp
#include <iostream>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            sum+=arr[i]-mid;
        }
    }
    if(sum>=m){return true;}
    else{return false;}
}
int cutWood(int arr[],int n,int m){
    int s=0;
    int maxi=arr[0];
    for(int i=0;i<n;i=i+2){
        maxi=max(arr[i],arr[i+1]);
    }
    int e=maxi;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int arr[5]={4,42,40,26,46};
    int n=5;
    int m=20;
    //cout<<"ENTER N AND M";
    //cin>>n>>m;
    //for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<cutWood(arr,n,m);
    return 0;
}

```
## Time Complexity
The time complexity for the solution therefore(ignoring the array insertion and creation) is ```0(N)*O(logN) = O(NlogN)```


###

Written and Documented by [Sritam Mishra](https://github.com/ENVIRYO2112VIT)