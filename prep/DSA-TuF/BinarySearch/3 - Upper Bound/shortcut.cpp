#include <iostream>
#include <vector>
#include <algorithm> // for upper_bound
using namespace std;

int main()
{

   // VECTOR ------------------------------------
   vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int n = 5;

   auto it1 = upper_bound(v.begin(), v.end(), n);
   int ub1 = it1 - v.begin();

   cout << "Upper bound of " << n << " is at index: " << ub1 << endl;

   // ARRAYS ------------------------------------

   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int m = 5;
   int size = sizeof(arr) / sizeof(arr[0]);

   auto it2 = upper_bound(arr, arr + size, m);
   int ub2 = it2 - arr;
   cout << "Upper bound of " << m << " is at index: " << ub2 << endl;
   return 0;
}