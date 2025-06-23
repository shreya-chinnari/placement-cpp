#include <iostream> // For input/output operations
using namespace std;

// Define a class named 'Base'
class Base
{
public:
   // Member variables
   int age;     // Stores the age
   string name; // Stores the name

   // Setter function for age
   void setAge(int a)
   {
      age = a; // Assigns the value 'a' to the 'age' member variable
   }

   // Getter function for age
   int getAge()
   {
      return age; // Returns the current value of 'age'
   }

   // Setter function for name
   void setName(string n)
   {
      name = n; // Assigns the value 'n' to the 'name' member variable
   }

   // Getter function for name
   string getName()
   {
      return name; // Returns the current value of 'name'
   }
};

int main()
{
   // Create an object 's' of class Base using static allocation
   Base s;

   // At this point, 'age' is uninitialized, so this may print garbage
   cout << "age is (direct access): " << s.age << endl;

   // 'getAge()' will also return uninitialized value at this point
   cout << "age is (via getter): " << s.getAge() << endl;

   // Set age using setter
   s.setAge(10);

   // Now retrieve and print the updated age using getter
   cout << "age after setAge(10): " << s.getAge() << endl;

   return 0;
}

/*
age is (direct access): 0
age is (via getter): 0
age after setAge(10): 10

*/