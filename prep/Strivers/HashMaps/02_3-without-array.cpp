// Count frequencies of characters in a STRING of ONLY LOWER CASES
#include <iostream>
using namespace std;

int main()
{
   // Input string
   string s;
   cout << "Enter string : ";
   cin >> s;

   // Build the hash-array for lowercase characters
   int hash[26] = {0}; // only 26 needed for lowercase letters

   cout << "\nHashmap ----------" << endl;
   for (char ch : s)
   {
      if (ch >= 'a' && ch <= 'z')
      {
         hash[ch - 'a']++;
         cout << "char : " << ch << "   freq : " << hash[ch - 'a'] << endl;
      }
   }

   // Query
   int q;
   cout << "\nNumber of queries: ";
   cin >> q;

   cout << "\nEnter char to query:\n";
   while (q--)
   {
      char ch;
      cin >> ch;
      cout << "frequency of " << ch << " : " << hash[ch - 'a'] << endl;
   }

   return 0;
}
