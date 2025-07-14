// For counting INTEGERS
// unordered_map

#include <iostream>
#include <unordered_map> // required for std::map
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

   // changed to unordered_map
   unordered_map<int, int> mpp;
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

/*
Enter elements :
1
8
1
7
2
< 2 , 1 >
< 7 , 1 >
< 8 , 1 >
< 1 , 2 >
*/
