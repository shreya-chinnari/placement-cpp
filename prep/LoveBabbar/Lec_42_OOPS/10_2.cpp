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
   // jab aap khud hi constructor define karte ho, toh compiler default constructor nahi banata, woh delete ho jata hai
   // jo aap banayenge wahi exist karega
};

int main()
{
   Base person; // Static allocation of Base object
   return 0;
}
// The constructor will be called automatically when the object is created
// Output: constructor called!