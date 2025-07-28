
#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &arr, int threshold)
{
   int n = arr.size();

   int maxi = *max_element(arr.begin(), arr.end());

   // search space for divisor {d} from 1 to maxi

   for (int d = 1; d <= maxi; d++)
   {

      int sum = 0;

      // Calculate the sum of ceil(arr[i] / d) for all elements in arr
      for (int i = 0; i < n; i++)
      {
         sum = sum + ceil((double)(arr[i]) / (double)(d));
      }

      // compare the sum with threshold
      if (sum <= threshold)
      {
         return d; // Found the smallest divisor
      }
   }
   return -1; // If no divisor found that meets the threshold
}

int main()
{
   vector<int> arr = {1, 2, 3, 4, 5};
   int threshold = 8;
   int ans = smallestDivisor(arr, threshold);
   cout << "The minimum divisor is: " << ans << "\n";
   return 0;
}
