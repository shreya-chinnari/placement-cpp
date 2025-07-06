// How many times a number occurs in an array

#include <iostream>
using namespace std;

int main()
{
   // 1 : Build the array
   int n;
   cout << "Enter array length: ";
   cin >> n;

   int *arr = new int[n];
   cout << "Enter " << n << " elements: ";
   int max_val = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
      if (arr[i] > max_val)
         max_val = arr[i]; // to determine hash size dynamically
   }

   // 2 : Build the hash-array
   int *hash = new int[max_val + 1](); // all 0s initially using value-initialization
   cout << "\nBuilding frequency table...\n";
   for (int i = 0; i < n; i++)
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
      int number;
      cin >> number;

      if (number > max_val || number < 0)
         cout << "Frequency of " << number << ": 0 (out of bounds)\n";
      else
         cout << "Frequency of " << number << ": " << hash[number] << endl;
   }

   // 4 : Cleanup
   delete[] arr;
   delete[] hash;

   return 0;
}
