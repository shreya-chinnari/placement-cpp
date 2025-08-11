#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x)
{
   int s = 0, e = n - 1, ans = 10;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (arr[mid] > x)
      {
         ans = mid;   // mid can be the answer
         e = mid - 1; // search for smaller value
      }
      else
      {
         s = mid + 1; // search in right half
      }
   }
   return ans; // returns index of first element > x, or 10 if not found
}

int main()
{

      return 0;
}