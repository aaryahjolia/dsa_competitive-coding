
## [Allocate Books](https://www.codingninjas.com/codestudio/problems/allocate-books_1090540)

Book Allocation Problem

Given an array ```arr``` of integer numbers . 
where ```arr[i]``` represents the number of pages in the ```i-th``` book. 

There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:

    1. Each student gets at least one book.
    2. Each book should be allocated to a student.
    3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.


## Approach
This question on reading can be determined that this is a question of Binary Search.


**How?**

Binary Search always have a certain patterns of questions which can be determined by reading the questions itself !

**The line:**

*You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.*

is the one which helps us to identify that..

**The approach:(Dry Run)**

We are trying to minimize the search space here too

Suppose our array is 

10 20 30 40 

and students are 2

Initialize min=0   and max=100

mid=50 ((0+100)/2)

so checking if 50  is a possible solution
```
    10+20+30+40 =30(if +30,then >50,so not a possible solution)
```
checking for 2nd Student
```
    30+40>50,so allocate only 30
```

checking for student 3 **(but we had only 2)**

Thus ,50 is not a possible  solution

    
So since 50 is not a possible solution,
mid<50 solutions are also not possible(left space rejected),

so shifting to right space(i.e start=mid+1)

So,now our search pace is 51 to 100

mid=75 (51+100/2)

```
    Student 1:10+20+30(not +40)=60
    Student 2: 40
```
so we successfullly allocated, thus 75 is a possible solution

Now since 75 is a possible solution,all solutions greater than 75 are possible,so to find minimum possible solution,check to **left of 75** in search space

so end=mid-1

Now our search space is 51 to 74

mid=125/2=62
    
checking for 62 allocation
```
    Student 1: 10+20+30 (<62)
    Student 2: 40 (<62)
    done
```

again Search space to 51 to 61

mid=(112/2)=56

```
    Student 1= 10+20 (<526)
    Student 2= 30 (<56)
    40 remains unallocated
    thus No solution
    So now Search space reduces to right subspace
    that is 57 to 61
    mid=59
    Student 1=10+20
    Student 2=30
    No possible solution
```

So jump to right subspace 60 to 61
    
mid=60+61/2=60

```
    Student 1= 10+20+30(<60)
    Student 2=40(<60)

    Solution possible
```

No left subspace now is s=60,e=59(mid-1),so while loop exits thus return ans stored after each step 

We could also use Linear search with ```O(N^2)``` Time Complexity or better, we use Binary Search with ```O(Nlog(N))```
## Code

```cpp
bool isPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1, pageSum = 0;	//min start with one student, and page sum=0, keep on adding value till it is<mid and rest give to other student and check
    for(int i = 0; i<n; i++){
        if(pageSum + arr[i] <=mid ){
            //a[i] current page sum value, maintain a running count
            pageSum+=arr[i];	//save it || page sum represents the no. of pages alloted to the student in consideration right now
        }
        else{
            //allocate remaining pages to other student
            studentCount++;
            //check for no solution case
            if(studentCount > m || arr[i] > mid){
                return false;
                //if student >m and the value of current is greater than mid, stop in these two cases
            }
            else{
                //we increases student count so new page sum value
//                 pageSum=0;
//                 pageSum+=arr[i];
//                 we can use above lines also for understanding, if starting from zero no needed for zero + in unary operator
                pageSum=arr[i];
            }
        }
    }
    return true;	//everything fine return true
}
int allocateBooks(vector<int> arr, int n, int m) {
    int start = 0;	//end = sum of all array elements
    int sum = 0;
    for(int i =0; i<n; i++){
        sum+=arr[i];
    }
    int end = sum;
    int ans = -1;	//initialize ans
    
    int mid = start +(end-start)/2;
    
    while(start<=end){
        if(isPossible(arr, n,m,mid)){
            //possible solution, save the ans and move to left to find minimal possilbe solution, coz right of this will also satisfy the condition
            ans = mid;
            end = mid-1;
        }
        else{
            //no soln exists, means more no. of students needed than given, so move to right to increase sum
            //lower the search space, bring start infront
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}

```
## Time Complexity
The time complexity for the solution therefore(ignoring the array insertion and creation) is ```0(N)*O(logN) = O(NlogN)```

###

Written and Documented by [Sritam Mishra](https://github.com/ENVIRYO2112VIT)