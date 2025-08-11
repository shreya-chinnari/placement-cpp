#include <bits/stdc++.h>
using namespace std;

// 2 pointer approach

vector<int> FindUnion(int a[], int b[], int n, int m)
{

   vector<int> U;
   int i = 0, j = 0;

   // traverse both arrays while there are elements in both
   while (i < n && j < m)
   {
      // two base cases:
      // 1. if a[i] <= b[j]
      // 2. if a[i] > b[j]

      // 1. if a[i] <= b[j]

      if (a[i] <= b[j])
      {
         // check if Union array is empty OR last element of Union array != a[i] {new element}
         if (U.size() == 0 || U.back() != a[i])
         {
            U.push_back(a[i]);
         }
         // otherwise increment i as it will be a duplicate
         i++;
      }

      // 2. if b[j] < a[i]

      else
      {
         // check if Union array is empty OR last element of Union array != b[j] {new element}
         if (U.size() == 0 || U.back() != b[j])
         {
            U.push_back(b[j]);
         }
         // otherwise increment j as it will be a duplicate
         j++;
      }
   }

   // if we reach here, it means one of the arrays has been completely traversed
   // and the other array still has elements left
   // so we need to add the remaining elements of the other array to the Union array
   while (i < n)
   {
      if (U.size() == 0 || U.back() != a[i])
      {
         U.push_back(a[i]);
      }
      i++;
   }

   while (j < m)
   {
      if (U.size() == 0 || U.back() != b[j])
      {
         U.push_back(b[j]);
      }
      j++;
   }

   return U;
}

int main()

{
   int n = 10, m = 7;
   int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int arr2[] = {2, 3, 4, 4, 5, 11, 12};
   vector<int> Union = FindUnion(arr1, arr2, n, m);
   cout << "Union of arr1 and arr2 is  " << endl;
   for (auto &val : Union)
      cout << val << " ";
   return 0;
}