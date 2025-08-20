#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &hist)
{
   int n = hist.size();
   stack<int> st;
   int maxArea = 0;

   // Step 1: Iterate through histogram
   for (int i = 0; i <= n; i++)
   {
      // Current height (0 when i==n to flush out stack)
      int el = (i == n) ? 0 : hist[i];

      // Maintain increasing order in stack
      while (!st.empty() && hist[st.top()] > el)
      {
         int element = st.top();
         st.pop();

         int nse = i;                          // next smaller element index
         int pse = st.empty() ? -1 : st.top(); // prev smaller element index

         // width = nse - pse - 1
         int width = nse - pse - 1;
         int area = hist[element] * width;

         maxArea = max(maxArea, area);
      }
      st.push(i);
   }

   // Step 2: Post-processing (flush remaining stack)
   while (!st.empty())
   {
      int el = st.top();
      st.pop();

      int nse = n; // now NSE is n since array ended
      int pse = st.empty() ? -1 : st.top();

      maxArea = max(maxArea, hist[el] * (nse - pse - 1));
   }
   return maxArea;
}

// TC : O(n) - push, O(n) - pop
// SC : O(n) - stack

int main()
{
   vector<int> arr = {2, 1, 5, 6, 2, 3};
   cout << "Largest Rectangle Area = " << largestRectangleArea(arr) << endl;
   return 0;
}
