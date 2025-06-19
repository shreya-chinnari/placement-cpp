#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int beautifulTriplets(int d, const vector<int> &arr)
{
   unordered_set<int> elements(arr.begin(), arr.end()); // For O(1) lookups
   int count = 0;

   for (int i = 0; i < arr.size(); i++)
   {
      int first = arr[i];
      int second = first + d;
      int third = second + d;

      // Check if all elements in the triplet exist
      if (elements.count(second) && elements.count(third))
      {
         count++;
      }
   }

   return count;
}

int main()
{
   int n, d;
   cin >> n >> d;
   vector<int> arr(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> arr[i];
   }

   cout << "no. of beautiful triplets: " << beautifulTriplets(d, arr) << endl;
   return 0;
}
