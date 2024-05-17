## Arrays
## basic array code using c++

#include <bits/stdc++.h>
using namespace std;
int main()
{
int size,arr[100];
cout<<"enter the size of the array"<<endl;
cin>>size;
cout<<"kindly enter the elements"<<endl;
for(int i=0;i<size;i++)
{
    cin>>arr[i];
}
for(int i=0;i<size;i++)
{
    cout<<"the array element at index" <<i << "is" <<arr[i]<<endl;
}
}

## code for finding max number in an array
#include <bits/stdc++.h>
using namespace std;
int main()
{
int size,arr[100];
int max=0;
cout<<"enter the size of the array"<<endl;
cin>>size;
cout<<"kindly enter the elements"<<endl;
for(int i=0;i<size;i++)
{
    cin>>arr[i];
}
cout<<"now find the maximum number"<<endl;
for(int i=0;i<size;i++)
{
    if(max<arr[i])
    {
        max=arr[i];
    }
}
    cout<<"the maximum array element is "<<max<<endl;
}
