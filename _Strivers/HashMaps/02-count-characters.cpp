#include <iostream>
using namespace std;

int main()
{

   // Building the character array
   int n;
   cout << "Size of characater array : ";
   cin >> n;
   char arr[n];
   cout << "Enter characters : ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   // Build the hash-array for charcaters using ASCII
   int hash[256] = {0}; // ASCII charcater range
   cout << "Hashmap ---------- " << endl;
   for (int i = 0; i < n; i++)
   {
      hash[(int)arr[i]]++;
      cout << "char : " << arr[i] << "   freq : " << hash[(int)arr[i]] << endl;
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
      cout << "frequency of " << ch << " :  " << hash[(int)ch] << endl;
   }
   return 0;
}