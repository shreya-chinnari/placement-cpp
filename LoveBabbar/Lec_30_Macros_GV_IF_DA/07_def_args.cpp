// Default arguments allow you to assign default values to function parameters. If the caller omits those arguments, the compiler uses the default values.

#include <iostream>
using namespace std;

void greet(string name = "Guest", int age = 18)
{
   cout << "Hello, " << name << "! Age: " << age << endl;
}

int main()
{
   greet();            // Uses both default values
   greet("Shreya");    // Uses default age
   greet("Rahul", 25); // No defaults used
   return 0;
} 

/*
Hello, Guest! Age: 18
Hello, Shreya! Age: 18
Hello, Rahul! Age: 25
*/