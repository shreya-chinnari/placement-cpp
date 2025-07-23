#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

int main()
{

   // VECTOR ------------------------------------

   vector<int> vec = {1, 2, 4, 4, 5, 7, 9}; // Sorted vector
   int n = 4;                               // Element to find lower bound of

   // lower_bound returns iterator to first element >= n
   auto it1 = lower_bound(vec.begin(), vec.end(), n);

   // Index of lower bound
   int lb1 = it1 - vec.begin();

   cout << "Lower bound of " << n << " is at index: " << lb1 << endl;
   // Output: Lower bound of 4 is at index: 2 (first 4 appears at index 2)

   // ARRAYS ------------------------------------

   int arr[] = {1, 2, 4, 4, 5, 7, 9};
   int m = 4;
   int size = sizeof(arr) / sizeof(arr[0]);

   // lower_bound returns pointer to first element >= n
   auto it2 = lower_bound(arr, arr + size, m);

   // Index is pointer difference
   int lb2 = it2 - arr;

   cout << "Lower bound of " << m << " is at index: " << lb2 << endl;
   return 0;
}
