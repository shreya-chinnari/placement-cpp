// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// TC: O(2N)
// SC: O(26)

/*
Maintain a window [l, r] such that:
We keep track of the most frequent character in the window.
If (window size - maxFreq) > k, it means we need to change more than k characters, so shrink the window by moving the left pointer.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k)
{

   int maxLen = 0, maxFreq = 0;
   int l = 0, r = 0;
   int n = s.size();

   int hash[26] = {0};
   while (r < n)
   {
      hash[s[r] - 'A']++;                       // Add character at 'r' to the window
      maxFreq = max(maxFreq, hash[s[r] - 'A']); // Update max frequency in the window

      // If changes needed > k, shrink window
      while ((r - l + 1) - maxFreq > k)
      {
         hash[s[l] - 'A']--; // Remove char at left

         maxFreq = 0;
         for (int i = 0; i < n; i++)
         {
            maxFreq = max(maxFreq, hash[i]);
         }
         l++; // Shrink window
      }

      // Update maxLen (window is always valid after shrinking)
      maxLen = max(maxLen, r - l + 1);

      r++; // Expand window
   }

   return maxLen;
}

int main()
{
   string s = "AABABBA";
   int k = 1;
   cout << "Longest valid substring length: " << characterReplacement(s, k) << endl;
   return 0;
}