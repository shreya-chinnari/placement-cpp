#include <iostream>
#include <array>
#include <algorithm> // for sort, reverse, etc.
using namespace std;

int main()
{
   // 🔸 Declaration and Initialization
   array<int, 5> arr = {5, 2, 9, 1, 7};

   // 🔸 Accessing Elements
   cout << "Elements using at(): ";
   for (int i = 0; i < arr.size(); i++)
      cout << arr.at(i) << " "; // bounds-checked access
   cout << endl;

   // 🔸 Front and Back
   cout << "First element (front): " << arr.front() << endl;
   cout << "Last element (back): " << arr.back() << endl;

   // 🔸 Size and Capacity
   cout << "Size of array: " << arr.size() << endl;

   // 🔸 Fill entire array with a single value
   arr.fill(100);
   cout << "After fill(100): ";
   for (int val : arr)
      cout << val << " ";
   cout << endl;

   // 🔸 Reassign values for further operations
   arr = {5, 2, 9, 1, 7};

   // 🔸 Sort the array
   sort(arr.begin(), arr.end());
   cout << "Sorted array: ";
   for (int val : arr)
      cout << val << " ";
   cout << endl;

   // 🔸 Reverse the array
   reverse(arr.begin(), arr.end());
   cout << "Reversed array: ";
   for (int val : arr)
      cout << val << " ";
   cout << endl;

   // 🔸 Check if array is empty
   cout << "Is array empty? " << (arr.empty() ? "Yes" : "No") << endl;

   // 🔸 Swap contents with another array
   array<int, 5> arr2 = {10, 20, 30, 40, 50};
   arr.swap(arr2);
   cout << "After swap, arr: ";
   for (int val : arr)
      cout << val << " ";
   cout << endl;

   // 🔸 Direct data access (C-style)
   int *ptr = arr.data(); // Returns pointer to first element
   cout << "First element using data(): " << *ptr << endl;

   // Empty or Not
   cout << "Is arr2 empty? " << (arr2.empty() ? "Yes" : "No") << endl;

   return 0;
}
