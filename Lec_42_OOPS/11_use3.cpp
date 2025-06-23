// ✅ 3. Using this Inside Non-Static Member Function

/*
🔍 Purpose:

this is automatically available in non-static member functions to refer to the calling object.

This can be used to:

   : Access members of the current object
   : Return object address for method chaining
   : Print debugging info about the current object
*/

#include <iostream>
using namespace std;

class Hero
{
private:
   int age;

public:
   void setAge(int age)
   {
      this->age = age; // Still using 'this' to access object member
   }

   void showAddress()
   {
      cout << "Address of current object (this): " << this << endl;
   }

   void display()
   {
      cout << "Age: " << age << endl;
   }
};

int main()
{
   Hero h1;
   h1.setAge(40);
   h1.display();

   cout << "Address in main(): " << &h1 << endl;
   h1.showAddress(); // Shows same address as &h1

   return 0;
}

/*

Age: 40
Address in main(): 0x925b7ff97c
Address of current object (this): 0x925b7ff97c

*/