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
      cout << "[Constructor] Hero created with name = " << name << ", age = " << age << endl;
   }

   // Copy constructor
   Hero(const Hero &original)
   {
      age = original.age;
      name = original.name;
      cout << "[Copy Constructor] Copying Hero with name = " << name << ", age = " << age << endl;
   }

   // Display method
   void display()
   {
      cout << "Name: " << name << ", Age: " << age << endl;
   }
};

// Function that accepts an object by value (triggers copy constructor)
void showHero(Hero h)
{
   cout << "[Inside showHero()] Displaying copied object:\n";
   h.display();
}

// Function that returns an object (may trigger copy constructor)
Hero createHero()
{
   Hero temp(100, "TempHero");
   return temp; // May call copy constructor or use optimization (NRVO)
}

int main()
{
   cout << "\n Step 1 : Creating original object h1 :\n ";
   Hero h1(25, "Ramesh"); // Calls parameterized constructor

   cout << "\n Step 2: Creating h2 by copying h1:\n";
   Hero h2 = h1; // Calls copy constructor

   cout << "\n Step 3: Passing h1 to function by value:\n";
   showHero(h1); // Calls copy constructor to pass by value

   cout << "\n Step 4: Creating object from function return:\n";
   Hero h3 = createHero(); // May or may not call copy constructor (optimization dependent)

   cout << "\n Final Objects:\n";
   h1.display();
   h2.display();
   h3.display();

   return 0;
}

/*
 Step 1 : Creating original object h1 :
 [Constructor] Hero created with name = Ramesh, age = 25

 Step 2: Creating h2 by copying h1:
[Copy Constructor] Copying Hero with name = Ramesh, age = 25

 Step 3: Passing h1 to function by value:
[Copy Constructor] Copying Hero with name = Ramesh, age = 25
[Inside showHero()] Displaying copied object:
Name: Ramesh, Age: 25

 Step 4: Creating object from function return:
[Constructor] Hero created with name = TempHero, age = 100

 Final Objects:
Name: Ramesh, Age: 25
Name: Ramesh, Age: 25
Name: TempHero, Age: 100

*/