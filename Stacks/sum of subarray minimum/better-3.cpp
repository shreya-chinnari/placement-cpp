#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
   int n = arr.size();
   const int MOD = 1e9 + 7;

   vector<int> left(n), right(n);
   stack<int> st;

   // 1) Previous Smaller Element (strictly smaller to the left)
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] > arr[i])
         st.pop();
      left[i] = st.empty() ? (i + 1) : (i - st.top());
      st.push(i);
   }

   // clear stack for reuse
   while (!st.empty())
      st.pop();

   // 2) Next Smaller Element (smaller OR equal to the right)
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      right[i] = st.empty() ? (n - i) : (st.top() - i);
      st.push(i);
   }

   // 3) Compute result
   long long result = 0;
   for (int i = 0; i < n; i++)
   {
      long long contrib = (1LL * arr[i] * left[i] % MOD) * right[i] % MOD;
      result = (result + contrib) % MOD;
   }

   return (int)result;
}

int main()
{
   vector<int> arr = {3, 1, 2, 4};
   cout << sumSubarrayMins(arr) << endl; // Expected: 17
   return 0;
}
