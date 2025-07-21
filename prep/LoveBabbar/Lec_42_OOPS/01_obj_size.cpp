#include <iostream>
using namespace std;

class name
{
   int age;
   int height;
   string name;
};

int main()
{
   name obj;
   // The object 'obj' of class 'name' is created, but it does not have any value assigned to its members, so it has garbage values for now, they are uninitialized.

   cout << "size of object: " << sizeof(obj) << endl;
   // The size of the object 'obj' is determined by the size of its members.
   // The size of an object is the sum of the sizes of its members, plus any padding added by the compiler for alignment purposes.
   return 0;
}

// size of object: 40