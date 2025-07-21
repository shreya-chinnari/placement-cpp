// how many times a number occurs in an array

#include <iostream>
using namespace std;

int main()
{

   // Input Array: -------------------------------------------------
   int n;
   cout << "length of array: ";
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   // Hashing to Count Frequencies | pre-compute {store}: -----------

   // The array hash is initialized to zero.It's used to store the frequency of each number in the input array. The size of hash is 13 because, as per the comment, the numbers in the input array can range from 0 to 12.
   // hash[arr[i]]++ increments the count of arr[i] in the hash array. For example, if arr[i] is 5, hash[5] will be incremented.

   int hash[13] = {0}; // given : array can have max size = 12 {so, 12+1 because 0 to 12}
   for (int i = 0; i < n; i++)
   {
      hash[arr[i]]++; // hash array is ready with 0 to 12 values
   }

   // Querying: ------------------------------------------------------

   // After building the hash array, the program prompts the user to enter the number of queries (q). Each query asks for the frequency of a specific number in the array.

   int q;
   cin >> q;
   while (q--)
   {
      int number;
      cin >> number;

      // {fetch}
      cout << hash[number] << endl;
   }

   return 0;
}