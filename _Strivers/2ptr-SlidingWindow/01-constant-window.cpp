// maximum sum of "k" consecutive elements in an array
// TYPE - 1 : constant window

#include <iostream>
using namespace std;

int maximumSum(int arr[], int size, int k)
{
   int sum = 0;
   int start = 0, end = k - 1;

   for (int i = 0; i <= end; i++)
   {
      sum = sum + arr[i];
   }
   cout << "\n [" << arr[start] << " , " << arr[end] << "] : " << sum;

   int maxSum = sum;
   while (end < size - 1)
   {
      sum = sum - arr[start];
      start++;
      end++;

      sum = sum + arr[end];
      cout << "\n [" << arr[start] << " , " << arr[end] << "] : " << sum;
      maxSum = max(sum, maxSum);
   }
   cout << "\n max sum : ";

   return maxSum;
}

int main()
{
   int arr[10] = {1, 7, 3, 9, 3, 9, 4, 2, 3, 9};
   cout << maximumSum(arr, 10, 4);

   return 0;
}