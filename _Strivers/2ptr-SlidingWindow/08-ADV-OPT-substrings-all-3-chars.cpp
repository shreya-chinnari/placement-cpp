// TOTAL Number of Substrings containing all 3 characters

// TC : O(n) -  We loop once and use constant-time min operation.
// SC : O(1) - Only 3 integer variables used (lastSeen[3]).

// generate substrings, but in a smarter way {right to left}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countSubstring(string s)
{
   int lastSeen[3] = {-1, -1, -1}; // last seen index of 'a', 'b', 'c'
   int n = s.size();
   int count = 0;

   for (int i = 0; i < n; i++)
   {
      lastSeen[s[i] - 'a'] = i; // update last seen index

      if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
      {
         count = count + 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
      }
   }
   return count;
}

int main()
{
   string s = "bbacba";
   cout << "Total substrings with all 3 characters: "
        << countSubstring(s) << endl;
   return 0;
}