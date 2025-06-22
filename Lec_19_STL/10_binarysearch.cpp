#include <iostream>
#include <vector>
#include <algorithm> // For binary_search, lower_bound, upper_bound
using namespace std;

// Function to print the contents of the vector
void printVector(const vector<int> &v)
{
   cout << "Current elements: ";
   for (int val : v)
   {
      cout << val << " ";
   }
   cout << "\n";
}

int main()
{
   // Sample sorted vector
   vector<int> v = {10, 20, 30, 40, 50};

   // Print the initial vector
   printVector(v);

   // Binary Search (returns true if element is present)
   int target = 30;
   if (binary_search(v.begin(), v.end(), target))
   {
      cout << target << " found in the vector.\n";
   }
   else
   {
      cout << target << " not found in the vector.\n";
   }

   // Lower Bound (returns first [position] where value >= target)
   auto lower = lower_bound(v.begin(), v.end(), 30);
   if (lower != v.end())
      cout << "Lower bound of 30 is at index: " << (lower - v.begin()) << "\n";

   // Upper Bound (returns first [position] where value > target)
   auto upper = upper_bound(v.begin(), v.end(), 30);
   if (upper != v.end())
      cout << "Upper bound of 30 is at index: " << (upper - v.begin()) << "\n";

   // Insertion of an element while maintaining sorted order
   int newElement = 25;
   auto pos = lower_bound(v.begin(), v.end(), newElement);
   v.insert(pos, newElement);
   cout << newElement << " inserted.\n";
   printVector(v);

   // Deletion of an element
   int deleteElement = 40;
   auto it = lower_bound(v.begin(), v.end(), deleteElement);
   if (it != v.end() && *it == deleteElement)
   {
      v.erase(it);
      cout << deleteElement << " deleted.\n";
   }
   else
   {
      cout << deleteElement << " not found, cannot delete.\n";
   }
   printVector(v);

   // Count occurrences (useful if duplicates are allowed)
   int countTarget = 20;
   auto first = lower_bound(v.begin(), v.end(), countTarget);
   // Finds the first position where an element is greater than or equal to countTarget. This points to the first occurrence of 20 (if it exists).
   auto last = upper_bound(v.begin(), v.end(), countTarget);
   // Finds the first position where an element is strictly greater than countTarget.This points just after the last occurrence of 20.
   int count = last - first;

   // The difference between the two iterators gives the count of occurrences of countTarget.
   cout << "Count of " << countTarget << ": " << count << "\n";

   return 0;
}
