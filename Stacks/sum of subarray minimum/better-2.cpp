// GOOD FOR COMPETITIVE PROGRAMMING

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Previous Smaller Element (strictly smaller)
vector<int> PSE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> left(n);
   stack<int> st;

   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] > arr[i])
         st.pop();
      left[i] = st.empty() ? (i + 1) : (i - st.top());
      st.push(i);
   }
   return left;
}
// Next Smaller Element (smaller or equal)
vector<int> NSE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> right(n);
   stack<int> st;

   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      right[i] = st.empty() ? (n - i) : (st.top() - i);
      st.push(i);
   }
   return right;
}
int sumSubarrayMins(vector<int> &arr)
{
   int n = arr.size();

   // get distances to previous/next smaller elements
   vector<int> left = PSE(arr);
   vector<int> right = NSE(arr);

   long long total = 0;
   for (int i = 0; i < n; i++)
   {
      long long contribution = (1LL * arr[i] * left[i] % MOD) * right[i] % MOD;
      total = (total + contribution) % MOD;
   }
   return (int)total;
}

int main()
{
   vector<int> arr = {3, 1, 2, 4};
   cout << sumSubarrayMins(arr) << endl; // Expected: 17
   return 0;
}
