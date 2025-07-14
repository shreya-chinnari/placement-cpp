// longest substring with K distinct chars
// use [unordered_map] to store frequency

// TC : O(n) + O(n) + O(1)

// SC : O(k)
// Structure	       → Space
// unordered_map O(k) → At most k distinct characters tracked

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringK(string s, int k)
{
   int maxLen = 0;
   int n = s.size();

   int l = 0, r = 0;

   unordered_map<char, int> charCount;

   while (r < n) // o(n)
   {
      // put the character into map
      // Expand the window by adding s[r]
      charCount[s[r]]++; // O(1)

      // valid or invalid

      // Shrink the window from the left if more than k distinct characters
      while (charCount.size() > k) // o(n)
      {
         charCount[s[l]]--; // o(1)
         if (charCount[s[l]] == 0)
         {
            charCount.erase(s[l]); // O(1)
         }
         l++; // Shrink from Left
      }

      // Valid window with ≤ k distinct characters
      maxLen = max(maxLen, r - l + 1);
      r++; // Expand the window
   }

   return maxLen;
}

int main()
{
   string s = "aaabbbopopopobpop";
   int k = 2;

   cout << "Longest substring with " << k << " distinct characters: "
        << longestSubstringK(s, k) << endl;

   return 0;
}
