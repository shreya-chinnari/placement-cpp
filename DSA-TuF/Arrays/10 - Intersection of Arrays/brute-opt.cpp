#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOf2SortedArrays(int a[], int b[], int n, int m)
{
   vector<int> I;

   // Always create the 'visited' array for the smaller array to save space
   if (n > m)
   {
      // Case 1: 'b[]' is smaller → visited[] will be on b[]
      vector<bool> visited(m, false);

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (a[i] == b[j] && !visited[j])
            {
               I.push_back(a[i]);
               visited[j] = true;
               break;
            }
            if (b[j] > a[i])
               break;
         }
      }
   }
   else if (n < m)
   {
      // Case 2: 'a[]' is smaller → visited[] will be on a[]
      vector<bool> visited(n, false);

      for (int j = 0; j < m; j++)
      {
         for (int i = 0; i < n; i++)
         {
            if (a[i] == b[j] && !visited[i])
            {
               I.push_back(b[j]);
               visited[i] = true;
               break;
            }
            if (a[i] > b[j])
               break;
         }
      }
   }

   return I;
}

int main()
{

   int n = 8, m = 7;
   int a[] = {1, 2, 2, 3, 3, 4, 5, 6};
   int b[] = {2, 3, 3, 5, 6, 6, 7};

   vector<int> intersection = intersectionOf2SortedArrays(a, b, n, m);
   cout << "Intersection of a[] and b[] is: ";

   for (int i : intersection)
      cout << i << " ";

   // ------------------------------------------

   int n1 = 5, m1 = 9;
   int a1[] = {2, 3, 3, 3, 8};
   int b1[] = {1, 1, 2, 2, 3, 3, 4, 4, 9};

   intersection = intersectionOf2SortedArrays(a1, b1, n1, m1);
   cout << "\n \n Intersection of a[] and b[] is: ";

   for (int i : intersection)
      cout << i << " ";

   // Output: Intersection of a[] and b[] is: 2 3 3
   return 0;
}