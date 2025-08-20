#include <bits/stdc++.h>
using namespace std;

// Brute Force: Next Greater Element
vector<int> NGE(vector<int> arr)
{
   int n = arr.size();
   vector<int> nge(n, -1); // Initialize with -1

   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] > arr[i])
         {
            nge[i] = arr[j]; // Found the next greater element
            break;           // Stop searching further
         }
      }
   }
   return nge;
}

// Brute Force: Previous Greater Element
vector<int> PGE(vector<int> arr)
{
   int n = arr.size();
   vector<int> pge(n, -1);

   for (int i = 0; i < n; i++)
   {
      for (int j = i - 1; j >= 0; j--)
      {
         if (arr[j] > arr[i])
         {
            pge[i] = arr[j]; // Found previous greater element
            break;           // Stop searching further
         }
      }
   }
   return pge;
}

// Brute Force: Next Smaller Element
vector<int> NSE(vector<int> arr)
{
   int n = arr.size();
   vector<int> nse(n, -1);

   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[i])
         {
            nse[i] = arr[j]; // Found next smaller element
            break;
         }
      }
   }
   return nse;
}

// Brute Force: Previous Smaller Element
vector<int> PSE(vector<int> arr)
{
   int n = arr.size();
   vector<int> pse(n, -1);

   for (int i = 0; i < n; i++)
   {
      for (int j = i - 1; j >= 0; j--)
      {
         if (arr[j] < arr[i])
         {
            pse[i] = arr[j]; // Found previous smaller element
            break;
         }
      }
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
