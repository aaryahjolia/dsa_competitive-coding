# Recursion

When a Function call itselfs until a specified condition met is called Recursion.

If the condition is not there, It will be infinite recursion.

A stack is maintained and the function is pushed whenever it is called, so in case of infinite recursion, the stack will overflow and it is called Segmentation error or Stack overflow error.  
The space used in the stack is called the stack space.

The specified condition on which the recursive function stops calling itself is called the Base condition.

Recursion Tree:  
Function calls are represented in form of smaller functions. 
![Recursion Tree Image](https://media.geeksforgeeks.org/wp-content/uploads/20210608083944/img-300x172.PNG)

Main keywords:
1. Recursion definition
2. Base Case
3. Stack overflow / Stack space
4. Recursion tree