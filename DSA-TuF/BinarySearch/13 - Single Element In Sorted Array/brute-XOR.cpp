
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
   int n = arr.size(); // size of the array.
   int ans = 0;
   // XOR all the elements:
   for (int i = 0; i < n; i++)
   {
      ans = ans ^ arr[i];
   }
   return ans;
}

int main()
{
   vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
   int ans = singleNonDuplicate(arr);
   cout << "The single element is: " << ans << "\n";
   return 0;
}
