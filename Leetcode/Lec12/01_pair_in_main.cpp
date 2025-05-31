#include <iostream>
#include <vector>
using namespace std;

int firstOcc(const vector<int> &arr, int key)
{
   int start = 0, end = arr.size() - 1, index = -1;
   while (start <= end)
   {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key)
      {
         index = mid;
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
   return index;
}

int lastOcc(const vector<int> &arr, int key)
{
   int start = 0, end = arr.size() - 1, index = -1;
   while (start <= end)
   {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key)
      {
         index = mid;
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
   return index;
}

int main()
{
   vector<int> arr = {0, 0, 1, 1, 2, 2, 2, 2, 3, 4};
   int key = 2;

   pair<int, int> p;
   p.first = firstOcc(arr, key);
   p.second = lastOcc(arr, key);

   cout << "First occurrence: " << p.first << "\n Last occurrence: " << p.second << endl;
   return 0;
}
