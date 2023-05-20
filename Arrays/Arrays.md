## Arrays
--- 
### what is an array 
 It is linear data strucutre. An array is collection of homogenous data type where 
  the element are allocated memeroy, any element of an array can be accessed in 
  contant time by indexing value array can stored in multipal value in a single
  variable. Array indexing always start Zero(0).

  ```Array
                       array elements
    array =        | 1 | 2 | 3 | 4 | 5 | 6 |
    indexNumber  =   0   1   2   3   4   5
````
```** note ** 
 Array name stored is base address of an array , array
 index number are called subscript  numbers--

```
---
### Array Operations 
 * Traversal 
 * insertation
 * Deletion
 * searching 
 * sorting 
 * merging

 ---

 ## Array Declaration 
   ```CPP

    datatype arrayName[size]  =   {element of an array};

    int  arr[5] = { 1,2,3,4,5};

    2nd type 
    int marks[]  = new int[5];
    markrs[] = {1,2,3,4,5};
   
   ```
   ## how to create an array using cpp
```Cpp
 
    #include <iostream>
    namespace using std;
    int main(){
    
        int arr[5] = {1,2,3,4,5};
        
        cout<<arr[0];
        cout<<arr[1];
        cout<<arr[2];
        cout<<arr[3];
        cout<<arr[4];
        return 0;
    }
```
## Traversal of an Array uisng For loop
```Cpp
 #include <iostream>
using namespace std;

int main() {

  int numbers[5] = {7, 5, 6, 12, 35};

  cout << "The numbers are: ";

  //  Printing array elements
  // using range based for loop
  for (const int &n : numbers) {
    cout << n << "  ";
  }

  cout << "\nThe numbers are: ";

  //  Printing array elements
  // using traditional for loop
  for (int i = 0; i < 5; ++i) {
    cout << numbers[i] << "  ";
  }

  return 0;
}
```
## how to take input of an array

```cpp
#include <iostream>
using namespace std;

int main() {

  int numbers[5];

  cout << "Enter 5 numbers: " << endl;

  //  store input from user to array
  for (int i = 0; i < 5; ++i) {
    cin >> numbers[i];
  }

  cout << "The numbers are: ";

  //  print array elements
  for (int n = 0; n < 5; ++n) {
    cout << numbers[n] << "  ";
  }

  return 0;
}
```

### Queston 1:  Display Sum and Average of Array Elements Using for Loop
```CPP
#include <iostream>
using namespace std;

int main() {
    
  // initialize an array without specifying size
  double numbers[] = {7, 5, 6, 12, 35, 27};

  double sum = 0;
  double count = 0;
  double average;

  cout << "The numbers are: ";

  //  print array elements
  // use of range-based for loop
  for (const double &n : numbers) {
    cout << n << "  ";

    //  calculate the sum
    sum += n;

    // count the no. of array elements
    ++count;
  }

  // print the sum
  cout << "\nTheir Sum = " << sum << endl;

  // find the average
  average = sum / count;
  cout << "Their Average = " << average << endl;

  return 0;
}

 ```
In this program:

We have initialized a double array named numbers but without specifying its size. We also declared three double variables sum, count, and average.

Here, sum =0 and count = 0.
1.Then we used a range-based for loop to print the array elements. In each iteration of the loop, we add the current array element to sum.
2.We also increase the value of count by 1 in each iteration, so that we can get the size of the array by the end of the for loop.
3.After printing all the elements, we print the sum and the average of all the numbers. The average of the numbers is given by average = sum / count;



