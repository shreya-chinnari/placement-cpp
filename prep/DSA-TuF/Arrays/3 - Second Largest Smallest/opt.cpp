#include <iostream>
using namespace std;

// now we have to reduce the time complexity from O(2n) to O(n)

// without sorting : tc reduced from O(n log n) to O(2n)
// without 2 traverals, O(2n) to O(n)

int secondLargest(int arr[], int n)
{
   if (n < 2)
   {
      return -1; // Not enough elements
   }

   int largest = INT_MIN, secondLargest = INT_MIN;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] > largest)
      {
         secondLargest = largest;
         largest = arr[i];
      }
      else if (arr[i] > secondLargest && arr[i] != largest)
      {
         secondLargest = arr[i];
      }
   }
   return secondLargest; // Return second largest element
}

int secondSmallest(int arr[], int n)
{
   if (n < 2)
   {
      return -1; // Not enough elements
   }

   int smallest = INT_MAX, secondSmallest = INT_MAX;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] < smallest)
      {
         secondSmallest = smallest;
         smallest = arr[i];
      }
      else if (arr[i] < secondSmallest && arr[i] != smallest)
      {
         secondSmallest = arr[i];
      }
   }
   return secondSmallest; // Return second smallest element
}

int main()
{

   int arr[] = {12, 13, 1, 10, 34};
   int n = sizeof(arr) / sizeof(arr[0]);
   int secondLargestValue = secondLargest(arr, n);
   int secondSmallestValue = secondSmallest(arr, n);
   cout << "Second Largest: " << secondLargestValue << endl;
   cout << "Second Smallest: " << secondSmallestValue << endl;
   return 0;
}