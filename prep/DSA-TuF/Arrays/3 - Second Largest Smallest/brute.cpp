#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> secondLargestAndSmallest(int arr[], int n)
{
   if (n == 0 || n == 1)
   {
      return {-1, -1}; // Not enough elements
   }

   sort(arr, arr + n);

   int secondLargest = arr[n - 2];
   int secondSmallest = arr[1];

   return {secondLargest, secondSmallest};
}

// tc : O(n log n) because of sorting
// sc : O(1) because we are using a fixed amount of space to store the result

int main()
{
   int arr[] = {12, 13, 1, 10, 34};
   int n = sizeof(arr) / sizeof(arr[0]);
   pair<int, int> result = secondLargestAndSmallest(arr, n);
   cout << result.first << " " << result.second << endl; // Output second largest and second smallest
   return 0;
}