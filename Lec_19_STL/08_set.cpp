#include <iostream>
#include <set>      // Required for std::set
#include <iterator> // Required for std::inserter
using namespace std;

// set is a C++ Standard Template Library (STL) container that stores unique elements in a sorted order.
// It is implemented as a balanced binary search tree (usually a Red-Black Tree).
// The elements in a set are always sorted, and it does not allow duplicate values.
// Ypu can only insert or delete elements but you cannot modify existing elements.
// A set is dynamic because it can grow and shrink in size as elements are added or removed.
// It provides logarithmic time complexity for insertion, deletion, and search operations.

// time complexity of insertion, deletion, count and search operations in a set is O(log n), where n is the number of elements in the set.
// size, empty, begin and end operations are O(1) because they simply return the size or iterators without traversing the set.

int main()
{
   // Declare a set of integers
   set<int> set;

   // -----------------------------
   // INSERT ELEMENTS
   // -----------------------------
   set.insert(10); // Inserts 10
   set.insert(10); // Duplicate, will NOT be added
   set.insert(10); // Duplicate, will NOT be added
   set.insert(20); // Inserts 20
   set.insert(5);  // Inserts 5
   set.insert(5);  // Duplicate, will NOT be added
   set.insert(5);  // Duplicate, will NOT be added
   set.insert(30); // Inserts 30
   set.insert(30); // Duplicate, will NOT be added
   set.insert(30); // Duplicate, will NOT be added

   // -----------------------------
   // DISPLAY ELEMENTS (Ascending Order)
   // -----------------------------
   cout << "Elements in set: ";
   for (int x : set)
   {
      cout << x << " ";
   }
   cout << endl;

   // -----------------------------
   // SIZE OF THE SET
   // -----------------------------
   cout << "Size of set: " << set.size() << endl;

   // -----------------------------
   // CHECK IF SET IS EMPTY
   // -----------------------------
   cout << "Is set empty? " << (set.empty() ? "Yes" : "No") << endl;

   // -----------------------------
   // FIND AN ELEMENT
   // -----------------------------
   auto it = set.find(20);
   if (it != set.end())
   {
      cout << "Element 20 found in set.\n";
   }
   else
   {
      cout << "Element 20 not found in set.\n";
   }

   // -----------------------------
   // ERASE AN ELEMENT
   // -----------------------------
   set.erase(10); // Removes element 10 if it exists

   // -----------------------------
   // DISPLAY ELEMENTS AFTER ERASE
   // -----------------------------
   cout << "Set after erasing 10: ";
   for (int x : set)
   {
      cout << x << " ";
   }
   cout << endl;

   // -----------------------------
   // LOWER BOUND & UPPER BOUND
   // -----------------------------
   // lower_bound(x): returns iterator to first element >= x
   // upper_bound(x): returns iterator to first element > x
   auto lb = set.lower_bound(15);
   auto ub = set.upper_bound(20);

   if (lb != set.end())
      cout << "Lower bound of 15: " << *lb << endl;
   else
      cout << "Lower bound of 15 not found.\n";

   if (ub != set.end())
      cout << "Upper bound of 20: " << *ub << endl;
   else
      cout << "Upper bound of 20 not found.\n";

   // -----------------------------
   // COUNT (Only 0 or 1 in set)
   // -----------------------------
   cout << "Does 5 exist? " << (set.count(5) ? "Yes" : "No") << endl;

   // -----------------------------
   // CLEAR THE SET
   // -----------------------------
   set.clear();
   cout << "Set cleared. Is it empty now? " << (set.empty() ? "Yes" : "No") << endl;

   return 0;
}
