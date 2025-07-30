#include <iostream>
#include <set>
using namespace std;

// use a set
// to store unique elements
// then copy the set back to the array

// set in C++ is implemented as a balanced binary search tree { Red-Black Tree }
// each insert operation takes O(log n) time
// hence, the overall time complexity is O(n log n) assuming worst case : all n elements are unique

// copying the set back to the array takes O(n) time
// hence, the overall time complexity is O(n log n) + O(n) = O(n log n + n)

// we create an int function, where we return the size of the set

int removeDuplicates(int arr[], int n)
{
   // 1. create a set

   set<int> s;

   // 2. insert all elements of the array into the set
   for (int i = 0; i < n; i++)
   {
      s.insert(arr[i]);
   }

   // 3. copy the set back to the array
   int k = s.size();
   int j = 0; // index for the array

   for (auto it = s.begin(); it != s.end(); it++)
   {
      arr[j++] = *it; // copy the elements of the set to the array
   }

   // OR
   // for(int x : s) {
   //     arr[j++] = x;
   //}

   // 4. return the size of the set
   return k; // return the number of unique elements
}

int main()
{

   int arr[] = {12, 13, 1, 10, 34, 12, 13}; // example array with duplicates
   int n = sizeof(arr) / sizeof(arr[0]);    // size of the array

   int k = removeDuplicates(arr, n);

   for (int i = 0; i < k; i++)
   {
      cout << arr[i] << " ";
   }

   return 0;
}