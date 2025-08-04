#include <bits/stdc++.h>
using namespace std;

// using hashmaps

int missingNumber(vector<int> &a, int N)
{
   // 1. create a hash array of size N+1 initialized to 0.
   int hash[N + 1] = {0};

   // 2. iterate through the array and mark the presence of each element in the hash array
   for (int i = 0; i < N - 1; i++)
   {
      hash[a[i]]++;
   }

   // 3. iterate through the hash array { from 1 not 0 } to find the missing number
   for (int i = 1; i <= N; i++)
   {
      if (hash[i] == 0)
      {
         return i; // return the missing number
      }
   }

   // The following line will never execute.
   // It is just to avoid warnings.
   return -1;
}

int main()
{
   int N = 5;
   vector<int> a = {1, 2, 4, 5};
   int ans = missingNumber(a, N);
   cout << "The missing number is: " << ans << endl;
   return 0;
}
