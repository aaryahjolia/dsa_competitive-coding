// given array of size n contains 0s,1s,2s . sort in O(n)
// approaches
// sort directly -> TC = O(nlogn), SC = O(1)
// counting technique -> loop (0->n-1) { count no. of 0s 1s and 2s. } -> 0 -> for 0->#0-1 , 1-> for #0->#1-1 and 2-> for #1->#2-1 -> TC = O(n)+O(n)
// More Optimized -> Dutch National flag algorithm -> 3 pointer approach -> low , mid , high
//  initially low -> 0, mid -> 0 . high -> n-1
// assumptions -> a[0...low-1] -> all are 0s , a[high+1 ... end] -> all are 2s and a[low...mid-1]-> all are 1s
// for 0s -> swap(a[low],a[mid]),low++,mid++
// for 2s -> swap(a[high],a[mid]),high--
// for 1s -> mid++
// TC -> O(n) and SC -> O(1)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sort012(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort012(arr,n);
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
