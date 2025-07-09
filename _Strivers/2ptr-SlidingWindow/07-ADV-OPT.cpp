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

   while (r < n)
   {
      charCount[s[r]]++;

      // while (charCount.size() > k)

      // instead of removing all elements from Left, remove 1, then check, update, repeat
      if (charCount.size() > k)
      {
         charCount[s[l]]--;
         if (charCount[s[l]] == 0)
         {
            charCount.erase(s[l]);
         }
         l++;
      }
      maxLen = max(maxLen, r - l + 1);
      r++;
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
