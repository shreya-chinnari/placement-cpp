#include <iostream>
#include <list>
#include <algorithm> // for std::find, std::for_each
using namespace std;

// "list" is a [DOUBLY LINKED LIST] implementation in C++ STL.
// It allows for efficient insertion and deletion of elements at any position.
// It is not contiguous in memory, so it does not support random access like vectors or arrays.
// It is particularly useful when you need to frequently insert or delete elements from the middle of the collection.
// A list is dynamic because it can grow and shrink in size as elements are added or removed.
// It used 2 pointers per element: one for the next element and one for the previous element.

int main()
{
   cout << "\n";
   cout << "\n";
   cout << "\n";

      // Create an empty list of integers
   list<int> l;

   // ====== INSERTION ======
   l.push_back(10);    // Inserts at the end
   l.push_front(5);    // Inserts at the beginning
   l.emplace_back(15); // Constructs and inserts at the end
   l.emplace_front(2); // Constructs and inserts at the beginning

   /*
   push_back(15): Inserts a copy (or move) of the value 15 at the end of the list.

   emplace_back(15): Constructs the element in-place at the end. This is more efficient if the element is a complex object (like a class or struct), because it avoids unnecessary copy/move.
   */

   // ====== DISPLAY CONTENT ======
   cout << "List contents: ";
   for (int val : l)
      cout << val << " "; // Output: 2 5 10 15
   cout << "\n";

   // ====== SIZE & EMPTY CHECK ======
   cout << "List size: " << l.size() << "\n";
   cout << "Is list empty? " << (l.empty() ? "Yes" : "No") << "\n";

   // ====== ACCESS FRONT & BACK ======
   cout << "Front: " << l.front() << "\n";
   cout << "Back: " << l.back() << "\n";

   // ====== REMOVAL ======
   l.pop_front(); // Removes 2
   l.pop_back();  // Removes 15
   cout << "List contents after removal: ";
   for (int val : l)
      cout << val << " "; // Output: 5 10
   cout << "\n";

   // ====== INSERT & ERASE USING ITERATORS ======
   auto it = l.begin();
   advance(it, 1);  // Move iterator to second position
   l.insert(it, 7); // Insert 7 before 10

   cout << "List contents after inserting 7: ";
   for (int val : l)
      cout << val << " "; // Output: 5 7 10
   cout << "\n";

   // ====== ERASE ======
   it = l.begin();
   advance(it, 1); // Move to the inserted element 7
   l.erase(it);    // Erase the element at the position

   cout << "List contents after removal of element [l.begin + 1]: ";
   for (int val : l)
      cout << val << " "; // Output: 5 10
   cout << "\n";

   // ====== REMOVE BY VALUE ======
   l.push_back(10);
   l.remove(10); // Removes all occurrences of 10

   cout << "List contents after removal of all 10s: ";
   for (int val : l)
      cout << val << " "; // Output: 5
   cout << "\n";
   cout << "\n";

   // ====== REMOVE BY CONDITION ======
   l.push_back(20);
   l.push_back(25);
   cout << "List contents: ";
   for (int val : l)
      cout << val << " "; // Output: 5 10
   cout << "\n";
   l.remove_if([](int x)
               { return x > 20; }); // Removes elements > 20
   cout << "List contents after removing elements > 20: ";
   for (int val : l)
      cout << val << " "; // Output: 5 20
   cout << "\n";

   // ====== SORT ======
   l.push_back(3);
   l.push_back(1);
   l.push_back(4);
   l.sort(); // Sorts the list in ascending order

   cout << "List contents after sorting: ";
   for (int val : l)
      cout << val << " "; // Output: 1 3 4 5 20
   cout << "\n";

   // ====== REVERSE ======
   l.reverse(); // Reverses the order of elements
   cout << "List contents after reverse: ";
   for (int val : l)
      cout << val << " "; // Output: 20 5 4 3 1
   cout << "\n";
   cout << "\n";

   // ====== UNIQUE ======
   l.push_back(4);
   l.push_back(4);
   cout << "List contents: ";
   for (int val : l)
      cout << val << " "; // Output:  20 5 4 3 1 4 4
   cout << "\n";
   l.unique(); // Removes consecutive duplicates (not all)

   cout << "List contents after removing consecutive duplicates: ";
   for (int val : l)
      cout << val << " "; // Output: 20 5 4 3 1 4
   cout << "\n";

   // ====== MERGE ======
   list<int> anotherList = {1, 2, 3};
   anotherList.sort();
   l.sort();
   l.merge(anotherList); // Merges and sorts

   cout << "List contents after merging: ";
   for (int val : l)
      cout << val << " "; // Output: 1 1 2 3 3 4 4 5 20
   cout << "\n";

   // ====== SPLICE (Move elements from another list) ======
   list<int> spliceList = {100, 200};
   auto pos = l.begin();
   advance(pos, 2);
   l.splice(pos, spliceList); // Splice all elements at pos

   cout << "List contents after splice(): ";
   for (int val : l)
      cout << val << " "; // Output: 1 1 [100 200] 2 3 3 4 4 5 20
   cout << "\n";
   cout << "\n";

   // ====== CLEAR ======
   l.clear(); // Uncomment to remove all elements
   cout << "List contents after clear(): ";
   for (int val : l)
      cout << val << " ";
   cout << "\n";
   cout << "\n";
   cout << "\n";
}