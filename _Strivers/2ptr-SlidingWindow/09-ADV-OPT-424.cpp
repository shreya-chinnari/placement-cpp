// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// TC:
// SC:

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
      hash[s[r] - 'A']++;
      maxFreq = max(maxFreq, hash[s[r] - 'A']);

      // while ((r - l + 1) - maxFreq > k)
      if ((r - l + 1) - maxFreq > k)
      {
         hash[s[l] - 'A']--;

         // maxFreq = 0;
         // for (int i = 0; i < n; i++)
         // {
         //    maxFreq = max(maxFreq, hash[i]);
         // }
         l++;
      }

      maxLen = max(maxLen, r - l + 1);

      r++;
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