/*
First and Last Position of an Element In Sorted Array
=====================================================
Problem statement
=====================================================
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1.
2. 'arr' may contain duplicate elements.

Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1
Output: 1 2

Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8 2
0 0 1 1 2 2 2 2

Sample output 1:
4 7

Explanation of Sample output 1:
For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.
=====================================================

*/
#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> &arr, int size, int key)
{
   int start = 0, end = size - 1, mid = start + (end - start) / 2;
   int index = -1; // not found

   while (start <= end)
   {
      if (arr[mid] == key)
      {
         index = mid;
         end = mid - 1; // search in the left half for first occurrence
      }
      else if (key > arr[mid])
      {
         start = mid + 1; // key is in the right half
      }
      else if (key < arr[mid])
      {
         end = mid - 1; // key is in the left half
      }
      mid = start + (end - start) / 2; // recalculate mid
   }
   return index; // return the first occurrence index
}

int lastOcc(vector<int> &arr, int size, int key)
{
   int start = 0, end = size - 1, mid = start + (end - start) / 2;
   int index = -1; // not found

   while (start <= end)
   {
      if (arr[mid] == key)
      {
         index = mid;
         start = mid + 1; // search in the right half for last occurrence
      }
      else if (key > arr[mid])
      {
         start = mid + 1; // key is in the right half
      }
      else if (key < arr[mid])
      {
         end = mid - 1; // key is in the left half
      }
      mid = start + (end - start) / 2; // recalculate mid
   }
   return index; // return the first occurrence index
}

pair<int, int> first_and_last_pos(vector<int> &arr, int size, int key)
{
   int first = firstOcc(arr, size, key);
   int last = lastOcc(arr, size, key);
   return {first, last}; // return a pair of first and last occurrences

   pair<int, int> p; // Initialize a pair to store first and last occurrences
   p.first = firstOcc(arr, size, key);
   p.second = lastOcc(arr, size, key);
   return p; // return the pair containing first and last occurrences
}

int main()
{
   vector<int> arr = {0, 0, 1, 1, 2, 2, 2, 2, 3, 4};
   int key = 2;
   int size = arr.size();

   pair<int, int> result = first_and_last_pos(arr, size, key);

   cout << "First occurrence of " << key << " is at index: " << result.first << endl;
   cout << "Last occurrence of " << key << " is at index: " << result.second << endl;

   return 0;

   // int arr[10] = {0, 0, 1, 1, 2, 2, 2, 2, 3, 4};
   // int key = 2;
   // cout << "First occurrence of 2 is at index: " << firstOcc(arr, 10, key) << endl;
   // cout << "Last occurrence of 2 is at index: " << lastOcc(arr, 10, key) << endl;
   // return 0;
}