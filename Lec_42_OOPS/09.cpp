#include <iostream>
using namespace std;

// Define the Base class
class Base
{
private:
   int age;
   string name;

public:
   // Setter for age
   void setAge(int a)
   {
      age = a;
   }

   // Getter for age
   int getAge()
   {
      return age;
   }

   // Setter for name
   void setName(string n)
   {
      name = n;
   }

   // Getter for name
   string getName()
   {
      return name;
   }
};

int main()
{
   // ----------- Static Allocation ------------
   cout << "STATIC ALLOCATION:" << endl;

   Base s; // Object allocated statically (on stack)

   // Set values using setter functions
   s.setAge(25);
   s.setName("Alice");

   // Get and print values using getter functions
   cout << "Static Object - Name: " << s.getName() << endl;
   cout << "Static Object - Age: " << s.getAge() << endl;

   // ----------- Dynamic Allocation ------------

   cout << "\nDYNAMIC ALLOCATION:" << endl;
   Base *d = new Base(); // Object allocated dynamically (on heap)

   // ----------- Dynamic Object (Pointer + Arrow Operator) -----------
   // The -> operator is shorthand for (*pointer).member.

   // Set values using setter functions through pointer
   d->setAge(30);
   d->setName("Bob");

   // Get and print values using getter functions through pointer
   cout << "Dynamic Object - Name: " << d->getName() << endl;
   cout << "Dynamic Object - Age: " << d->getAge() << endl;

   // -------------- Dynamic Object (Pointer + Dereferencing) --------------
   (*d).setAge(50); // equivalent to d->setAge(30)
   cout << "\nAge: " << (*d).getAge() << endl;

   // Clean up dynamic memory
   delete d;

   return 0;
}

/*

STATIC ALLOCATION:
Static Object - Name: Alice
Static Object - Age: 25

DYNAMIC ALLOCATION:
Dynamic Object - Name: Bob
Dynamic Object - Age: 30

Age: 50
*/