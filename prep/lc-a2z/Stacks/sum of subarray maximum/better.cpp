#include <bits/stdc++.h>
using namespace std;

// --- O(1) space ---
const int MOD = 1e9 + 7;

// Previous Greater (break ties to LEFT)
// Time: ~ (n pushes + n pops + n comparisons) → ~3n
// Space: pge[n] + stack[n] → 2n
vector<int> PGE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> pge(n, -1); // default -1 if no greater element
   stack<int> st;

   for (int i = 0; i < n; i++)
   {
      // pop all elements smaller than arr[i]
      while (!st.empty() && arr[st.top()] < arr[i])
      {
         st.pop();
      }
      if (!st.empty())
         pge[i] = st.top();
      st.push(i);
   }
   return pge;
}

// Next Greater (break ties to RIGHT)
// Time: ~ (n pushes + n pops + n comparisons) → ~3n
// Space: nge[n] + stack[n] → 2n
vector<int> NGE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> nge(n, n); // default n if no greater element
   stack<int> st;

   for (int i = n - 1; i >= 0; i--)
   {
      // pop all elements smaller or equal to arr[i]
      while (!st.empty() && arr[st.top()] <= arr[i])
      {
         st.pop();
      }
      if (!st.empty())
         nge[i] = st.top();
      st.push(i);
   }
   return nge;
}

int sumSubarrayMaxs(vector<int> &arr)
{
   int n = arr.size();
   vector<int> pge = PGE(arr);
   vector<int> nge = NGE(arr);

   long long total = 0;

   for (int i = 0; i < n; i++)
   {
      long long left = i - pge[i];  // distance to previous greater,
      long long right = nge[i] - i; // distance to next greater,

      total = (total + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
   }

   return (int)total;
}

// total : TC - O(7n)
// SC - O(4n)
int main()
{
   vector<int> arr = {3, 1, 2, 4};
   cout << sumSubarrayMaxs(arr) << endl; // Expected: 30
   return 0;
}
