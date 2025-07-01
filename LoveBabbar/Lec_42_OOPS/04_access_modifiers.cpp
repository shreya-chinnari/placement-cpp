#include <iostream>
using namespace std;

class C
{
public:
   int age;

private:
   int height;
   // Private members (height): Can only be accessed within the class itself. Can be accessed by member functions of the class {functions inside the class}, but not by objects of the class or derived classes.

protected:
   string name;
   // Protected members(name) : Can be accessed in derived classes, but not in main().
};

int main()
{
   C obj;

   obj.age = 25; // ✅ OK, 'age' is public, so can be accessed directly
   cout << "age: " << obj.age << endl;

   // ❌ The following lines will cause compilation errors:

   // obj.height = 180;     // 'height' is private → inaccessible
   // obj.name = "John";    // 'name' is protected → inaccessible

   return 0;
}
