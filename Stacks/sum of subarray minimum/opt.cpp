#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute the sum of subarray minimums
int sumSubarrayMins(vector<int> &arr)
{
   int n = arr.size();

   // left[i]  = number of consecutive elements to the LEFT (including arr[i])
   //            where arr[i] is the minimum
   // right[i] = number of consecutive elements to the RIGHT (including arr[i])
   //            where arr[i] is the minimum
   //
   // So contribution of arr[i] = arr[i] * left[i] * right[i]
   // Example: arr = [3,1,2,4], arr[1]=1 covers left=2, right=3 → contributes 6 subarrays

   vector<int> left(n), right(n);
   stack<int> st; // monotonic stack (stores indices)

   // ------------------------------
   // Pass 1: Find distance to previous smaller-or-equal element for each index
   // ------------------------------
   for (int i = 0; i < n; i++)
   {
      // Pop until we find an element <= arr[i]
      // Why ">" and not ">="?
      //   Because equal elements should be tied consistently (we let RIGHT side break ties)
      while (!st.empty() && arr[st.top()] > arr[i])
         st.pop();

      // If stack empty → no smaller element on left → all (i+1) choices are valid
      // Else → distance is (i - st.top())
      left[i] = st.empty() ? i + 1 : i - st.top();

      st.push(i);
   }

   // Clear stack for reuse
   while (!st.empty())
      st.pop();

   // ------------------------------
   // Pass 2: Find distance to next smaller element for each index
   // ------------------------------
   for (int i = n - 1; i >= 0; i--)
   {
      // Pop until we find a strictly smaller element
      // Why ">=" this time?
      //   Because we already handled equality on the LEFT side.
      //   This ensures no double counting.
      while (!st.empty() && arr[st.top()] >= arr[i])
         st.pop();

      // If stack empty → no smaller element on right → (n-i) choices are valid
      // Else → distance is (st.top() - i)
      right[i] = st.empty() ? n - i : st.top() - i;

      st.push(i);
   }

   // ------------------------------
   // Contribution: arr[i] * left[i] * right[i]
   // ------------------------------
   long long total = 0;
   for (int i = 0; i < n; i++)
   {
      total = (total + 1LL * arr[i] * left[i] % MOD * right[i] % MOD) % MOD;
   }

   return total;
}

int main()
{
   vector<int> arr = {3, 1, 2, 4};
   cout << sumSubarrayMins(arr) << endl; // Expected output: 17
   return 0;
}
