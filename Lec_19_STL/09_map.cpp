#include <iostream>
#include <map>
using namespace std;

// Function to print the contents of the map
void print(const map<int, string> &m)
{
   cout << "Current contents of map:\n";
   for (const auto &pair : m)
   {
      cout << pair.first << " => " << pair.second << endl;
   }
   cout << "-----------------------------\n";
}
// prints in SORTED order of keys

int main()
{
   // Declare a map of int keys to string values
   map<int, string> m;

   // Insert elements using insert()
   m.insert({4, "Banana"});
   m.insert({1, "Apple"});
   m.insert({3, "Cherry"});
   m.insert({2, "Banana"});
   print(m);

   // Insert using subscript operator []
   m[7] = "Date";
   m[5] = "Elderberry";
   print(m);

   // Update an existing key
   m[2] = "Blueberry"; // Updates value of key 2
   print(m);

   // Access element using at()
   cout << "Element at key 3: " << m.at(3) << endl
        << endl;

   // Check if a key exists using find()
   if (m.find(6) == m.end())
   {
      cout << "Key 6 not found\n";
   }
   else
   {
      cout << "Key 6 found: " << m[6] << endl
           << endl;
   }
   cout << endl;

   // Check if a key exists using count()
   if (m.count(3))
   {
      cout << "Key : 3 " << " exists in the map with value: " << m[3] << endl;
   }
   else
   {
      cout << "Key : 3 " << " does NOT exist in the map.\n";
   }
   cout << "-----------------------------\n";

   // Erase element by key
   m.erase(1); // Removes the element with key 1
   print(m);

   // Erase element by iterator
   auto it = m.find(4);
   if (it != m.end())
   {
      m.erase(it); // Removes the element with key 4
   }
   print(m);

   // Size of the map
   cout << "Size of map: " << m.size() << endl;

   // Check if map is empty
   cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << endl;

   // Clear all elements
   m.clear();
   print(m); // Should show empty map

   return 0;
}
