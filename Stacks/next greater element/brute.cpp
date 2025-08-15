#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> arr)
{
   int n = arr.size();

   vector<int> nge(n, -1); // Vector of size n, Initialize with -1

   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] > arr[i])
         {
            nge[i] = arr[j]; // Found the next greater element
            break;           // No need to check further, we found the next greater element
         }
      }
   }

   return nge; // Return the vector containing next greater elements
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