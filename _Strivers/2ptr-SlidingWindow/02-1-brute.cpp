// longest subarray with sum <= k

#include <iostream>
using namespace std;

int maxLength(int arr[], int size, int k)
{
   int maxLen = 0;

   for (int i = 0; i < size; i++)
   {
      int sum = 0;                   // Reset for each starting index
      for (int j = i; j < size; j++) // j=i
      {
         sum = sum + arr[j];

         if (sum <= k)
         {
            maxLen = max(maxLen, j - i + 1);
         }
         else if (sum > k)
            break;
      }
   }
   return maxLen;
}

int main()
{
   int arr[10] = {2, 7, 9, 4, 2, 5, 7, 3, 2, 2};
   cout << "max length : " << maxLength(arr, 10, 19);

   return 0;
}