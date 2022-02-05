#include<bits/stdc++.h>
using namespace std;

int BinarySearchRecursion(int array[], int size, int to_find, int min_range, int max_range){
    int mid=min_range+(max_range-min_range)/2;
    if(array[mid]==to_find){
        return mid;
    }
    else if(array[mid]>to_find){
        return BinarySearchRecursion(array,size,to_find,0,mid-1);
    }
    else{
        return BinarySearchRecursion(array,size,to_find,mid+1,max_range);
    }
    return -1;
}

int main(){
    cout<<"Enter size of Array:"<<endl;
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter elements:"<<endl;
    // Insertion needs sorted array
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter element to search:"<<endl;
    int to_find_element;
    cin>>to_find_element;
    int index=BinarySearchRecursion(array,size,to_find_element,0,size-1);
    if(index==-1){
        cout<<"Element is not present in array!"<<endl;
    }
    else{
        // Index is based on '0' (zero) numbering, Add 1 to index for 1 numbering
        cout<<"Element "<<array[index]<<" is present at index: "<<index<<" !"<<endl;
    }
return 0;
}