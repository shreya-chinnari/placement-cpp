
#include <bits/stdc++.h>
using namespace std;

int sumOfCeils(vector<int> &arr, int div)
{
   int n = arr.size();

   int sum = 0;

   for (int i = 0; i < n; i++)
   {
      sum = sum + ceil((double)(arr[i] / (double)(div)));
      // sum = sum + ((arr[i] + div - 1)/div);
   }

   return sum;
}
int smallestDivisor(vector<int> &arr, int threshold)
{
   int n = arr.size();

   // edge case
   if (n > threshold)
      return -1; // as sum of ceil(arr[i] / d) will never be less than n

   // apply Binary Search on the answer space
   int s = 1, e = *max_element(arr.begin(), arr.end());

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (sumOfCeils(arr, mid) <= threshold)
      {
         e = mid - 1; // need to find a smaller divisor
      }
      else
      {
         s = mid + 1; // need to find a larger divisor which makes the (sumOfCeils <= threshold)
      }
   }
   return s; // "s" will always have the smallest divisor possible
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   int limit = 8;
   int ans = smallestDivisor(arr, limit);
   cout << "The minimum divisor is: " << ans << "\n";
   limit = 24;
   ans = smallestDivisor(arr, limit);
   cout << "The minimum divisor is: " << ans << "\n";
   return 0;
}
