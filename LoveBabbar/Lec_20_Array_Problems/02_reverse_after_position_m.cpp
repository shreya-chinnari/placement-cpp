/*
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0
based indexing so the subarray {5, 6} will be reversed and our
output array will be {1, 2, 3, 4, 6, 5}.
*/

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
   // Write your code here

   int start = m + 1;
   int end = arr.size() - 1;

   while (start <= end)
   {
      swap(arr[start], arr[end]);
      start++;
      end--;
   }
}