## Description 
Radix sort algo sorts the elements by  grouping one digits at a time, of the same place value. Then, sort the elements according to the element's increasing/decreasing order.

## Code  
```
//Radix sort in cpp
#include <iostream>
using namespace std;
 
// Get maximum value
int getMax(int array[], int size)
{
	int max = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
 
//  count sort .
void countSort(int array[], int size, int exp)
{
	// counting the number of elements having that 'i' digit at their (n)th place.  
	int output[size], i, count[10] = {0};
 
	// Count the number of times each digit occurred 
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
 

	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
 
	// Assign the result to the array .
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
 
// Sorting the array using Radix Sort.
void radix_Sort(int array[], int size)
{

	int max = getMax(array, size);
 
	// Call countSort() for digit at (n)th place .
	for (int exp = 1; max/exp > 0; exp *= 10)
		countSort(array, size, exp);
}
 

// main function or driver function
int main() {
    int size;
    cout<< "Enter Number of elements :" ;
    cin >> size ;
    int array[size];
    
    //getting array elements
    for(int i=0; i < size; i++ ){
        cout<<"array["<<i<<"] :";
        cin>>array[i];
    }
    
    //print original array
    cout<<"\n Original Array: ";
    for (int i= 0; i <size; i++ ){
        
         cout<<array[i]<<", ";
    }
    
    //calling shell_sort function
    radix_Sort(array,size);
    
    
    //print sorted array
    cout<<"\n Sorted array Array :";
    for (int i= 0; i <size; i++ ){
        
         cout<<array[i]<<", ";
    }
    
    
    
    
    return 0;
}
```

## Complexities
### Time complexity   : 
Best Case  : O(n+k)

Worst Case : O(n+k)

Average    : O(n+k)

### Space complexity  : 
O(max)


