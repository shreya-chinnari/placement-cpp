#include <bits/stdc++.h>
using namespace std;

// Function to find Next Greater Element for each element
vector<int> NGE(vector<int> arr)
{
   int n = arr.size();

   stack<int> st;
   vector<int> nge(n, -1);

   for (int i = n - 1; i >= 0; i--)
   {
      // If stack is not empty,
      // pop elements <= arr[i]
      // until we find a greater element
      while (!st.empty() && st.top() <= arr[i])
      {
         st.pop();
      }

      // If stack is not empty
      if (!st.empty())
         nge[i] = st.top(); // Top of stack is the next greater element
      // If stack is empty : no greater element found (nge[i] = -1 as it was)

      // Push current element for next iterations
      st.push(arr[i]);
   }
   return nge;
}

// Function to find Previous Greater Element for each element
vector<int> PGE(vector<int> arr)
{
   int n = arr.size();

   stack<int> st;
   vector<int> pge(n, -1);

   for (int i = 0; i < n; i++)
   {
      // If stack is not empty,
      // pop elements smaller or equal to arr[i]
      while (!st.empty() && st.top() <= arr[i])
      {
         st.pop();
      }

      // If stack not empty, top is previous greater element
      if (!st.empty())
         pge[i] = st.top();

      // Push current element for next iterations
      st.push(arr[i]);
   }
   return pge;
}

// Function to find Next Smaller Element for each element
vector<int> NSE(vector<int> arr)
{
   int n = arr.size();

   stack<int> st;
   vector<int> nse(n, -1);

   for (int i = n - 1; i >= 0; i--)
   {
      // If stack is not empty,
      // pop elements greater or equal to arr[i]
      while (!st.empty() && st.top() >= arr[i])
      {
         st.pop();
      }

      // If stack not empty, top is next smaller element
      if (!st.empty())
         nse[i] = st.top();

      // Push current element for next iterations
      st.push(arr[i]);
   }
   return nse;
}

// Function to find Previous Smaller Element for each element
vector<int> PSE(vector<int> arr)
{
   int n = arr.size();

   stack<int> st;
   vector<int> pse(n, -1);

   for (int i = 0; i < n; i++)
   {
      // If stack is not empty,
      // pop elements greater or equal to arr[i]
      while (!st.empty() && st.top() >= arr[i])
      {
         st.pop();
      }

      // If stack not empty, top is previous smaller element
      if (!st.empty())
         pse[i] = st.top();

      // Push current element for next iterations
      st.push(arr[i]);
   }
   return pse;
}

int main()
{
   vector<int> arr = {4, 5, 2, 10, 8};

   vector<int> nge = NGE(arr);
   vector<int> pge = PGE(arr);
   vector<int> nse = NSE(arr);
   vector<int> pse = PSE(arr);

   cout << "Array: ";
   for (int x : arr)
      cout << x << " ";
   cout << "\n";

   cout << "Next Greater Element: ";
   for (int x : nge)
      cout << x << " ";
   cout << "\n";

   cout << "Previous Greater Element: ";
   for (int x : pge)
      cout << x << " ";
   cout << "\n";

   cout << "Next Smaller Element: ";
   for (int x : nse)
      cout << x << " ";
   cout << "\n";

   cout << "Previous Smaller Element: ";
   for (int x : pse)
      cout << x << " ";
   cout << "\n";

   return 0;
}