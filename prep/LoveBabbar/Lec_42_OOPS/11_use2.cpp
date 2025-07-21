// ✅ 2. Returning the Current Object (*this) for Method Chaining

/*
🔍 Purpose:

Allows you to chain multiple function calls on the same object.

❌ Without return *this → Can't chain methods
✅ With return *this → Enables chaining
*/

#include <iostream>
using namespace std;

class Hero
{
private:
   int age;
   string name;

public:
   // Setters returning current object using 'this'
   Hero &setAge(int age)
   {
      this->age = age;
      return *this; // ✅ return current object for chaining
   }

   Hero &setName(string name)
   {
      this->name = name;
      return *this;
   }
   /*
   > | "this->age"   -  	Refers to the class's member variable named age.
   > | "age"	      -   Refers to the function's parameter named age.
   */

   void display()
   {
      cout << "Name: " << name << ", Age: " << age << endl;
   }
};

int main()
{
   Hero h;

   // ✅ Method chaining
   h.setAge(30).setName("Suresh");
   h.display(); // Output: Name: Suresh, Age: 30

   // ❌ Without 'return *this', chaining won't work:
   // h.setAge(30).setName("Suresh");  // ❌ Error: setAge doesn't return an object

   return 0;
}
