
#include <bits/stdc++.h>
using namespace std;
int secondLargest(int arr[], int n)
{
   sort(arr, arr + n);

   int largest = arr[n - 1];

   // Loop from second last down to 0 to find second distinct largest
   for (int i = n - 2; i >= 0; i++)
   {
      if (arr[i] != largest)
      {
         return arr[i];
      }
   }
   return -1; // No second largest (all elements same)
}
int secondSmallest(int arr[], int n)
{
   sort(arr, arr + n);

   int smallest = arr[0];

   // Loop from second last down to 0 to find second distinct largest
   for (int i = 1; i < n; i++)
   {
      if (arr[i] != smallest)
      {
         return arr[i];
      }
   }
   return -1; // No second largest (all elements same)
}

int main()
{
   int arr1[] = {1, 2, 4, 6, 7, 5};
   int n = sizeof(arr1) / sizeof(arr1[0]);
   cout << "Second largest: " << secondLargest(arr1, n) << endl;

   int arr2[] = {1};
   n = sizeof(arr2) / sizeof(arr2[0]);
   cout << "Second largest: " << secondLargest(arr2, n) << endl;

   int arr3[] = {4, 4, 4}; // All elements same
   n = sizeof(arr3) / sizeof(arr3[0]);
   cout << "Second largest: " << secondLargest(arr3, n) << endl;

   int arr4[] = {1, 2, 4, 6, 7, 5};
   n = sizeof(arr4) / sizeof(arr4[0]);
   cout << "Second smallest: " << secondSmallest(arr4, n) << endl;

   int arr5[] = {1};
   n = sizeof(arr5) / sizeof(arr5[0]);
   cout << "Second smallest: " << secondSmallest(arr5, n) << endl;

   int arr6[] = {4, 4, 4}; // All elements same
   n = sizeof(arr6) / sizeof(arr6[0]);
   cout << "Second smallest: " << secondSmallest(arr6, n) << endl;

   return 0;
}
