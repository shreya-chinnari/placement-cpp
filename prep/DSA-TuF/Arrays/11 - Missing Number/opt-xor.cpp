#include <bits/stdc++.h>
using namespace std;

// using XOR
// a^a = 0, a^0 = a

// we XOR all the numbers from 1 to N = xor1
// we XOR all the elements in the array = xor2
// the missing number is xor1 ^ xor2

/*

TC - O(2n) because of 2 loops

-----------------------------------------------
int missingNumber(vector<int> &a, int N)
{
   int XOR1 = 0;
   int XOR2 = 0;

   for (int i = 0; i < N - 1; i++)
   {
      XOR2 = XOR2 ^ a[i];
   }
   for (int i = 1; i < N ; i++)
   {
      XOR1 = XOR1 ^ (i);
   }

   return XOR1 ^ XOR2;
}
*/
int missingNumber(vector<int> &a, int N)
{
   int XOR1 = 0; // XOR of all numbers from 1 to N
   int XOR2 = 0; // XOR of all elements in the array

   for (int i = 0; i < N - 1; i++)
   {
      XOR1 = XOR1 ^ (i + 1); // XOR from 1 to N-1
      XOR2 = XOR2 ^ a[i];    // XOR of all elements in the array
   }
   XOR1 = XOR1 ^ N; // Include the last number N

   return XOR1 ^ XOR2; // The missing number is the XOR of both results
   // This works because the missing number will be the only one that does not cancel out.
}

int main()
{
   int N = 5;
   vector<int> a = {1, 2, 4, 5};
   int ans = missingNumber(a, N);
   cout << "The missing number is: " << ans << endl;
   return 0;
}
