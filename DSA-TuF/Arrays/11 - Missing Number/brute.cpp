#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> &a, int N)
{
   // outer loop : runs from 1 to N to check which number is missing
   for (int i = 1; i <= N; i++)
   {
      // flag : 0 {element not found} , 1 {element found}
      int flag = 0;

      // inner loop : runs through the array to check if the number i is present
      // it will have "n-1" elements because one number is missing
      for (int j = 0; j < N - 1; j++)
      {
         // elemenrt found
         if (a[j] == i)
         {
            flag = 1;
            break; // no need to check further, we found the element
         }
      }

      // elemtnt not found
      if (flag == 0)
      {
         return i; // return the missing number
      }
   }

   return -1; // if no number is missing, return -1
}

int main()
{
   int N = 5;
   vector<int> a = {1, 2, 4, 5};
   int ans = missingNumber(a, N);
   cout << "The missing number is: " << ans << endl;
   return 0;
}
