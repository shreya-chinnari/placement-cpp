// longest substring with K distinct chars
// use [unordered_map] to store frequency

// TC : O(n^2) x O(log(256))
// TC : O(256)

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringK(string s, int k)
{
   int maxLen = 0;
   int n = s.size();

   for (int i = 0; i < n; i++) // o(n)
   {
      unordered_map<char, int> charCount;
      charCount.clear();

      for (int j = i; j < n; j++) // o(n)
      {
         charCount[s[j]]++; // o(256)

         if (charCount.size() > k)
            break;

         if (charCount.size() <= k)
         {
            maxLen = max(maxLen, j - i + 1);
         }
      }
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
