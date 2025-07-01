#include <iostream>
using namespace std;

class Base
{
private:
   int age;
   string name;

public:
   // Parameterized Constructor
   Base(int a, string n)
   {
      age = a;
      name = n;
      cout << "Constructor called!" << endl;
   }

   void display()
   {
      cout << "Name: " << name << ", Age: " << age << endl;
   }
};

int main()
{
   Base b1(30, "Bob"); // Constructor gets called here
   b1.display();
   return 0;
}

/*

Constructor called!
Name: Bob, Age: 30

*/