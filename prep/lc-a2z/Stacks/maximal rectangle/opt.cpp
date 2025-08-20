#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &hist)
{
   int n = hist.size(); // number of bars in the histogram
   stack<int> st;       // stack of indices, kept in strictly increasing height order
   int maxArea = 0;     // answer we’ll keep updating

   for (int i = 0; i <= n; i++) // note: i goes to n (one extra step)
   {
      int el = (i == n) ? 0 : hist[i]; // sentinel 0 height at i==n to flush remaining bars

      while (!st.empty() && hist[st.top()] > el)
      {
         int element = st.top(); // index of the bar whose area we are fixing now
         st.pop();

         int nse = i;                          // index of next smaller element to the right
         int pse = st.empty() ? -1 : st.top(); // index of previous smaller element to the left

         int width = nse - pse - 1;        // width of the widest rectangle using hist[element] as height
         int area = hist[element] * width; // area for this bar as the limiting height
         maxArea = max(maxArea, area);     // update best
      }
      st.push(i); // push current index (even at i==n; harmless)
   }
   return maxArea; // final answer for this histogram
}

int maximalRectangle(vector<vector<char>> &matrix)
{
   int n = matrix.size(); // number of rows
   if (n == 0)
      return 0;              // empty matrix guard
   int m = matrix[0].size(); // number of columns

   vector<int> heights(m, 0); // histogram heights for the current row
   int maxArea = 0;           // global best across all rows

   for (int i = 0; i < n; i++) // process each row
   {
      for (int j = 0; j < m; j++) // update histogram heights column-wise
      {
         if (matrix[i][j] == '1')
            heights[j] += 1; // extend the vertical streak of ones
         else
            heights[j] = 0; // break streak when we see a '0'
      }
      maxArea = max(maxArea, largestRectangleArea(heights)); // best rectangle using this row as base
   }
   return maxArea; // best over all rows
}

// TC : O(m*n) + O(n*2m)
// O(n*m) + O(n)

int main()
{
   vector<vector<char>> mat = {
       {'1', '0', '1', '0', '0'},
       {'1', '0', '1', '1', '1'},
       {'1', '1', '1', '1', '1'},
       {'1', '0', '0', '1', '0'}};

   cout << "Maximal Rectangle Area = " << maximalRectangle(mat) << endl;
   return 0;
}
