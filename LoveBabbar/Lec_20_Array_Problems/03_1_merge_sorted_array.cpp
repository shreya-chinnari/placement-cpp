#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
The reason your code isn't showing any output is because of this major bug:

❗ Problem:
You're doing:

   arr3[k] = arr1[i];

But arr3 is empty, so accessing arr3[k] causes undefined behavior (it doesn't crash, but nothing is stored or shown). You should use push_back() to dynamically add elements.
*/

// vector<int> merge(vector<int> arr1[], int n1, vector<int> arr2[], int n2, vector<int> arr3[])
// ❌ ERROR: Correct function definition: use vector<int>& instead of vector<int>[] ❌
// ❌ ERROR: Also arr3 should be passed by reference so it can be modified inside the function ❌
// ❌ ERROR: Use void return type instead of vector<int> ❌
void merge(vector<int> &arr1, int n1, vector<int> &arr2, int n2, vector<int> &arr3)

{
   int i = 0, j = 0; // starting element se compare karenge
   int k = 0;        // merged array ka index, 0th index se start hoga

   while (i < n1 && j < n2)
   {
      if (arr1[i] < arr2[j])
      {
         arr3[k] = arr1[i];
         i++;
         k++;
      }
      else if (arr1[i] > arr2[j])
      {
         arr3[k] = arr2[j];
         j++;
         k++;
      }
   }

   // agar arr1 ke elements bache hain, copy them
   while (i < n1)
   {
      arr3[k] = arr1[i];
      i++;
      k++;
   }
   // agar arr2 ke elements bache hain, copy them
   while (j < n2)
   {
      arr3[k] = arr2[j];
      j++;
      k++;
   }
   // return arr3;
   // ❌ ERROR: No need to return arr3, as it is passed by reference ❌
}

int main()
{
   // vector<int> arr1[] = {1, 3, 5, 7};
   // vector<int> arr2[] = {2, 4, 6, 8};
   // ❌ ERROR: You were declaring array of vectors. ❌
   // ✅ FIX: Declare simple vectors

   vector<int> arr1 = {1, 3, 5, 7};
   vector<int> arr2 = {2, 4, 6, 8};

   // vector<int> n1 = sizeof(arr1) / sizeof(arr1[0]);
   // vector<int> n2 = sizeof(arr2) / sizeof(arr2[0]);
   // ❌ ERROR: You used vector<int> to store integer size ❌
   // ✅ FIX: Use int type
   int n1 = arr1.size();
   int n2 = arr2.size();

   // int arr3[] = {0};
   vector<int> arr3; // empty vector to store merged result

   merge(arr1, n1, arr2, n2, arr3);

   // Print merged vector
   cout << "Merged Array: ";
   for (int num : arr3)
      cout << num << " ";
   cout << endl;

   return 0;
}