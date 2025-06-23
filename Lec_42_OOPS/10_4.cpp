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
   Base s;             // Static allocation of Base object
   Base *d = new Base; // Dynamic allocation of Base object
   return 0;
}
// The constructor will be called TWICE because we have two different allocations

// Output:
// constructor called!
// constructor called!