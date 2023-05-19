## Description :
Bucket sort is a sorting algorithm that separate the elements into multiple groups said to be buckets. Elements in bucket sort are first uniformly divided into groups called buckets, and then they are sorted by any other sorting algorithm. After that, elements are gathered in a sorted manner.

```cpp

#include <iostream>  
  
using namespace std;  
  
int getMax(int a[], int n) // function to get maximum element from the given array  
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket(int a[], int n) // function to implement bucket sort  
{  
  int max = getMax(a, n); //max is the maximum element of array  
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  
void printArr(int a[], int n) // function to print array elements  
{  
  for (int i = 0; i < n; ++i)  
    cout<<a[i]<<" ";  
}  
int main()  
{  
  int a[] = {34, 42, 74, 57, 99, 84, 9, 5};  
  int n = sizeof(a) / sizeof(a[0]); // n is the size of array  
  cout<<"Before sorting array elements are - \n";  
  printArr(a, n);  
  bucket(a, n);  
  cout<<"\nAfter sorting array elements are - \n";  
  printArr(a, n);  
}  

```

## Complexities
## Time Complexity :

Best Case	O(n + k)
Average Case	O(n + k)
Worst Case	O(n^2)

## Space Complexity :

O(n*k)