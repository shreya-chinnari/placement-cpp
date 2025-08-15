#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> arr)
{
   int n = arr.size();

   stack<int> st;
   vector<int> nge(n, -1);

   for (int i = n - 1; i >= 0; i--)
   {
      // If stack is not empty,
      // pop elements smaller than arr[i]
      // until we find a greater element
      while (!st.empty() && st.top() <= arr[i])
      {
         st.pop();
      }

      // If stack empty,
      if (st.empty())
         nge[i] = -1; // No greater element found
      // If stack is not empty,
      else
         nge[i] = st.top(); // Top of stack is the next greater element

      // Push the current element onto the stack
      // for the next iteration for the next elements
      st.push(arr[i]);
   }
   return nge;
}

int main()
{
   vector<int> arr = {4, 5, 2, 10, 8};
   vector<int> result = NGE(arr);

   cout << "Next Greater Element for each element: ";
   for (int i = 0; i < result.size(); i++)
   {
      cout << result[i] << " ";
   }

   return 0;
}