#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<int> arr = {0, 0, 1, 1, 2, 2, 2, 2, 3, 4};
   int key = 2;
   int size = arr.size();
   int first = -1, last = -1;

   // First Occurrence
   int start = 0, end = size - 1;
   while (start <= end)
   {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key)
      {
         first = mid;
         end = mid - 1;
      }
      else if (key > arr[mid])
      {
         start = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
   }

   // Last Occurrence
   start = 0, end = size - 1;
   while (start <= end)
   {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key)
      {
         last = mid;
         start = mid + 1;
      }
      else if (key > arr[mid])
      {
         start = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
   }

   cout << "First occurrence: " << first << endl;
   cout << "Last occurrence: " << last << endl;
   return 0;
}
