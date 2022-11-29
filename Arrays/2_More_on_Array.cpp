#include<iostream>
using namespace std;

int main(){

int arr[5]={10,20,30,40,50}; // Array is declared and values are assaigned.
    
for (int i = 0; i < 5; i++) //  using for loop to print values of array.
{


    cout<<arr[i]<<endl;       // Here variable i will be updated in every
                             // iteration and all values of array will be printed
}


//We can change the value in an array.

arr[0]=5;      //we changed the value at index 0 (i.e 10) to 5.

cout<<"The value at index 0 after change "<<arr[0];  //printing new value.





//We can declare array of different Datatype like float,char,etc.

char arr1[3]={'c','a','r'};   //An array of datatype char is declared and assaigned.
return 0;
}