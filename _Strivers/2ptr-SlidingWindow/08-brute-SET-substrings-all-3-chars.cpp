// TOTAL Number of Substrings containing all 3 characters

// TC :
// SC :

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int countSubstrings_set(string s)
{
   int n = s.length(), count = 0;

   for (int i = 0; i < n; i++)
   {
      unordered_set<char> st;

      for (int j = i; j < n; j++)
      {
         st.insert(s[j]);

         if (st.size() == 3)
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
   cout << "Total substrings with all 3 characters: " << countSubstrings_set(s) << endl;
   return 0;
}
