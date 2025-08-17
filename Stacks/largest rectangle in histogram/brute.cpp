#include <bits/stdc++.h>
using namespace std;

// ---------- Previous Smaller Element ----------
vector<int> prevSmaller(vector<int> &arr)
{
   int n = arr.size();
   vector<int> pse(n, -1); // default = -1
   stack<int> st;
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      if (!st.empty())
         pse[i] = st.top();
      st.push(i);
   }
   return pse;
}

// ---------- Next Smaller Element ----------
vector<int> nextSmaller(vector<int> &arr)
{
   int n = arr.size();
   vector<int> nse(n, n); // default = n
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

// ---------- Largest Rectangle in Histogram ----------
int largestRectangleArea(vector<int> &arr)
{
   int n = arr.size();
   vector<int> pse = prevSmaller(arr); // TC : O(2n) , SC : O(2n)
   vector<int> nse = nextSmaller(arr); // TC : O(2n) , SC : O(2n)

   int maxArea = 0;
   for (int i = 0; i < n; i++) // TC : O(n)
   {
      int width = nse[i] - pse[i] - 1;
      int area = arr[i] * width;
      maxArea = max(maxArea, area);
   }
   return maxArea;
}

// ---------- Main ----------
int main()
{
   vector<int> heights = {2, 1, 5, 6, 2, 3};
   cout << largestRectangleArea(heights) << endl;
   // Expected output = 10 (rectangle formed by heights[2]=5 and heights[3]=6)
   return 0;
}
