#include <iostream>
using namespace std;

class name
{
   // empty
};

int main()
{
   name obj;
   cout << "size of object: " << sizeof(obj) << endl;
   return 0;
}

// size of object: 1

// An empty class in C++ has a size of 1 byte. This is to ensure that each object of the class has a unique address in memory, even if it contains no data members. This is a requirement of the C++ standard to allow for polymorphism and to ensure that objects can be distinguished from one another. The size of 1 byte is the minimum size for any object in C++.