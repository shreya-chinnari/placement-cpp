#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the largest element
int findLargestElement(int arr[], int n)
{
   // Base case: only one element
   if (n == 1)
      return arr[0];

   // Recursively find the largest in the rest of the array
   int maxim = findLargestElement(arr, n - 1);

   // Compare with the last element
   return max(arr[n - 1], maxim);
}

int main()
{
   int arr1[] = {2, 5, 1, 3, 0};
   int n = 5;
   int max = findLargestElement(arr1, n);
   cout << "The largest element in the array is: " << max << endl;

   int arr2[] = {8, 10, 5, 7, 9};
   n = 5;
   max = findLargestElement(arr2, n);
   cout << "The largest element in the array is: " << max << endl;

   return 0;
}
