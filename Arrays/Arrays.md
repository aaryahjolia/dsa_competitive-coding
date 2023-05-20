## Arrays

 In C++, an array is a data structure that stores a collection of elements of the same type. The elements in an array are arranged in a contiguous block of memory, and they can be accessed using their index.

The syntax for declaring an array in C++ is as follows:

   type array_name[size];

where type is the type of the elements in the array, array_name is the name of the array, and size is the number of elements in the array.

For example, the following code declares an array of 5 integers:

int numbers[5];

Once an array has been declared, you can initialize it with values using the following syntax:

array_name[index] = value;

For example, the following code initializes the first element of the numbers array to 10:

numbers[0] = 10;

You can access the elements of an array using their index. The index of an element is its position in the array, starting from 0. For example, the following code prints the value of the first element of the numbers array:

cout << numbers[0] << endl;

The following code prints the values of all the elements of the numbers array:

s
for (int i = 0; i < 5; i++) {
  cout << numbers[i] << endl;
}