#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int a[], int b[], int n, int m)
{

   vector<int> Union;

   map<int, int> freq;

   // Insert elements of first array into the map
   for (int i = 0; i < n; i++)
   {
      freq[a[i]]++;
   }

   // Insert elements of second array into the map
   for (int i = 0; i < m; i++)
   {
      freq[b[i]]++;
   }

   // Collect unique elements from the map into the Union vector
   for (auto &it : freq)
   {
      Union.push_back(it.first);
   }

   return Union;
}

int main()
{

   int a[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 7};
   int b[] = {2, 3, 4, 4, 5, 11, 11};
   int n = sizeof(a) / sizeof(a[0]);
   int m = sizeof(b) / sizeof(b[0]);

   vector<int> result = findUnion(a, b, n, m);

   for (int i : result)
   {
      cout << i << " ";
   }
   cout << endl;

   return 0;
}