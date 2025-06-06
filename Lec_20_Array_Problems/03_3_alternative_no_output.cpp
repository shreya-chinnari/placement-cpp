#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
The reason your code isn't showing any output is because of this major bug:

❗ Problem:

You're doing:
   arr3[k] = arr1[i];

But arr3 is empty, so accessing arr3[k] causes undefined behavior (it doesn't crash, but nothing is stored or shown).
You should use push_back() to dynamically add elements.
*/
void merge(vector<int> &arr1, int n1, vector<int> &arr2, int n2, vector<int> &arr3)

{
   int i = 0, j = 0;
   int k = 0;

   while (i < n1 && j < n2)
   {
      if (arr1[i] < arr2[j])
      {
         arr3[k++] = arr1[i++];
         // i++;
         // k++;
      }
      else if (arr1[i] > arr2[j])
      {
         arr3[k++] = arr2[j++];
         // j++;
         // k++;
      }
   }

   while (i < n1)
   {
      arr3[k++] = arr1[i++];
      // i++;
      // k++;
   }

   while (j < n2)
   {
      arr3[k++] = arr2[j++];
      // j++;
      // k++;
   }
}

int main()
{

   vector<int> arr1 = {1, 3, 5, 7};
   vector<int> arr2 = {2, 4, 6, 8};

   int n1 = arr1.size();
   int n2 = arr2.size();

   vector<int> arr3;

   merge(arr1, n1, arr2, n2, arr3);

   cout << "Merged Array: ";
   for (int num : arr3)
      cout << num << " ";
   cout << endl;

   return 0;
}