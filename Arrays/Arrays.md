## Arrays

Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.

## Code To Read and Print elements of an array  

```cpp
#include <stdio.h>
// Main function
int main()
{
    int arr[10];  // Declare an array of size 10 to store integer values
    int i;
    // Print a message to prompt the user for input
    printf("\n\nRead and Print elements of an array:\n");
    printf("-----------------------------------------\n");
    // Prompt the user to input 10 elements into the array
    printf("Input 10 elements in the array :\n");
    for(i=0; i<10; i++)
    {
	    printf("element - %d : ",i);  // Prompt the user to input the i-th element
        scanf("%d", &arr[i]);  // Read the input and store it in the array
    }
    // Display the elements in the array
    printf("\nElements in array are: ");
    for(i=0; i<10; i++)
    {
        printf("%d  ", arr[i]);  // Print each element in the array
    }
    printf("\n");
	return 0;
}
```
