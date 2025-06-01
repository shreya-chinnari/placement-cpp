/*
AGGRESSIVE COWS PROBLEM

You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Print the maximum possible minimum distance.

Example:

   Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
   Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

   Sample Input 1 :
   6 4
   0 3 4 7 10 9

   Sample Output 1 :
   3

   Explanation to Sample Input 1 :
   The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int total_cows, int minDist)
{
   int cowCount = 1;                // place the first cow in the first stall
   int lastCowPosition = stalls[0]; // position of the last placed cow

   // iterate through the stalls to place "total_cows" no. of cows
   for (int stall_position = 0; stall_position < stalls.size(); stall_position++)
   {
      if (stalls[stall_position] - lastCowPosition >= minDist) // check if the current stall can accommodate a cow
      {
         cowCount++;                 // place a cow in the current stall
         if (cowCount == total_cows) // if all cows are placed
         {
            return true; // return true as we have successfully placed all cows
         }
         lastCowPosition = stalls[stall_position]; // update the position of the last placed cow to the current stall and continue
      }
   }
   return false; // if we exit the loop without placing all cows, return false
}

int aggressiveCows(vector<int> &stalls, int total_cows)
{
   sort(stalls.begin(), stalls.end()); // sort the stalls to apply binary search
   int start = 0;                      // minimum possible distance

   int maxi = -1; // to find the maximum stall position
   for (int stall_position = 0; stall_position < stalls.size(); stall_position++)
   {
      maxi = max(maxi, stalls[stall_position]); // find the maximum stall position
   }
   // int end = stalls.back(); // since stalls are sorted
   int end = maxi; // maximum possible distance
   int ans = -1;   // to store the answer
   int mid = start + (end - start) / 2;

   while (start <= end)
   {
      if (isPossible(stalls, total_cows, mid))
      {
         ans = mid;
         start = mid + 1; // try for a better (larger) solution on the right side
      }
      else
      {
         end = mid - 1; // try for a smaller solution on the left side
      }
      mid = start + (end - start) / 2; // recalculate mid
   }
   return ans; // return the maximum possible minimum distance
}

int main()
{
   vector<int> stalls = {0, 3, 4, 7, 10, 9};
   int cows = 4;

   int result = aggressiveCows(stalls, cows);

   cout << "Maximum possible minimum distance is " << result << "; between " << cows << " cows!" << endl;

   return 0;
}