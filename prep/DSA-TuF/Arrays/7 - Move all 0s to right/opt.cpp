#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeros(int n, vector<int> a)
{
   int j = -1; // index of first zero

   // find the first zero in the array
   for (int i = 0; i < n; i++)
   {
      if (a[i] == 0)
      {
         j = i;
         break;
      }
   }

   // if no zero found, return the original array
   if (j == -1)
      return a;

   // move all non-zero elements to the front
   for (int i = j + 1; i < n; i++)
   {
      if (a[i] != 0)
      {
         swap(a[i], a[j]);
         j++; // increment the index of the first zero
      }
   }
   return a;
}

int main()
{
   vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
   int n = 10;
   vector<int> ans = moveZeros(n, arr);
   for (auto &it : ans)
   {
      cout << it << " ";
   }
   cout << '\n';

   return 0;
}