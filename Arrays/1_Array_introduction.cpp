#include<iostream>
using namespace std;


//   ARRAYS --> An array in C/C++ or is a collection of similar data items 
//              stored at contiguous memory locations and elements can be 
//              accessed randomly using indices of an array

// Note - The indices/indexes start from 0, so first value is assaigned to index 0.

int main(){


//Different ways to declare and assign arrays.

// Method 1


    int arr1[5];       //initialization or declaration
    arr1[0]=1;         //Assigning values at mentioned index
    arr1[1]=2;
    arr1[2]=3;
    arr1[3]=4;
    arr1[4]=5;

// Here first we declared an array of length 5.
//Then we started to assaign values at mentioned indexes (ie-0,1,2,3,4,5).





//Method 2 
   
    int arr2[5]={10,20,30,40,50};    //declaration and assignment at once.

//Here we declared an array of length 5 and assaigned values at once using curcly brackets {}.     



return 0;
}