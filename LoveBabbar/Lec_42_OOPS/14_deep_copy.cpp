#include <iostream>
using namespace std;
#include <cstring>

class Hero
{

public:
   int age;
   char *name;

   // user-defined default constructor
   Hero()
   {
      cout << "default constructor called\n";
      name = new char[100];
   }

   // user-defined copy constructor FOR DEEP COPY
   Hero(Hero &temp)
   {
      cout << "copy constructor called\n";
      this->age = temp.age; // Copy age
      this->age = temp.age; // Copy age

      // Allocate new memory for name : method II
      this->name = new char[strlen(temp.name) + 1];
      strcpy(this->name, temp.name); // Copy the name into allocated memory
   }
   void print() const
   {
      cout << "[ Name: " << this->name << ", Age: " << this->age << " ]" << endl;
   }
   void setAge(int age)
   {
      this->age = age;
   }
   void getAge()
   {
      cout << "Age: " << age << endl;
   }

   void setName(char name[])
   {
      strcpy(this->name, name);
   }
   void getName()
   {
      cout << "Name: " << name << endl;
   }
   ~Hero()
   {
      // Destructor to free dynamically allocated memory
      cout << "Destructor called for Hero with name: " << name << endl;
      delete[] name;
   }
};

int main()
{
   cout << "\n--- Creating Hero1 ---\n";
   Hero hero1;
   hero1.setAge(21);
   char name1[] = "Shreya";
   hero1.setName(name1);
   hero1.print();

   cout << "\n--- Creating Hero2 by copying Hero1 (Deep Copy) ---\n";
   Hero hero2(hero1); // Deep copy
   hero2.print();

   cout << "\n--- Modifying Hero1's name after copying ---\n";
   hero1.name[0] = 'P'; // Change 'S' to 'P' in "Shreya" => "Phreya"

   cout << "\n--- Hero1 details after modification ---\n";
   hero1.print();

   cout << "\n--- Hero2 details (should be unchanged if deep copied) ---\n";
   hero2.print();

   cout << "\n--- Exiting main() ---\n";
   return 0;
}

/*

      // Allocate memory for name : method I
      char *ch = new char[strlen(temp.name) + 1];
      strcpy(ch, temp.name); // Copy the name

*/

/*
--- Creating Hero1 ---
default constructor called
[ Name: Shreya, Age: 21 ]

--- Creating Hero2 by copying Hero1 (Deep Copy) ---
copy constructor called
[ Name: Shreya, Age: 21 ]

--- Modifying Hero1's name after copying ---

--- Hero1 details after modification ---
[ Name: Phreya, Age: 21 ]

--- Hero2 details (should be unchanged if deep copied) ---
[ Name: Shreya, Age: 21 ]

--- Exiting main() ---
Destructor called for Hero with name: Shreya
Destructor called for Hero with name: Phreya

*/