// Peak Index in a Mountain Array

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   int peakIndexInMountainArray(vector<int> &arr)
   {
      int start = 0;
      int end = arr.size() - 1;

      int mid = start + (end - start) / 2;
      while (start < end)
      {
         if (arr[mid] < arr[mid + 1])
         {
            start = mid + 1;
         }
         else
         {
            end = mid; // in both cases - whether arr[mid] > arr[mid+1] OR peak element is the end element
         }
         mid = start + (end - start) / 2;
      }
      return start;
   }
};

int main()
{
   Solution sol;

   vector<int> arr = {0, 2, 4, 7, 9, 6, 3, 1};

   int peakIndex = sol.peakIndexInMountainArray(arr);

   cout << "Peak index is: " << peakIndex << endl;
   cout << "Peak element is: " << arr[peakIndex] << endl;

   return 0;
}
