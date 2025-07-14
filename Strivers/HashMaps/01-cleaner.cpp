// how many times a number occurs in an array

#include <iostream>
using namespace std;

int main()
{
   // 1 : Build the array

   int n;
   cout << "Enter array length: ";
   cin >> n;

   int arr[n];
   cout << "Enter " << n << " elements: ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   // 2 : Build the hash-array

   int hash[13] = {0}; // all 0s initially
   cout << "\nBuilding frequency table...\n";
   for (int i = 0; i < n; i++) // range: 0 to 12
   {
      hash[arr[i]]++;
      cout << "Count of " << arr[i] << " now: " << hash[arr[i]] << endl;
   }

   // 3 : Queries

   int q;
   cout << "\nEnter number of queries: ";
   cin >> q;
   cout << "Enter query numbers:\n";
   while (q--)
   {
      int number; // number to be searched
      cin >> number;
      cout << "Frequency of " << number << ": " << hash[number] << endl;
   }

   return 0;
}
