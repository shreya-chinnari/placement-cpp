#include <iostream>
using namespace std;

class Person
{
private:
   int age;
   string name;

public:
   // Setter for age with condition
   void setAge(int a)
   {
      if (a >= 0)
      {
         age = a;
      }
      else
      {
         cout << "Invalid age! Age cannot be negative." << endl;
         age = 0; // or keep it unchanged
      }
   }

   int getAge()
   {
      return age;
   }

   void setName(string n)
   {
      name = n;
   }

   string getName()
   {
      return name;
   }
};

int main()
{
   Person p;

   p.setName("Alice");
   p.setAge(-5); // Invalid input
   cout << "Name: " << p.getName() << endl;
   cout << "Age: " << p.getAge() << endl; // Will show 0 due to fallback

   p.setAge(25); // Valid input
   cout << "Updated Age: " << p.getAge() << endl;

   return 0;
}
