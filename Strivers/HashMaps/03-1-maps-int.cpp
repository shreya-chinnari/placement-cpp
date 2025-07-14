// For counting INTEGERS

#include <iostream>
#include <map> // required for std::map
using namespace std;

int main()
{
   int n;
   cout << "Size of Arr: " << endl;
   cin >> n;

   int arr[n];
   cout << "Enter elements : " << endl;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   map<int, int> mpp;
   for (int i = 0; i < n; i++)
   {
      mpp[arr[i]]++;
   }

   // to show the working :

   for (auto it : mpp)
   {
      cout << "< " << it.first << " , " << it.second << " >" << endl;
   }

   int q;
   cout << "Number of queries: " << endl;
   cin >> q;

   while (q--)
   {
      int number;
      cout << "Number to query : ";
      cin >> number;
      cout << "   Frequency : " << mpp[number] << endl;
   }
   return 0;
}

/* EXAMPLE :

arr = [4, 2, 4, 3, 2, 2]

mpp[4]++;  // map = {4: 1}
mpp[2]++;  // map = {2: 1, 4: 1}
mpp[4]++;  // map = {2: 1, 4: 2}
mpp[3]++;  // map = {2: 1, 3: 1, 4: 2}
mpp[2]++;  // map = {2: 2, 3: 1, 4: 2}
mpp[2]++;  // map = {2: 3, 3: 1, 4: 2}

Key : Frequency
2   : 3
3   : 1
4   : 2

*/

/*
Enter elements :
1
8
1
7
2
< 1 , 2 >
< 2 , 1 >
< 7 , 1 >
< 8 , 1 >
*/