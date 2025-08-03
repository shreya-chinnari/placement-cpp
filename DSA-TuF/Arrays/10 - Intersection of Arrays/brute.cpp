#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOf2SortedArrays(int a[], int b[], int n, int m)
{

   // resultant array of intersection elements
   vector<int> I;

   // "elements visited" array on array "b[]" to keep track of elements already added to the intersection
   vector<bool> visited(m, false);

   // traverse both arrays while there are elements in both
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         // if elements match in "a[]" and "b[]", AND the element in "b[]" has not been visited yet
         if (a[i] == b[j] && !visited[j])
         {
            I.push_back(a[i]);
            visited[j] = true; // mark this element as visited
            break;             // no need to check further in "b[]" for this element
         }

         // stop checking "b[]" if the current element in "b[]" is greater than the current element in "a[]"
         if (b[j] > a[i])
            break;
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