#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &v)
{
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
   cout << endl;
}

// 1. store the first k elements in a temporary array
// 2. shift the remaining elements to the left by k positions
// 3. copy the elements from the temporary array to the end of the original array
// Time Complexity: O(n)
// Space Complexity: O(k) because of the temporary array

void rotateByKPlaceLeft(vector<int> &v)
{
   int temp[k];
   int n = v.size();
   int k = k % n; // Handle cases where k >= n

   // Store the first k elements in temp
   for (int i = 0; i < k; i++)
   {
      temp[i] = v[i];
   }

   // Shift the remaining (n-k) elements to the left by k positions
   for (int i = k; i < n; i++)
   {
      v[i - k] = v[i];
   }

   // Copy the elements from temp to the end of the original array
   for (int i = n - k; i < n; i++)
   {
      v[i] = temp[i - (n - k)];
   }

   v = temp; // Update the original array with the rotated elements
}

void rotateByKPlaceRight(vector<int> &v)
{
}

int main()
{

   cout << "Left Rotate by 1 place:\n";
   vector<int> v1 = {1, 2, 3, 4, 5};
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   rotateByKPlaceLeft(v1);
   printArray(v1);
   cout << "Right Rotate by 1 place:\n";
   vector<int> v2 = {1, 2, 3, 4, 5};
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   rotateByKPlaceRight(v2);
   printArray(v2);
   return 0;
}