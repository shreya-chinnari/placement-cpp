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

// void merge(vector<int> &arr1, int n1, vector<int> &arr2, int n2, vector<int> &arr3)
// ❌ ERROR: Correct function definition to be able to print without using dynamic pushback ❌
void merge(int arr1[], int n1, int arr2[], int n2, int arr3[])

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

   int arr1[] = {1, 3, 5, 7};
   int arr2[] = {2, 4, 6, 8};

   int n1 = sizeof(arr1) / sizeof(arr1[0]);
   int n2 = sizeof(arr2) / sizeof(arr2[0]); // arr[0] is the first element, so sizeof(arr2[0]) gives the size of one element

   // int arr3[];
   // int arr3[] = {0}; // ❌ ERROR: Because arr3[] doesn't have enough space allocated result is coming :   1 2 3 3 3 3 5 7 ❌
   // int arr3[n1 + n2]; // ✅ FIX: Declare arr3 with enough space to hold all elements from arr1 and arr2
   /*
   ❌ ERROR:
   expression must have a constant value
   the value of variable "n1" (declared at line 62) cannot be used as a constant
   ❌
   */
   int arr3[100]; // ✅ FIX: Declare arr with enough space to hold all elements from arr1 and arr2

   merge(arr1, n1, arr2, n2, arr3);

   cout << "Merged Array: ";
   for (int i = 0; i < n1 + n2; i++)
      cout << arr3[i] << " ";

   return 0;
}

// Merged Array: 1 2 3 4 5 6 7 8