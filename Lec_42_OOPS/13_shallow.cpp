// shallow and deep copy

/*
✅ What This Code Covers:
   How shallow copy works (default copy constructor)
   Why it’s problematic with dynamic memory
   How deep copy solves it
*/
#include <iostream>
using namespace std;
#include <cstring>

class Hero
{

public:
   int age;
   char *name; // Pointer to dynamically allocated memory

   // print
   void print() const
   {
      cout << "[ Name: " << this->name << ", Age: " << this->age << " ]" << endl;
   }
   // user-defined default constructor
   Hero()
   {
      cout << "default constructor called\n";
      name = new char[100]; // Allocate dynamic memory for name
   }
   // age
   void setAge(int age)
   {
      this->age = age; // Set the age
   }
   void getAge()
   {
      cout << "Age: " << age << endl; // Display the age
   }
   // name
   void setName(char name[])
   {
      strcpy(this->name, name); // Copy the name into allocated memory
   }
   void getName()
   {
      cout << "Name: " << name << endl; // Display the name
   }
};

int main()
{
   Hero obj1; // using our constructor
   obj1.setAge(24);
   obj1.setName("Eleanor");
   char name[7] = "Shreya";
   obj1.setName(name);
   obj1.print(); // [ Name: Shreya, Age: 24 ]

   // use default copy constructor
   Hero obj2 = obj1;
   Hero obj3(obj1);
   obj2.print(); // [ Name: Shreya, Age: 24 ]
   obj3.print(); // [ Name: Shreya, Age: 24 ]

   // changing obj1's name
   obj1.setName("Sachi");
   obj1.print(); // [ Name: Sachi, Age: 24 ]
   obj2.print(); // [ Name: Sachi, Age: 24 ]
   obj3.print(); // [ Name: Sachi, Age: 24 ]

   // Changing the first character of obj2's name
   obj2.name[0] = 'A';
   obj2.print(); // [ Name: Aachi, Age: 24 ]
   obj3.print(); // [ Name: Aachi, Age: 24 ]
   obj1.print(); // [ Name: Aachi, Age: 24 ]
   // obj2 and obj3 now share the same memory as obj1
   // This is a shallow copy issue, as obj2 and obj3 point to the same memory location as obj1
   // If obj1 is deleted, obj2 and obj3 will point to invalid memory
   // To fix this, we need to implement a deep copy

   // default constructor does SHALLOW COPY
   // To implement DEEP COPY, we need to create a user-defined copy constructor
   return 0;
}