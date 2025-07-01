#include <iostream>  // Includes standard input-output stream
using namespace std; // Avoids needing std:: prefix for cout, string, etc.

class Hero
{
private:
   // 🔹 Member variables (stored per object)
   int age;     // stores the hero's age
   string name; // stores the hero's name

public:
   // 🟢 1. Parameterized Constructor
   // Called when a new object is created with specific values
   Hero(int a, string n)
   {
      // Constructor parameters:
      // a -> int passed by value
      // n -> string passed by value

      // 'this->age' refers to the object's member variable
      this->age = a;
      this->name = n;

      cout << "[Constructor] Hero created with name = " << name << ", age = " << age << endl;
   }

   // 🟢 2. Copy Constructor
   // Called when a new object is created as a copy of an existing one
   Hero(const Hero &original)
   {
      // Parameter:
      // original -> const reference to another Hero object
      //           -> passed by reference to avoid infinite recursion
      //           -> const to protect original from modification

      this->age = original.age;
      this->name = original.name;

      cout << "[Copy Constructor] Copying Hero with name = " << name << ", age = " << age << endl;
   }

   // 🟢 3. Display Function
   // Outputs current values of age and name
   void display()
   {
      // 'this' is an implicit pointer to the current object (not used here explicitly)
      cout << "Name: " << name << ", Age: " << age << endl;
   }
};

// 🟢 4. Function: showHero
// Accepts a Hero object BY VALUE → invokes the COPY CONSTRUCTOR
void showHero(Hero h)
{
   // h is a copy of whatever object was passed
   // Parameter Type: Hero passed by value ⇒ copy is made
   cout << "[Inside showHero()] Displaying copied object:\n";
   h.display();
}

// 🟢 5. Function: createHero
// Returns a Hero object BY VALUE
Hero createHero()
{
   // Local object created
   Hero temp(100, "TempHero");

   // Return by value: compiler may optimize (Named Return Value Optimization - NRVO)
   return temp;
}

// 🔵 MAIN FUNCTION: Entry point
int main()
{
   cout << "🔹 Step 1: Creating original object h1:\n";
   Hero h1(25, "Ramesh");
   // h1 is created using the parameterized constructor
   // Variable type: Hero (object)
   // Memory: stored on stack

   cout << "\n🔹 Step 2: Creating h2 by copying h1:\n";
   Hero h2 = h1;
   // h2 is created as a copy of h1
   // Copy constructor is called
   // Both h1 and h2 are separate objects (deep copies for primitive types)

   cout << "\n🔹 Step 3: Passing h1 to function by value:\n";
   showHero(h1);
   // Passing h1 by value ⇒ copy constructor is called
   // Local copy `h` exists only inside showHero()

   cout << "\n🔹 Step 4: Creating object from function return:\n";
   Hero h3 = createHero();
   // Object returned by value
   // May or may not call copy constructor depending on optimization (NRVO)

   cout << "\n🔹 Final Objects:\n";
   h1.display();
   h2.display();
   h3.display();

   return 0;
}
