<h1>C++ OOPs Concepts</h1>

The major purpose of C++ programming is to introduce the concept of object orientation to the C programming language.

Object Oriented Programming is a paradigm that provides many concepts such as inheritance, data binding, polymorphism etc.

The programming paradigm where everything is represented as an object is known as truly object-oriented programming language. Smalltalk is considered as the first truly object-oriented programming language.

OOPs (Object Oriented Programming System)
Object means a real word entity such as pen, chair, table etc. Object-Oriented Programming is a methodology or paradigm to design a program using classes and objects. It simplifies the software development and maintenance by providing some concepts:

<h2>Cpp Oops concept </h2> 

-Object

-Class

-Inheritance

-Polymorphism

-Abstraction

-Encapsulation

-Object

--Any entity that has state and behavior is known as an object. For example: chair, pen, table, keyboard, bike etc. It can be physical and logical.

<h1>Class</h1>

Collection of objects is called class. It is a logical entity.

<h3>Inheritance</h3>
When one object acquires all the properties and behaviours of parent object i.e. known as inheritance. It provides code reusability. It is used to achieve runtime polymorphism.

<h3>Polymorphism</h3>
When one task is performed by different ways i.e. known as polymorphism. For example: to convince the customer differently, to draw something e.g. shape or rectangle etc.

In C++, we use Function overloading and Function overriding to achieve polymorphism.

<h3>Abstraction</h3>
Hiding internal details and showing functionality is known as abstraction. For example: phone call, we don't know the internal processing.

In C++, we use abstract class and interface to achieve abstraction.

<h3>Encapsulation</h3>
Binding (or wrapping) code and data together into a single unit is known as encapsulation. For example: capsule, it is wrapped with different medicines.

<h4>Advantage of OOPs over Procedure-oriented programming language</h4>
-OOPs makes development and maintenance easier where as in Procedure-oriented programming language it is not easy to manage if code grows as project size grows.

-OOPs provide data hiding whereas in Procedure-oriented programming language a global data can be accessed from anywhere.

-OOPs provide ability to simulate real-world event much more effectively. We can provide the solution of real word problem if we are using the Object-Oriented Programming language.

<h1>C++ Object and Class</h1>
Since C++ is an object-oriented language, program is designed using objects and classes in C++.

<h2>C++ Object</h2>
In C++, Object is a real world entity, for example, chair, car, pen, mobile, laptop etc.

In other words, object is an entity that has state and behavior. Here, state means data and behavior means functionality.

Object is a runtime entity, it is created at runtime.

Object is an instance of a class. All the members of the class can be accessed through object.

Let's see an example to create object of student class using s1 as the reference variable.

Student s1;  //creating an object of Student      
In this example, Student is the type and s1 is the reference variable that refers to the instance of Student class.

<h3>C++ Class</h3>
In C++, class is a group of similar objects. It is a template from which objects are created. It can have fields, methods, constructors etc.

Let's see an example of C++ class that has three fields only.


<mark>class Student    
{    
public:  
int id;  //field or data member     
float salary; //field or data member  
String name;//field or data member    
}    </mark>

<h4>C++ Object and Class Example</h4>

Let's see an example of class that has two fields: id and name. It creates instance of the class, initializes the object and prints the object value.

<mark>#include <iostream>
using namespace std;  
class Student {  
public:  
int id;//data member (also instance variable)      
string name;//data member(also instance variable)      
};  
int main() {  
Student s1; //creating an object of Student   
s1.id = 201;    
s1.name = "Sonoo Jaiswal";   
cout<<s1.id<<endl;  
cout<<s1.name<<endl;  
return 0;  
} </mark> 

Output:

201

Sonoo Jaiswal

C++ Class Example: Initialize and Display data through method

Let's see another example of C++ class where we are initializing and displaying object through method.

<mark>#include <iostream>
using namespace std;  
class Student {  
public:  
int id;//data member (also instance variable)      
string name;//data member(also instance variable)      
void insert(int i, string n)    
{    
id = i;    
name = n;    
}    
void display()    
{    
cout<<id<<"  "<<name<<endl;    
}    
};  
int main(void) {  
Student s1; //creating an object of Student   
Student s2; //creating an object of Student  
s1.insert(201, "Sonoo");    
s2.insert(202, "Nakul");    
s1.display();    
s2.display();  
return 0;  
}  </mark>

Output:

201     Sonoo

202     Nakul

C++ Class Example: Store and Display Employee Information
Let's see another example of C++ class where we are storing and displaying employee information using method.

<mark>#include <iostream>
using namespace std;  
class Employee {  
public:  
int id;//data member (also instance variable)      
string name;//data member(also instance variable)  
float salary;  
void insert(int i, string n, float s)    
{    
id = i;    
name = n;    
salary = s;  
}    
void display()    
{    
cout<<id<<"  "<<name<<"  "<<salary<<endl;    
}    
};  
int main(void) {  
Employee e1; //creating an object of Employee   
Employee e2; //creating an object of Employee  
e1.insert(201, "Sonoo",990000);    
e2.insert(202, "Nakul", 29000);    
e1.display();    
e2.display();    
return 0;  
}  </mark>

Output:

201  Sonoo  990000

202  Nakul  29000
