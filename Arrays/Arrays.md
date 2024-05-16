## Arrays
## basic array code using c++

#include <bits/std++.h>
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

