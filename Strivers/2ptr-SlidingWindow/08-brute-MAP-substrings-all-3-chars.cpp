#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int countSubstrings_map(string s)
{
   int n = s.length(), count = 0;

   for (int i = 0; i < n; i++)
   {
      unordered_map<char, int> freq;

      for (int j = i; j < n; j++)
      {
         freq[s[j]]++;

         if (freq['a'] && freq['b'] && freq['c'])
         {
            count++;
         }
      }
   }
   return count;
}

int main()
{
   string s = "bbacba";
   cout << "Total substrings with all 3 characters: " << countSubstrings_map(s) << endl;
   return 0;
}
