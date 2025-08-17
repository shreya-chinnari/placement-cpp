// GOOD FOR INTERVIEW

#include <bits/stdc++.h>
using namespace std;

// ---------- Helpers for Smaller ----------

// Previous Smaller (strictly smaller, break ties to LEFT)
vector<int> PSEE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> pse(n, -1);
   stack<int> st;
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] > arr[i])
         st.pop();
      if (!st.empty())
         pse[i] = st.top();
      st.push(i);
   }
   return pse;
}

// Next Smaller (strictly smaller, break ties to RIGHT)
vector<int> NSE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> nse(n, n);
   stack<int> st;
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      if (!st.empty())
         nse[i] = st.top();
      st.push(i);
   }
   return nse;
}

// ---------- Helpers for Greater ----------

// Previous Greater (strictly greater, break ties to LEFT)
vector<int> PGEE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> pge(n, -1);
   stack<int> st;
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] < arr[i])
         st.pop();
      if (!st.empty())
         pge[i] = st.top();
      st.push(i);
   }
   return pge;
}

// Next Greater (strictly greater, break ties to RIGHT)
vector<int> NGE(vector<int> &arr)
{
   int n = arr.size();
   vector<int> nge(n, n);
   stack<int> st;
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] <= arr[i])
         st.pop();
      if (!st.empty())
         nge[i] = st.top();
      st.push(i);
   }
   return nge;
}

// ---------- Core function ----------

// Sum of subarray ranges = sum of contributions as max - as min
long long subArrayRanges(vector<int> &arr)
{
   int n = arr.size();

   // Get previous/next smaller
   vector<int> pse = PSEE(arr);
   vector<int> nse = NSE(arr);

   // Get previous/next greater
   vector<int> pge = PGEE(arr);
   vector<int> nge = NGE(arr);

   long long totalMax = 0, totalMin = 0;

   for (int i = 0; i < n; i++)
   {
      long long leftMin = i - pse[i];
      long long rightMin = nse[i] - i;
      totalMin += 1LL * arr[i] * leftMin * rightMin;

      long long leftMax = i - pge[i];
      long long rightMax = nge[i] - i;
      totalMax += 1LL * arr[i] * leftMax * rightMax;
   }

   return totalMax - totalMin;
}

// ---------- Main ----------
int main()
{
   vector<int> arr = {3, 1, 2, 4};
   cout << subArrayRanges(arr) << endl; // Expected: 13
   return 0;
}
