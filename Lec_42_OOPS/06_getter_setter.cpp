#include <iostream>
using namespace std;

class Person
{
private:
   int age;     // private member
   string name; // private member

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
   Person p;

   // Set values using setters
   p.setAge(30);
   p.setName("Alice");

   // Get values using getters
   cout << "Name: " << p.getName() << endl;
   cout << "Age: " << p.getAge() << endl;

   return 0;
}
