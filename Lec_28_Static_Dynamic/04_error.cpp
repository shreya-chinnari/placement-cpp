#include <iostream>
#include <string>
using namespace std;

string &getName()
{
   string name = "Shreya"; // Local variable (lives only during function call)
   return name;            // ❌ Returning reference to local variable
}

int main()
{
   string &ref = getName();                    // ref refers to destroyed variable
   cout << "Returned string: " << ref << endl; // ⚠️ Undefined behavior
   return 0;
}

// SAFE METHOD - uncomment it
/*

#include <iostream>
#include <string>
using namespace std;

// Return by value — safe & efficient with modern compilers

string getName() {
    string name = "Shreya";
    return name;  // ✅ Safe: returns a copy of 'name'
}

int main() {
    string result = getName();  // Safe: stores the returned value
    cout << "Returned string: " << result << endl;

    return 0;
}

*/