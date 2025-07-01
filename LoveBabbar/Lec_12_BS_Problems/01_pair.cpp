#include <iostream>
#include <vector> // added for vector support
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

pair<int, int> first_and_last_pos(vector<int> &arr, int key)
{
   return {firstOcc(arr, key), lastOcc(arr, key)};
}

int main()
{
   vector<int> arr = {0, 0, 1, 1, 2, 2, 2, 2, 3, 4};
   int key = 2;
   pair<int, int> result = first_and_last_pos(arr, key);
   cout << "First occurrence: " << result.first << "\nLast occurrence: " << result.second << endl;
   return 0;
}
