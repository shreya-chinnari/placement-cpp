// Longest substring without repeating characters

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ✅ Function 1: Return max length
int maxLength(string s)
{
   int maxLen = 0, len = 0;
   int size = s.length();

   for (int i = 0; i < size; i++)
   {
      int arr[256] = {0}; // Reset character arr

      for (int j = i; j < size; j++)
      {
         // if the character has been recorded earlier, it's count is already 1, so don't include it
         if (arr[s[j]] == 1)
            break;
         // if the character hasn't been recorded earlier :
         arr[s[j]] = 1;
         len = j - i + 1;
         maxLen = max(len, maxLen);
      }
   }
   return maxLen;
}

// ✅ Function 2: Return start and end index of longest unique substring
pair<int, int> maxLengthIndex(string s)
{
   int maxLen = 0, size = s.length();
   int start = 0, end = 0;

   for (int i = 0; i < size; i++)
   {
      int arr[256] = {0};
      for (int j = i; j < size; j++)
      {
         if (arr[s[j]] == 1)
            break;

         arr[s[j]] = 1;
         if (j - i + 1 > maxLen)
         {
            maxLen = j - i + 1;
            start = i;
            end = j;
         }
      }
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