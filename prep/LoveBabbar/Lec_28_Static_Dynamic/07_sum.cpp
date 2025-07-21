#include <iostream>
using namespace std;

// Function to compute sum of array elements
int getSum(int *arr, int size)
{
   int sum = 0;
   for (int i = 0; i < size; ++i)
   {
      sum += arr[i];
   }
   return sum;
}

int main()
{
   int n;
   cout << "Enter size of the array: ";
   cin >> n;

   // Dynamic array on heap
   int *arr = new int[n];

   // Input array elements
   cout << "Enter " << n << " elements:\n";
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   // Get sum using function
   int total = getSum(arr, n);

   // Print result
   cout << "Sum of array elements = " << total << endl;

   // Free heap memory
   delete[] arr;

   return 0;
}
