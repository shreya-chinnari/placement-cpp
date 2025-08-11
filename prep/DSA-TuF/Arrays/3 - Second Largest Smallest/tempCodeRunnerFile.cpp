#include <iostream>
#include <algorithm>
using namespace std;

pair<int> secondLargestAndSmallest(int arr[], int n)
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

int main()
{
   int arr[] = {12, 13, 1, 10, 34};
   int n = sizeof(arr) / sizeof(arr[0]);
   pair<int> result = secondLargestAndSmallest(arr, n);
   return 0;
}