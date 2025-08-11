#include <bits/stdc++.h>
using namespace std;

// using SUMMATION

int missingNumber(vector<int> &a, int N)
{

   int totalSum = (N * (N + 1)) / 2; // Sum of first N natural numbers

   int arraySum = 0; // Sum of elements in the array
   for (int i = 0; i < N; i++)
   {
      arraySum += a[i];
   }

   return totalSum - arraySum; // The missing number is the difference
}

int main()
{
   int N = 5;
   vector<int> a = {1, 2, 4, 5};
   int ans = missingNumber(a, N);
   cout << "The missing number is: " << ans << endl;
   return 0;
}
