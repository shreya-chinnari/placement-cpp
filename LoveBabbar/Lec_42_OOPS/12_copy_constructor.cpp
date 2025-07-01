#include <iostream>
using namespace std;

class Hero
{
private:
   int age;
   string name;

public:
   // Parameterized constructor
   Hero(int a, string n)
   {
      age = a;
      name = n;
      cout << "Constructor called\n";
   }

   // Copy constructor
   Hero(const Hero &original)
   {
      age = original.age; // original = h1
      name = original.name;
      cout << "Copy Constructor called\n";
   }

   void display()
   {
      cout << "Name: " << name << ", Age: " << age << endl;
   }
};

int main()
{
   Hero h1(20, "Ramesh"); // Constructor called
   /*
   same as:
   h1.setAge(20);
   h1.setName("Ramesh");
   */
   Hero h2 = h1; // Copy constructor called

   // h1 : direct constructor
   // h2 : copy constructor using h1
   cout << "\nOriginal object:\n";
   h1.display();

   cout << "\nCopied object:\n";
   h2.display();

   return 0;
}
