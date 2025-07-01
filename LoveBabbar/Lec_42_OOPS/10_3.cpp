#include <iostream>
using namespace std;

class Base
{
private:
   int age;
   string name;

public:
   Base()
   {
      cout << "constructor called!" << endl;
   } // Default constructor
};

int main()
{
   Base *person = new Base; // Dynamic allocation of Base object
   return 0;
}
// The constructor will be called automatically when the object is created
// Output: constructor called!