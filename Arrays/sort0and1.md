## sort 0 and 1
### Apporch of sort 0 and 1, 
```steps
step 0; loop is runnig when (si < ei);
step 1: find the start index(si) and ending index(ei) 
		starting index initilize with index number 0, and 
		ending index initilize with size of an array,
step 2: if start index ==0 then, si++ and ending index, ei = 1, ei--;
step 3: if start index =1 and ending index =0 , then swap (si,ei);
```
---
```cpp
#include<iostream>
using namespace std;

  void sort(int[] arr , int size){
        int si =0;
        int ei = size-1;
       while (si < ei)
		{
			while (arr[si] == 0 && si < ei)
			si++;

			while (arr[ei] == 1 && si < ei)
				ei--;

			if (si < ei)
			{
				arr[si] = 0;
				arr[ei] = 1;
				si++;
				ei--;
			}
		}
	  for (int i=0; i<arr.length; i++) {
            cout<<arr[i];
        	}
        }
int  main(){
  int arr[] = {0,1,0,1,1,0,1,0,0,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  sort(arr,size);
}
    
