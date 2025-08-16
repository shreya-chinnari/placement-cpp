// GOOD FOR INTERVIEW

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Previous Smaller (break ties to LEFT)
vector<int> PSEE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> psee(n, -1); // default -1 if no smaller element
   stack<int> st;
   // start looking from front
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] > arr[i])
      { // pop all elements SMALLER THAN arr[i]
         // because we are looking for [smaller and equal] elements
         st.pop();
      }
      if (!st.empty())
         pse[i] = st.top();
      // pse[i] = st.empty() ? -1 : st.top();
      st.push(i);
   }
   return psee;
}

// Next Smaller (break ties to RIGHT)
vector<int> NSE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> nse(n, n); // default n if no smaller element
   stack<int> st;
   // start looking from back
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
      { // pop all elements GREATER THAN or EQUAL TO arr[i]
         // because we are looking for only [smaller] elements
         st.pop();
      }
      if (!st.empty())
         nse[i] = st.top();
      // nse[i] = st.empty() ? n : st.top();
      st.push(i);
   }
   return nse;
}

// int sumSubarrayMins(vector<int> &arr)
// {
//    int n = arr.size();
//    vector<int> pse = PSEE(arr);
//    vector<int> nse = NSE(arr);

//    long long total = 0;

//    for (int i = 0; i < n; i++)
//    {
//       long long left = i - pse[i];  // distance to previous smaller
//       long long right = nse[i] - i; // distance to next smaller

//       total = (total + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
//    }

//    return (int)total;
// }

int main()
{
   vector<int> arr = {3, 1, 2, 4};
   cout << sumSubarrayMins(arr) << endl; // Expected: 17
   return 0;
}
