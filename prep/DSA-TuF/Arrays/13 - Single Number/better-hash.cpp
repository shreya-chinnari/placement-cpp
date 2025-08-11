// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

#include <bits/stdc++.h>
using namespace std;

// using HASHING + ARRAYS

// 1. find maxElement in the array
// 2. create a hash array of size (maxElement + 1) initialized to 0.
// 3. hash the array, incrementing the count of each element in the hash array
// 4. find the element in the hash array that has a count of 1
// 5. return that element

int SingleElement(vector<int> &arr)
{
   int n = arr.size();

   // 1. find maxElement in the array
   int maxi = arr[0];
   for (int i = 0; i < n; i++)
   {
      maxi = max(maxi, arr[i]);
   }

   // 2. create a hash array of size (maxElement + 1) initialized to 0.
   vector<int> hash(maxi + 1, 0);

   // 3. hash the array, incrementing the count of each element in the hash array
   for (int i = 0; i < n; i++)
   {
      hash[arr[i]]++;
   }

   // 4. find the element in the hash array that has a count of 1
   for (int i = 0; i < n; i++)
   {
      // for(int i=0 ; i<=maxi ; i++)

      if (hash[arr[i]] == 1)
      {
         return arr[i];
      }
   }

   return -1;
}

// Time complexity for the final for loop :

int main()
{

   vector<int> arr = {4, 1, 2, 1, 2};
   int ans = SingleElement(arr);
   cout << "The single element is: " << ans << endl;
   return 0;
}