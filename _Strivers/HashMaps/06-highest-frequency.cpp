#include <iostream>
#include <map>
using namespace std;

int main()
{

   int n;
   cout << "size: " << endl;
   cin >> n;

   int arr[n];
   map<int, int> mpp;

   cout << "elements: " << endl;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
      mpp[arr[i]]++;
   }

   int maxFreq = 0;
   int maxFreqElement = -1;

   for (auto it : mpp)
   {
      if (it.second > maxFreq)
      {
         maxFreq = it.second;
         maxFreqElement = it.first;
      }
   }

   cout << "max freq element is : " << maxFreqElement << " - with frequency : " << maxFreq;

   return 0;
}