#include <iostream>
#include <vector>
#include <algorithm> // for sort, reverse, find, etc.
using namespace std;

/*
A vector is dynamic because it automatically resizes its storage to accommodate new elements as they are added.
*/

int main()
{
   // 🔹 Declaration & Initialization
   vector<int> v = {10, 20, 30, 40, 50};

   // 🔹 Add elements using push_back
   v.push_back(60);
   v.push_back(70);

   // 🔹 Display vector using range-based loop
   cout << "Initial vector: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Size and Capacity
   cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;

   /*
   🧠 Why Does Capacity Matter?

         Frequent memory allocations are expensive.
         STL vector increases capacity exponentially (usually doubles it) to amortize the cost of growing.

         vector<int> v;
           - v.push_back(10);     // size = 1, capacity could be 1, 2, or more depending on implementation
           - v.push_back(20);     // size = 2, capacity might double
   */

   // 🔹 Access elements
   cout << "First element: " << v.front() << endl;
   cout << "Last element: " << v.back() << endl;
   cout << "Element at index 2: " << v.at(2) << endl;

   // 🔹 Insert at specific position
   v.insert(v.begin() + 2, 25); // Insert 25 at index 2
   cout << "After insert at index 2: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Remove from specific position
   v.erase(v.begin() + 3); // Remove element at index 3
   cout << "After erase at index 3: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Sort the vector
   sort(v.begin(), v.end());
   cout << "Sorted vector: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Reverse the vector
   reverse(v.begin(), v.end());
   cout << "Reversed vector: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Find an element
   auto it = find(v.begin(), v.end(), 30);
   if (it != v.end())
      cout << "Element 30 found at index: " << distance(v.begin(), it) << endl;
   else
      cout << "Element 30 not found." << endl;

   // 🔹 Resize vector
   v.resize(5); // Shrink to 5 elements
   cout << "After resize to 5: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   v.resize(7, 99); // Expand to 7, fill new with 99
   cout << "After resize to 7 with default 99: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Clear all elements
   v.clear();
   cout << "After clear, is vector empty? " << (v.empty() ? "Yes" : "No") << endl;

   // 🔹 Assign new values
   v.assign(4, 100); // 4 elements of value 100
   cout << "After assign: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Swap with another vector
   vector<int> v2 = {1, 2, 3};
   v.swap(v2);
   cout << "After swap, v: ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   // 🔹 Shrink to fit (reduce capacity)
   v.shrink_to_fit();
   cout << "Final size: " << v.size() << ", capacity: " << v.capacity() << endl;

   // 🔹 Pop the last element
   v.pop_back(); // Removes 70

   // 🔹 Display vector after pop_back
   cout << "After pop_back (removed last element): ";
   for (int val : v)
      cout << val << " ";
   cout << endl;

   vector<int> v3(5, 1); // Initialize v3 with 5 elements, all set to 1
   cout << "v3 initialized with 5 elements of value 1: ";
   for (int val : v3)
      cout << val << " ";
   cout << endl;

   vector<int> copy(v3);
   cout << "Copy of v3: ";
   for (int val : copy)
      cout << val << " ";
   cout << endl;

   return 0;
}
