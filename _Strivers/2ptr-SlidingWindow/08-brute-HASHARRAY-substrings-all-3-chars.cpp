// TOTAL Number of Substrings containing all 3 characters

// TC : O(n^2)
// SC : O(1)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countSubstringsWithAll3(string s)
{
   int count = 0;
   int n = s.size();

   for (int i = 0; i < n; i++)
   {
      int hash[3] = {0}; // 0 for 'a', 1 for 'b', 2 for 'c'

      for (int j = i; j < n; j++)
      {
         hash[s[j] - 'a'] = 1; // Mark character as seen

         if (hash[0] + hash[1] + hash[2] == 3)
         {
            count++; // All three characters seen
         }
      }
   }

   return count;
}

int main()
{
   string s = "bbacba";
   cout << "Total substrings with all 3 characters: " << countSubstringsWithAll3(s) << endl;
   return 0;
}
