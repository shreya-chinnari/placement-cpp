// count frequencies of charcaters in a STRING of ONLY LOWER CASES

#include <iostream>
using namespace std;

int main()
{

   // Building the character array
   string s;

   cout << "Enter string : ";
   cin >> s;

   // Build the hash-array for charcaters using ASCII
   int hash[26] = {0}; // only 26 needed for lower case letters
   cout << "\n Hashmap ---------- " << endl;
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] >= 'a' && s[i] <= 'z')
         hash[s[i] - 'a']++;

      cout << "char : " << s[i] << "   freq : " << hash[s[i] - 'a'] << endl;
   }

   // Query
   int q;
   cout << "\n Number of queries: " << endl;
   cin >> q;
   cout << "\n Enter char to query : \n";
   while (q--)
   {
      char ch;
      cin >> ch;

      cout << "frequency of " << ch << " :  " << hash[ch - 'a'] << endl;
   }
   return 0;
}