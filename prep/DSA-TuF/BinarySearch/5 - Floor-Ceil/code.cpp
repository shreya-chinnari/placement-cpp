#include <iostream>
using namespace std;

int floor(int arr[], int n, int x)
{
   int low = 0, high = n - 1, ans = -1;
   while (low <= high)
   {
      int mid = (low + high) / 2;

      if (arr[mid] <= x)
      {
         ans = mid;     // mid can be the answer
         low = mid + 1; // search in right half for a larger floor
      }
      else
      {
         high = mid - 1; // search in left half for a smaller floor
      }
   }
   return ans;
}

int ceil(int arr[], int n, int x)
{
   int low = 0, high = n - 1, ans = -1;

   while (low <= high)
   {
      int mid = (low + high) / 2;

      if (arr[mid] >= x)
      {
         ans = mid;      // mid can be the answer
         high = mid - 1; // search in left half for a smaller ceil
      }
      else
      {
         low = mid + 1; // search in right half for a larger ceil
      }
   }
   return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
   int f = floor(arr, n, x);
   int c = ceil(arr, n, x);
   return make_pair(f, c);
}

int main()
{
   int arr[] = {3, 4, 4, 7, 8, 10};
   int n = 6, x = 5;
   pair<int, int> ans = getFloorAndCeil(arr, n, x);
   cout << "The floor and ceil are: " << ans.first
        << " " << ans.second << endl;
   return 0;
}