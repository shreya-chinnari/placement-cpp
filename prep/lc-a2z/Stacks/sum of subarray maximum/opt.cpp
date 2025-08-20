#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute the sum of subarray maximums
int sumSubarrayMaxs(vector<int> &arr)
{
   int n = arr.size();
   vector<int> left(n), right(n);
   stack<int> st;

   // ------------------------------
   // Pass 1: Find distance to previous greater-or-equal element
   // ------------------------------
   for (int i = 0; i < n; i++)
   {
      // Pop until we find an element >= arr[i]
      while (!st.empty() && arr[st.top()] < arr[i])
         st.pop();

      left[i] = st.empty() ? i + 1 : i - st.top();
      st.push(i);
   }

   // Clear stack for reuse
   while (!st.empty())
      st.pop();

   // ------------------------------
   // Pass 2: Find distance to next greater element
   // ------------------------------
   for (int i = n - 1; i >= 0; i--)
   {
      // Pop until we find a strictly greater element
      while (!st.empty() && arr[st.top()] <= arr[i])
         st.pop();

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
   cout << sumSubarrayMaxs(arr) << endl; // Expected output: 30
   return 0;
}
