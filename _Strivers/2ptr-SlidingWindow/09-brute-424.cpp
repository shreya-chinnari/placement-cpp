// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// TC: O(n²) ✔ The hash[26] access and maxFreq update are done in constant time.
// SC: O(1) ) (constant space for 26 uppercase characters)

/*
-  -  Count frequency of each character in the substring.
-  -  Find the most frequent character in it.
-  -  Calculate how many changes are needed:
   changesNeeded = (j - i + 1) - maxFreq
-  -  If changesNeeded <= k, it's a valid substring.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k)
{

   int maxLen = 0;
   int n = s.size();

   for (int i = 0; i < n; i++)
   {
      int hash[26] = {0}; // Hash to count frequency of each uppercase character
      int maxFreq = 0;    // Track the most frequent character in current substring

      for (int j = i; j < n; j++)
      {
         hash[s[j] - 'A']++;                       // Increment frequency of current char
         maxFreq = max(maxFreq, hash[s[j] - 'A']); // Update max frequency in window

         int windowLen = j - i + 1; // Total characters in current substring
         int changesNeeded = windowLen - maxFreq;

         // If number of characters to change ≤ k, it's a valid window
         if (changesNeeded <= k)
         {
            maxLen = max(maxLen, windowLen); // Update result if valid
         }
         else
            break;
      }
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