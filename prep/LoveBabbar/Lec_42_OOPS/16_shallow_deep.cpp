#include <iostream>
#include <cstring> // For strcpy()

// Class definition
class MyClass
{
private:
   char *name;

public:
   // Constructor
   MyClass(const char *n)
   {
      name = new char[strlen(n) + 1];
      strcpy(name, n);
   }

   // Destructor
   ~MyClass()
   {
      delete[] name;
   }

   // Shallow copy constructor
   MyClass(const MyClass &other) : name(other.name) {}

   // Deep copy constructor
   MyClass deepCopy()
   {
      MyClass temp(name);
      return temp;
   }

   // Method to display name
   void displayName()
   {
      std::cout << "Name: " << name << std::endl;
   }
};

// Main function
int main()
{
   // Original object
   MyClass original("Original");

   // Shallow copy
   MyClass shallowCopy = original;

   // Deep copy
   MyClass deepCopy = original.deepCopy();

   // Display names
   std::cout << "Original object:" << std::endl;
   original.displayName();

   std::cout << "\nShallow copy object:" << std::endl;
   shallowCopy.displayName();

   std::cout << "\nDeep copy object:" << std::endl;
   deepCopy.displayName();

   return 0;
}

/*
Shallow Copy:

   In the shallow copy (MyClass(const MyClass &other)),
   the name pointer of the new object (shallowCopy) points to the same memory location as the original object (original).
   This means both objects share the same name data, leading to potential issues if one object modifies name.

Deep Copy:

   In the deep copy (MyClass deepCopy()),
   a new memory location is allocated for the name data using strcpy().
   This ensures that the deepCopy object has its own independent copy of name,
   preventing unintended interactions between the original and copied objects.
*/