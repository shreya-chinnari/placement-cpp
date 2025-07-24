// using Linear Search to find first and last occurrence of target in sorted array

#include <iostream>
using namespace std;

pair<int, int> occurrences(int arr[], int n, int x)
{
   int first = -1, last = -1;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] == x)
      {
         if (first == -1)
         {
            first = i; // first occurrence
         }
         last = i; // last occurrence
      }
   }
   return make_pair(first, last);
}

int main()
{
   int arr[] = {1, 2, 2, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 2;

   pair<int, int> result = occurrences(arr, n, x);
   if (result.first != -1)
      cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << endl;
   else
      cout << "Element not found in array." << endl;

   return 0;
}
