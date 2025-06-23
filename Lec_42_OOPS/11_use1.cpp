// ✅ 1. Resolve Naming Conflicts with this

/*
🔍 Problem:

When a constructor parameter has the same name as a class member, the member gets shadowed.

   ❌ Without this → Wrong assignment
   ✅ With this → Correctly assigns value to class member
*/

#include <iostream>
using namespace std;

class Hero
{
private:
   int age;
   string name;

public:
   // Constructor with parameter names same as data members
   Hero(int age, string name)
   {
      // Without 'this', it would assign the parameter to itself (no effect)
      // age = age;  // ❌ wrong (does nothing useful)
      // name = name; // ❌ wrong (does nothing useful)

      // ✅ 'this->' clarifies you mean the class's member variable
      this->age = age;
      this->name = name;
   }

   void display()
   {
      cout << "Name: " << name << ", Age: " << age << endl;
   }
};

int main()
{
   Hero h(21, "Ramesh");
   h.display(); // Output: Name: Ramesh, Age: 21
   return 0;
}
