// Longest substring without repeating characters

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TC : O(N) - only moving "r"
// SC : O(256)

// ✅ Function 1: Return max length
int maxLength(string s)
{
   int l = 0, r = 0, maxLen = 0;
   int hashArr[256] = {-1}; // To track last index of each character
   int n = s.length();
   int len;

   while (r < n)
   {
      // If s[r] has been seen before
      if (hashArr[s[r]] != -1)
      {
         // If s[r] has been seen inside current window
         if (hashArr[s[r]] >= l)
         {
            // Move left pointer past the last occurrence
            l = hashArr[s[r]] + 1;
         }
      }
      // Update window length and maxLen
      len = r - l + 1;
      maxLen = max(maxLen, len);

      // Record latest index of character s[r]
      hashArr[s[r]] = r;
      r++;
   }
   return maxLen;
}

// ✅ Function 2: Return start and end index of longest unique substring
pair<int, int> maxLengthIndex(string s)
{

   int start = 0, end = 0;

   int l = 0, r = 0, maxLen = 0;
   int hashArr[256] = {-1};
   int n = s.length();
   int len;

   while (r < n)
   {
      if (hashArr[s[r]] != -1)
      {
         if (hashArr[s[r]] >= l)
         {
            l = hashArr[s[r]] + 1;
         }
      }
      len = r - l + 1;

      // ✅ Update only if new max found
      if (len > maxLen)
      {
         maxLen = len;
         start = l;
         end = r;
      }

      hashArr[s[r]] = r;
      r++;
   }
   return {start, end};
}

// ✅ Function 3: Print the substring with no repeating characters
void maxLengthSubstring(string s)
{
   pair<int, int> idx = maxLengthIndex(s);
   cout << "Longest substring without repeating characters: ";
   for (int i = idx.first; i <= idx.second; i++)
   {
      cout << s[i];
   }
   cout << endl;
}

// ✅ Main
int main()
{
   string s = "djncsdkcnfedfnheadNCWVKCDAWKADXLKA";

   cout << "Max length: " << maxLength(s) << endl;

   pair<int, int> indices = maxLengthIndex(s);
   cout << "Start index: " << indices.first << ", End index: " << indices.second << endl;

   maxLengthSubstring(s);

   return 0;
}