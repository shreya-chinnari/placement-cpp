#include <bits/stdc++.h>
using namespace std;

// 2 pointer approach

// traverse i,
// check if

// 1. if(a[i] <= b[j])
//       > check if a[i] == b[j]   { I.pushback(a[i]) , i++ , j++ }
//       > check if a[i] < b[j]    { i++ }
// 2. if(a[i] > b[j])              { j++ }

vector<int> intersectionOf2SortedArrays(int a[], int b[], int n, int m)
{
   int i = 0, j = 0;

   vector<int> I;

   // traverse both arrays while there are elements in both
   while (i < n && j < m)
   {

      // case 1: if a[i] <= b[j]

      if (a[i] <= b[j])
      {
         // if elements match in "a[]" and "b[]"
         if (a[i] == b[j])
         {
            I.push_back(a[i]);
            i++; // move to next element in a[]
            j++; // move to next element in b[]
         }
         // if a[i] < b[j], move to next element in a[]
         else if (a[i] < b[j])
         {
            i++; // move to next element in a[]
         }
      }
      // case 2: if a[i] > b[j]
      else if (a[i] > b[j])
      {
         j++; // move to next element in b[]
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

   // Output: Intersection of a[] and b[] is: 2 3 3 5 6
   return 0;
}