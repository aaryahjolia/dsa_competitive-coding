## Description 
Vector are also called as dynamic arrays. It work like arrays and it is part of containers.

## Different Ways to Initialise a vector  

### Note : Vectors need an additional include.
```cpp
#include<vector>
```
But Everything will be included when we include <bits/stdc++.h>, so no need to import vector if we import all modules.

### Supported Datatypes : 
char, uchar, short, ushort, int, uint, float, long, and ulong

### 1. 0 sized vector  

```cpp
// Creates a zero sized vector of int
vector<int> name;
```
 
### 2. n-sized vector

```cpp
// Creates a n sized vector of int
vector<int> name1(n);
```

### 3. Creating copy of vector

```cpp
//1st way - Using a loop to copy elements of the old vector into the new vector
vector<int> name1{1,2,3,4};
vector<int> name2;
for(int i=0;i<name1.size();i++){
   name2.push_back(name1[i]);
}

//2nd way - Using the assignment operator ("=") to assign the new vector to the old vector
vector<int> name1{1,2,3,4};
vector<int> name2;
name2=name1;

// 3rd way - Creating a copy of vector name1 by iterating 
vector<int> name2(name1.begin(),name1.end());

// 4th way - By passing the old vector as constructor while declaring the new vector copies the contents of the old vector into the new one.
vector<int> name2(name1);

//5th way - Using the copy function for copying the vector
vector<int> name1{1,2,3,4};
vector<int> name2;
copy(name1.begin(),name1.end(),back_inserter(name2));         //back_inserter() function is used to insert values from the back

//6th way - Using the assign function to assign the contents of the old vector to the new vector
vector<int> name1{1,2,3,4};
vector<int> name2;
name2.assign(name1.begin(),name1.end());                      // assign() function is used as vector.assign(iterator1,iterator2)  where iterator1,iterator2 are the initial and final positions in the range respectively 

//7th way - Using the insert function for copying the vector
vector<int> name1{1,2,3,4};
vector<int> name2;
name2.insert(name2.begin(),name1.begin(),name1.end());        //insert() function can be used as vector.insert(start, iterator1, iterator2) which inserts the range of elements iterator1 to iterator2 at the position "start"

,```

### 4. n-sized vector with default value m

```cpp
// Creates a n sized vector of int with default value m
vector<int> name1(n,m);
```

### 5. Vector with pre defined values

```cpp
// Creates a vector with user values
vector<int> name1 = {1,2,3,4,5,6};
```
