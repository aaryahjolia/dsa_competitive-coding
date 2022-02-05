#include<bits/stdc++.h>
using namespace std;

int LinearSearch(int array[],int size,int to_find){
    for(int i=0;i<size;i++){
        // Returns index based on '0' (zero)
        if(array[i]==to_find)return i;
    }
    return -1;
}

int main(){
    cout<<"Enter size of Array:"<<endl;
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter element to search:"<<endl;
    int to_find_element;
    cin>>to_find_element;
    int index=LinearSearch(array,size,to_find_element);
    if(index==-1){
        cout<<"Element is not present in array!"<<endl;
    }
    else{
        // Index is based on '0' (zero) numbering, Add 1 to index for 1 numbering
        cout<<"Element "<<array[index]<<" is present at index: "<<index<<" !"<<endl;
    }
return 0;
}