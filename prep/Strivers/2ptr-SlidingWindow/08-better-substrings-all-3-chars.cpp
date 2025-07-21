// TOTAL Number of Substrings containing all 3 characters

// TC : O(n^2) {worst}
// TC : O(n^2) {best}
// SC : O(1)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countSubstrings_little_opt_hash(string s)
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
            // count++; // All three characters seen
            count = count + (n - j);
            break; // stop traversing further, go to next "i"
         }
      }
   }

   return count;
}

int main()
{
   string s = "bbacba";
   cout << "Total substrings with all 3 characters: " << countSubstrings_little_opt_hash(s) << endl;
   return 0;
}
